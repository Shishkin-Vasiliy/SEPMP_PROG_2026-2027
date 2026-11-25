#pragma once

#include <iostream>

class Vector2f
{
public:
    float x;
    float y;

    Vector2f(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2f operator+(const Vector2f &other) const
    {
        return Vector2f(x + other.x, y + other.y);
    }

    Vector2f operator-(const Vector2f &other) const
    {
        return Vector2f(x - other.x, y - other.y);
    }

    float operator*(const Vector2f &other) const
    {
        return x * other.x + y * other.y;
    }

    Vector2f operator*(float k) const
    {
        return Vector2f(x * k, y * k);
    }

    Vector2f operator/(float k) const
    {
        return Vector2f(x / k, y / k);
    }

    Vector2f operator-() const
    {
        return Vector2f(-x, -y);
    }

    Vector2f operator+() const
    {
        return Vector2f(x, y);
    }

    bool operator==(const Vector2f &other) const
    {
        return x == other.x && y == other.y;
    }

    bool operator!=(const Vector2f &other) const
    {
        return !(*this == other);
    }

    Vector2f &operator+=(const Vector2f &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }

    Vector2f &operator-=(const Vector2f &other)
    {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    Vector2f &operator*=(float k)
    {
        x *= k;
        y *= k;
        return *this;
    }

    Vector2f &operator/=(float k)
    {
        x /= k;
        y /= k;
        return *this;
    }

    friend std::ostream &operator<<(std::ostream &os, const Vector2f &v);
    friend std::istream &operator>>(std::istream &is, Vector2f &v);
};

inline Vector2f operator*(float k, const Vector2f &v)
{
    return Vector2f(v.x * k, v.y * k);
}

inline std::ostream &operator<<(std::ostream &os, const Vector2f &v)
{
    os << "(" << v.x << ", " << v.y << ")";
    return os;
}

inline std::istream &operator>>(std::istream &is, Vector2f &v)
{
    is >> v.x >> v.y;
    return is;
}