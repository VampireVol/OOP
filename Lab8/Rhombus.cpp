#include "Rhombus.h"

Rhombus::Rhombus (double a, double alpha)
    : Parallelogram (a, a, alpha)
{

}

QString Rhombus::toString ()
{
    return QString ("Rhombus: a: %1 b: %2 alpha: %3")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_alpha);
}
