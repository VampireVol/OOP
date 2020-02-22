#include "Rhombus.h"

Rhombus::Rhombus (const double &a, const double &alpha)
    : Parallelogram (a, a, alpha)
{

}

QString Rhombus::toString ()
{
    return QString ("Rhombus: a: %1 alpha: %3")
            .arg (_edge[0])
            .arg (_angle[0]);
}
