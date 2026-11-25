#ifndef INTEGER_HPP
#define INTEGER_HPP

#include <string>
#include <vector>
#include <iostream>

class Integer
{
public:
    Integer();
    Integer(const std::string &str);

    Integer operator+(const Integer &n) const;
    Integer &operator+=(const Integer &n);
    Integer operator*(const Integer &n) const;
    bool isEven() const;

    friend std::ostream &operator<<(std::ostream &os, const Integer &n);

private:
    std::vector<int> digits;
};

#endif