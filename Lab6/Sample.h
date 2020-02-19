#ifndef SAMPLE_H
#define SAMPLE_H
#include <QPointF>

struct SampleData
{
    enum Type
    {
        Triangle,
        IsoscelesTriangle,
        EquilateralTriangle
    };

    SampleData (Type type, double x, double y/*, double a, double b, double c*/);

    Type _type {Triangle};
    double _x;
    double _y;
//    double _a;
//    double _b;
//    double _c;
};

class Sample
{
public:
    Sample (SampleData &data);
    ~Sample ();

    QPointF *_pivot;
    SampleData::Type _type {SampleData::Triangle};
};

#endif // SAMPLE_H
