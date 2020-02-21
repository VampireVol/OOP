#ifndef POLYGON_H
#define POLYGON_H
#include <math.h>
#include <iostream>
#include <QList>
#include <QString>
#define PI 3.14159265

using namespace std;

class Polygon
{
public:
    Polygon ();
    Polygon (QList<double> &edge, QList<double> &angle);
    virtual ~Polygon ();

    double area ();
    double perimetr ();
    virtual QString toString ();
protected:
    void calcInternal ();
    QList<double> _edge;
    QList<double> _angle;
    QList<double> _iEdge;
    QList<double> _iAngle;
};

#endif // POLYGON_H
