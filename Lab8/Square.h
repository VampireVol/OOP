#ifndef SQUARE_H
#define SQUARE_H
#include "Rectangle.h"
#include "Rhombus.h"

class Square : public Rectangle, public Rhombus
{
public:
    Square(double a);
    double area() override;
    double perimetr() override;
    QString toString () override;
//    friend ostream& operator<< (ostream &out, const Square *obj);
};

#endif // SQUARE_H
