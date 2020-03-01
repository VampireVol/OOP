#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"


class Square : public Rectangle
{
public:
    Square (const QPointF &pivot, const double &a);
};

#endif // SQUARE_H
