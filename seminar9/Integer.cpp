#include "Integer.hpp"
#include <algorithm>

Integer::Integer()
{
    digits.push_back(0);
}

Integer::Integer(const std::string &str)
{
    for (size_t i = 0; i < str.size(); i++)
        digits.push_back(str[str.size() - 1 - i] - '0');
}

Integer Integer::operator+(const Integer &n) const
{
    Integer res;
    res.digits.clear();

    size_t max_size = std::max(digits.size(), n.digits.size());
    int carry = 0;

    for (size_t i = 0; i < max_size; i++)
    {
        int a = (i < digits.size()) ? digits[i] : 0;
        int b = (i < n.digits.size()) ? n.digits[i] : 0;
        int sum = a + b + carry;

        res.digits.push_back(sum % 10);
        carry = sum / 10;
    }
    if (carry)
        res.digits.push_back(carry);

    return res;
}

Integer &Integer::operator+=(const Integer &n)
{
    *this = *this + n;
    return *this;
}

Integer Integer::operator*(const Integer &n) const
{
    Integer res;
    res.digits.assign(digits.size() + n.digits.size(), 0);

    for (size_t i = 0; i < digits.size(); i++)
    {
        int carry = 0;
        for (size_t j = 0; j < n.digits.size(); j++)
        {
            int prod = digits[i] * n.digits[j] + res.digits[i + j] + carry;
            res.digits[i + j] = prod % 10;
            carry = prod / 10;
        }
        res.digits[i + n.digits.size()] += carry;
    }

    while (res.digits.size() > 1 && res.digits.back() == 0)
        res.digits.pop_back();

    return res;
}

bool Integer::isEven() const
{
    return (digits[0] % 2) == 0;
}

std::ostream &operator<<(std::ostream &os, const Integer &n)
{
    for (size_t i = 0; i < n.digits.size(); i++)
        os << n.digits[n.digits.size() - 1 - i];
    return os;
}