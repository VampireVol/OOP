#include "Sample.h"

SampleData::SampleData (const SampleData::Type &type, const QPointF &pivot, const double &a, const double &b)
    : _type (type), _pivot (pivot), _a (a), _b (b)
{

}

Sample::Sample (const QPointF &pivot, const double &a, const double &b)
    : _pivot (pivot)
    , _a (a)
    , _b (b)
{

}

Sample::~Sample ()
{

}
