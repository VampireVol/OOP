#include "Polynom.h"

Polynom::Polynom ()
    : _a (0)
    , _b (0)
    , _c (0)
{

}

Polynom::Polynom (number a, number b, number c)
    : _a (a)
    , _b (b)
    , _c (c)
{}

int Polynom::roots (number *x)
{
    number D = _b * _b - 4 * _a * _c;

    if (D > 0) {
        x[0] = (-_b + sqrt (D)) / (2 * _a);
        x[1] = (-_b - sqrt (D)) / (2 * _a);
        return 2;
    } else if (D == 0) {
        x[0] = -_b / (2 * _a);
        return 1;
    }
    return 0;
}

ostream &operator<< (ostream &os, Polynom &p)
{
    return os << p._a << "x^2+" << p._b << "x+" << p._c;
}
