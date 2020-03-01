#include "Ellipse.h"

Ellipse::Ellipse (const QPointF &pivot, const double &a, const double &b)
    : Sample (pivot, a, b)
{

}

bool Ellipse::checkPoint (const double &x, const double &y)
{
    if ((x - _pivot.x ()) * (x - _pivot.x ()) / (_a * _a) + (y - _pivot.y ()) * (y - _pivot.y ()) / (_b * _b) <= 1)
        return true;
    else
        return false;
}
