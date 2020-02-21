#include "Square.h"

Square::Square (double a)
    : Parallelogram (a, a, 90), Rectangle (a, a), Rhombus(a, 90)
{
}

QString Square::toString ()
{
    return QString ("Square: a: %1")
            .arg (_edge[0]);
}
