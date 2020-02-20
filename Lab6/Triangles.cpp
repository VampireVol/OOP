#include "Triangles.h"

Triangle::Triangle (double a, double b, double c)
    : _a (a), _b (b), _c (c)
{

}

Triangle::~Triangle ()
{

}

QPoint Triangle::calcLastPoint ()
{
    double x = (_a * _a + _b * _b - _c * _c) / (2 * _a);
    int x0 = static_cast<int> (_a - x);
    int y0 = static_cast<int> (sqrt (_b * _b - x * x));
    return QPoint (x0, -y0);
}

IsoscelesTriangle::IsoscelesTriangle(double a, double b)
    : Triangle (a, b, b)
{

}

IsoscelesTriangle::~IsoscelesTriangle ()
{

}

EquilateralTriangle::EquilateralTriangle(double a)
    : IsoscelesTriangle (a, a)
{

}

EquilateralTriangle::~EquilateralTriangle ()
{

}
