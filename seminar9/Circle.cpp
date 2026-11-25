#include "Point.hpp"
#include "Circle.hpp"
#include <cmath>

const float PI = 3.14159265358979323846f;

Circle::Circle(const Point &center, float radius) : center(center)
{
    setRadius(radius);
}

Circle::Circle() : center(0, 0), radius(1) {}

Circle::Circle(const Circle &circle) : center(circle.center), radius(circle.radius) {}

Point Circle::getCenter() const
{
    return center;
}

void Circle::setCenter(const Point &c)
{
    center = c;
}

float Circle::getRadius() const
{
    return radius;
}

void Circle::setRadius(float r)
{
    if (r < 0)
        radius = 0;
    else
        radius = r;
}

float Circle::area() const
{
    return PI * radius * radius;
}

float Circle::distance(const Point &p) const
{
    float dx = p.getX() - center.getX();
    float dy = p.getY() - center.getY();
    float dist_to_center = std::sqrt(dx * dx + dy * dy);

    return std::fabs(dist_to_center - radius);
}

bool Circle::isColliding(const Circle &c) const
{
    float dx = c.center.getX() - center.getX();
    float dy = c.center.getY() - center.getY();
    float dist_between_centers = std::sqrt(dx * dx + dy * dy);

    return dist_between_centers <= (radius + c.radius);
}

void Circle::move(const Point &p)
{
    center = center + p;
}