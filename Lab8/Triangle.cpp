#include "Triangle.h"

Triangle::Triangle (double a, double b, double angle)
    : _a (a)
    , _b (b)
    , _alpha (angle)
{

}

double Triangle::area ()
{
    return 0.5 * _a * _b * cos (_alpha * PI / 180);
}

double Triangle::perimetr ()
{
    return sqrt (_a * _a + _b * _b - 2 * _a * _b * cos (_alpha * PI / 180)) + _a + _b;
}

QString Triangle::toString ()
{
    return QString ("Triangle: a: %1 b: %2 alpha: %3")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_alpha);
}
