#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle (double a, double b, double angle);
    QString toString () override;
};

#endif // TRIANGLE_H
