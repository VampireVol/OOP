#include "Rhombus.h"

Rhombus::Rhombus (double a, double alpha)
    : Parallelogram (a, a, alpha)
{

}

double Rhombus::area ()
{
    return _a * _a * cos (_alpha * PI / 180);
}

double Rhombus::perimetr ()
{
    return 4 * _a;
}

QString Rhombus::toString ()
{
    return QString ("Rhombus: a: %1 b: %2 alpha: %3")
            .arg (this->_a)
            .arg (this->_b)
            .arg (this->_alpha);
}

//ostream& operator<< (ostream &out, const Rhombus *obj)
//{
//    out << "Rhombus: "
//        << "a: "    << obj->_a
//        << "b: "    << obj->_b
//        << "alpha: "<< obj->_alpha;
//    return out;
//}
