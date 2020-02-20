#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Parallelogram.h"

class Rectangle : virtual public Parallelogram
{
public:
    Rectangle (double a, double b);
    QString toString () override;
};

#endif // RECTANGLE_H
