#include "Point.hpp"

class Circle
{
public:
    Circle(const Point &center, float radius);
    Circle();                       
    Circle(const Circle &circle);

    Point getCenter() const;
    void setCenter(const Point &center);
    float getRadius() const;
    void setRadius(float radius);  

    float area() const;
    float distance(const Point &p) const;
    bool isColliding(const Circle &c) const;
    void move(const Point &p);

private:
    Point center;
    float radius;
};