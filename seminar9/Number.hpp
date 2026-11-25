#pragma once

#include <iostream>
#include <iomanip>

class Number 
{
private:
    static const int base = 100;

    char* data;
    std::size_t size;
    std::size_t capacity;

public:

    Number(int a) 
    {
        int temp = a;
        capacity = 0;
        while (temp != 0) 
        {
            temp /= base;
            capacity += 1;
        }

        if (capacity == 0) 
            capacity = 1;

        data = new char[capacity];

        for (int i = 0; i < capacity; ++i) 
        {
            data[i] = a % base;
            a /= base;
        }

        size = capacity;
    }

    bool operator==(const Number& other) const 
    {
        if (size != other.size)
            return false;

        for (std::size_t i = 0; i < size; ++i) 
        {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    bool operator!=(const Number& other) const 
    {
        return ! (*this == other);
    }


    ~Number() 
    {
        delete [] data;
    }


    friend std::ostream& operator<<(std::ostream& stream, const Number& num);
};

std::ostream& operator<<(std::ostream& stream, const Number& num)
{
    // Печатаем самый большой разряд
    stream << static_cast<int>(num.data[num.size - 1]);

    // Печатаем остальные разряды с заполнением нулями до 2-х цифр
    // setfill и setw используются для того, чтобы замостить ноликом, элемент будет меньше чем 10.
    for (std::size_t i = 0; i < num.size - 1; ++i)
        stream << std::setfill('0') << std::setw(2) << static_cast<int>(num.data[num.size - 2 - i]);

    return stream;
}