#include "Sample.h"

SampleData::SampleData (SampleData::Type type, double x, double y/*, double a, double b, double c*/)
    : _type (type)
    , _x (x)
    , _y (y)
//    , _a (a)
//    , _b (b)
//    , _c (c)
{

}

Sample::Sample (SampleData &data)
    : _pivot (new QPointF (data._x, data._y))
    , _type (data._type)
{

}

Sample::~Sample()
{
    if (_pivot)
        delete _pivot;
}
