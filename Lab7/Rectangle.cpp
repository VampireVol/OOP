#include "Rectangle.h"

Rectangle::Rectangle (const QPointF &pivot, const double &a, const double &b)
    : Sample (pivot, a, b)
{

}

bool Rectangle::checkPoint (const double &x, const double &y)
{
    if (x <= _a / 2 + _pivot.x () && x >= -_a / 2 + _pivot.x () &&
        y <= _b / 2 + _pivot.y () && y >= -_b / 2 + _pivot.y ())
        return true;
    else
        return false;
}
