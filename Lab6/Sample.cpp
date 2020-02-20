#include "Sample.h"
#include <QDebug>

SampleData::SampleData (SampleData::Type type, int x, int y, double a, double b, double c)
    : _type (type)
    , _x (x)
    , _y (y)
    , _a (a)
    , _b (b)
    , _c (c)
{

}

Sample::Sample (SampleData &data)
    : _pivot (new QPoint (data._x, data._y))
    , _type (data._type)
{
    if (SampleData::Triangle == _type)
    {
        _triangle = new Triangle (data._a, data._b, data._c);
    }
    else if (SampleData::IsoscelesTriangle == _type)
    {
        _triangle = new IsoscelesTriangle (data._a, data._b);
    }
    else if (SampleData::EquilateralTriangle == _type)
    {
        _triangle = new EquilateralTriangle (data._a);
    }
}

Sample::~Sample ()
{
    if (_pivot)
        delete _pivot;
    if (_triangle)
        delete _triangle;
}

QPolygon Sample::getPolygon ()
{
    QPolygon polygon;
    QPoint b = *_pivot;
    b += QPoint (static_cast<int> (_triangle->_a), 0);
    QPoint c = *_pivot;
    c += _triangle->calcLastPoint ();
    polygon << *_pivot << b << c;

    return polygon;
}
