#include "Parallelogram.h"

Parallelogram::Parallelogram (double a, double b, double alpha)
    : Quadrangle (a, b, a, b, alpha, alpha)
{

}

QString Parallelogram::toString ()
{
    return QString ("Parallelogram: a: %1 b: %2 alpha: %3")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_alpha);
}
