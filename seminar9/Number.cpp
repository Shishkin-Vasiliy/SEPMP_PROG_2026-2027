#include "Number.hpp"
#include <algorithm>

void Number::FreeDigits()
{
    delete[] digits;
    digits = nullptr;
    size = 0;
}

Number::Number()
{
    size = 1;
    digits = new char[1];
    digits[0] = 0;
}

Number::Number(const Number &n)
{
    size = n.size;
    digits = new char[size];
    for (size_t i = 0; i < size; i++)
        digits[i] = n.digits[i];
}

Number::Number(const std::string &str)
{
    size = str.size();
    digits = new char[size];

    for (size_t i = 0; i < size; i++)
        digits[i] = str[str.size() - 1 - i] - '0';
}

Number &Number::operator=(const Number &n)
{
    if (this == &n)
        return *this;

    FreeDigits();
    size = n.size;
    digits = new char[size];
    for (size_t i = 0; i < size; i++)
        digits[i] = n.digits[i];

    return *this;
}

Number::~Number()
{
    FreeDigits();
}

Number Number::operator+(const Number &n) const
{
    size_t max_size = std::max(size, n.size);
    char *result = new char[max_size + 1];
    int carry = 0;

    for (size_t i = 0; i < max_size; i++)
    {
        int a = (i < size) ? digits[i] : 0;
        int b = (i < n.size) ? n.digits[i] : 0;
        int sum = a + b + carry;

        result[i] = sum % 10;
        carry = sum / 10;
    }

    size_t result_size = max_size;
    if (carry)
    {
        result[max_size] = carry;
        result_size = max_size + 1;
    }

    Number res;
    res.FreeDigits();
    res.size = result_size;
    res.digits = new char[result_size];
    for (size_t i = 0; i < result_size; i++)
        res.digits[i] = result[i];

    delete[] result;
    return res;
}

Number &Number::operator+=(const Number &n)
{
    *this = *this + n;
    return *this;
}

Number Number::operator*(const Number &n) const
{
    size_t result_size = size + n.size;
    char *result = new char[result_size];
    for (size_t i = 0; i < result_size; i++)
        result[i] = 0;

    for (size_t i = 0; i < size; i++)
    {
        int carry = 0;
        for (size_t j = 0; j < n.size; j++)
        {
            int prod = digits[i] * n.digits[j] + result[i + j] + carry;
            result[i + j] = prod % 10;
            carry = prod / 10;
        }
        result[i + n.size] += carry;
    }

    while (result_size > 1 && result[result_size - 1] == 0)
        result_size--;

    Number res;
    res.FreeDigits();
    res.size = result_size;
    res.digits = new char[result_size];
    for (size_t i = 0; i < result_size; i++)
        res.digits[i] = result[i];

    delete[] result;
    return res;
}

bool Number::isEven() const
{
    return (digits[0] % 2) == 0;
}

std::ostream &operator<<(std::ostream &os, const Number &n)
{
    for (size_t i = 0; i < n.size; i++)
        os << (int)n.digits[n.size - 1 - i];
    return os;
}