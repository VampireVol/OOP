#include "Quadrangle.h"

Quadrangle::Quadrangle (double a, double b, double c,
                        double alpha, double beta)
{
    _edge.append (a);
    _edge.append (b);
    _edge.append (c);
    _angle.append (alpha);
    _angle.append (beta);
    calcInternal ();
}

QString Quadrangle::toString ()
{
    return QString ("Quadrangle: a: %1 b: %2 c: %3 alpha: %4 beta: %5")
            .arg (_edge[0])
            .arg (_edge[1])
            .arg (_edge[2])
            .arg (_angle[0])
            .arg (_angle[1]);
}
