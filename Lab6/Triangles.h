#ifndef TRIANGLES_H
#define TRIANGLES_H


class Triangle
{
public:
    Triangle ();
    virtual ~Triangle ();
};


class IsoscelesTriangle : public Triangle
{
public:
    IsoscelesTriangle ();
    virtual ~IsoscelesTriangle ();
};

class EquilateralTriangle : public Triangle
{
public:
    EquilateralTriangle ();
    virtual ~EquilateralTriangle ();
};


#endif // TRIANGLES_H
