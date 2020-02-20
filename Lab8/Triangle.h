#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Polygon.h"

class Triangle : public Polygon
{
public:
    Triangle (double a, double b, double angle);
    double area () override;
    double perimetr () override;
    QString toString () override;
private:
    double _a;
    double _b;
    double _alpha;
};

#endif // TRIANGLE_H
