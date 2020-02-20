#include "Square.h"

Square::Square (double a)
    : Parallelogram (a, a, 90), Rectangle (a, a), Rhombus(a, 90)
{

}

double Square::area ()
{
    return _a * _a;
}

double Square::perimetr ()
{
    return 4 * _a;
}

QString Square::toString ()
{
    return QString ("Square: a: %1")
            .arg (this->_a);
}
