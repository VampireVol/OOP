#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle (const double &a, const double &b, const double &angle);
    QString toString () override;
};

#endif // TRIANGLE_H
