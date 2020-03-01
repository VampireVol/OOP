#ifndef CIRCLE_H
#define CIRCLE_H
#include "Ellipse.h"

class Circle : public Ellipse
{
public:
    Circle (const QPointF &pivot, const double &a);
};

#endif // CIRCLE_H
