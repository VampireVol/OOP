#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include "Rhombus.h"

class Square : public Rectangle, public Rhombus
{
public:
    Square(double a);
    QString toString () override;
};

#endif // SQUARE_H
