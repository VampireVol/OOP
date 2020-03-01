#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Sample.h"

class Rectangle : public Sample
{
public:
    Rectangle (const QPointF &pivot, const double &a, const double &b);
    bool checkPoint (const double &x, const double &y) override;
};

#endif // RECTANGLE_H
