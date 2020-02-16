#include "Parallelogram.h"

Parallelogram::Parallelogram (double a, double b, double alpha)
    : Quadrangle (a, b, a, b, alpha, alpha)
{

}

double Parallelogram::area ()
{
    return _a * _b * cos (_alpha * PI / 180);
}

double Parallelogram::perimetr ()
{
    return 2 * (_a + _b);
}

QString Parallelogram::toString ()
{
    return QString ("Parallelogram: a: %1 b: %2 alpha: %3")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_alpha);
}
