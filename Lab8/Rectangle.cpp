#include "Rectangle.h"

Rectangle::Rectangle (double a, double b)
    : Parallelogram (a , b, 90)
{

}

QString Rectangle::toString ()
{
    return QString ("Rectangle: a: %1 b: %2")
            .arg (_edge[0])
            .arg (_edge[1]);
}
