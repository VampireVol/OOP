#include "Triangle.h"

Triangle::Triangle (const double &a, const double &b, const double &angle)
{
    _edge.append (a);
    _edge.append (b);
    _angle.append (angle);
    calcInternal ();
}

QString Triangle::toString ()
{
    return QString ("Triangle: a: %1 b: %2 alpha: %3")
            .arg (_edge[0])
            .arg (_edge[1])
            .arg (_angle[0]);
}
