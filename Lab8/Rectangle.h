#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Parallelogram.h"

class Rectangle : virtual public Parallelogram
{
public:
    Rectangle (double a, double b);
    double area () override;
    double perimetr () override;
    QString toString () override;
};

#endif // RECTANGLE_H
