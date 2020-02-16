#include "Quadrangle.h"

Quadrangle::Quadrangle (double a, double b,
                        double c, double d,
                        double alpha, double beta)
    : _a (a), _b (b)
    , _c (c), _d (d)
    , _alpha (alpha)
    , _beta (beta)
{

}

double Quadrangle::area ()
{
    return 0.5 * _a * _b * sin (_alpha * PI / 180) + 0.5 * _c * _d * sin (_beta * PI / 180);
}

double Quadrangle::perimetr ()
{
    return _a + _b + _c + _d;
}

QString Quadrangle::toString ()
{
    return QString ("Quadrangle: a: %1 b: %2 c: %3 d: %4 alpha: %5 beta: %6")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_c)
            .arg (this->_d)
            .arg (this->_alpha)
            .arg (this->_beta);
}

//ostream& operator<< (ostream &out, const Quadrangle *obj)
//{
//    out << "Quadrangle: "
//        << "a: "    << obj->_a
//        << "b: "    << obj->_b
//        << "c: "    << obj->_c
//        << "d: "    << obj->_d
//        << "alpha: "<< obj->_alpha
//        << "beta: " << obj->_beta;
//    return out;
//}
