#include <stdio.h>
#include <math.h>

struct Point {
    double x;
    double y;
};

struct Triangle {
    Point a;
    Point b;
    Point c;
};

void print_point(Point p)
{
    printf("(%.2f, %.2f)", p.x, p.y);
}

void print_triangle(Triangle t)
{
    printf("{");
    print_point(t.a);
    printf(", ");
    print_point(t.b);
    printf(", ");
    print_point(t.c);
    printf("}");
}

double distance(Point p1, Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

double get_triangle_perimeter(const Triangle* t)
{
    return distance(t->a, t->b)
         + distance(t->b, t->c)
         + distance(t->c, t->a);
}

Triangle moved_triangle(const Triangle* t, Point d)
{
    Triangle result;
    result.a.x = t->a.x + d.x;
    result.a.y = t->a.y + d.y;
    result.b.x = t->b.x + d.x;
    result.b.y = t->b.y + d.y;
    result.c.x = t->c.x + d.x;
    result.c.y = t->c.y + d.y;
    return result;
}

void move_triangle(Triangle* t, Point d)
{
    t->a.x += d.x;
    t->a.y += d.y;
    t->b.x += d.x;
    t->b.y += d.y;
    t->c.x += d.x;
    t->c.y += d.y;
}
