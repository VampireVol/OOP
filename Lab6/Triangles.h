#ifndef TRIANGLES_H
#define TRIANGLES_H
#include <QPoint>
class Triangle
{
public:
    Triangle (double a, double b, double c);
    virtual ~Triangle ();
    QPoint calcLastPoint ();
    double _a;
    double _b;
    double _c;
};

class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle (double a, double b);
    virtual ~IsoscelesTriangle ();
};

class EquilateralTriangle : public IsoscelesTriangle
{
public:
    EquilateralTriangle (double a);
    virtual ~EquilateralTriangle ();
};


#endif // TRIANGLES_H
