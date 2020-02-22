#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Parallelogram.h"

class Rectangle : virtual public Parallelogram
{
public:
    Rectangle (const double &a, const double &b);
    QString toString () override;
};

#endif // RECTANGLE_H
