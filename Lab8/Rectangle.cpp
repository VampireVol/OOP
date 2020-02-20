#include "Rectangle.h"

Rectangle::Rectangle (double a, double b)
    : Parallelogram (a , b, 90)
{

}

double Rectangle::area ()
{
    return _a * _b;
}

double Rectangle::perimetr ()
{
    return 2 * (_a + _b);
}

QString Rectangle::toString ()
{
    return QString ("Rectangle: a: %1 b: %2")
            .arg (this->_a)
            .arg (this->_b);
}
