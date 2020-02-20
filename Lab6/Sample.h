#ifndef SAMPLE_H
#define SAMPLE_H
#include <QPointF>
#include <QPolygon>
#include "Triangles.h"

struct SampleData
{
    enum Type
    {
        Triangle,
        IsoscelesTriangle,
        EquilateralTriangle
    };

    SampleData (Type type, int x, int y, double a, double b, double c);

    Type _type {Triangle};
    int _x;
    int _y;
    double _a;
    double _b;
    double _c;
};

class Sample
{
public:
    Sample (SampleData &data);
    ~Sample ();
    QPolygon getPolygon ();
private:
    Triangle *_triangle {nullptr};
    QPoint *_pivot;
    SampleData::Type _type {SampleData::Triangle};
};

#endif // SAMPLE_H
