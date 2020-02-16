#ifndef POLYGON_H
#define POLYGON_H
#include <math.h>
#include <iostream>
#include <QString>
#define PI 3.14159265

using namespace std;

class Polygon
{
public:
    Polygon();
    virtual ~Polygon ();

    virtual double area () = 0;
    virtual double perimetr () = 0;
    virtual QString toString () = 0;
};

#endif // POLYGON_H
