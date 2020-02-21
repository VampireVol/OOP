#include "Parallelogram.h"

Parallelogram::Parallelogram (double a, double b, double alpha)
    : Quadrangle (a, b, a, alpha, 180 - alpha)
{

}

QString Parallelogram::toString ()
{
    return QString ("Parallelogram: a: %1 b: %2 alpha: %3")
            .arg (_edge[0])
            .arg (_edge[1])
            .arg (_angle[0]);
}
