#ifndef SAMPLE_H
#define SAMPLE_H
#include <QtCore/QPointF>

struct SampleData
{
    enum Type
    {
        Rectangle,
        Square,
        Ellipse,
        Circle
    };

    SampleData (const Type &type, const QPointF &pivot, const double &a, const double &b = 0);

    Type _type;
    QPointF _pivot;
    double _a;
    double _b;
};

class Sample
{
public:
    Sample (const QPointF &pivot, const double &a, const double &b);
    virtual ~Sample ();
    virtual bool checkPoint (const double &x, const double &y) = 0;
protected:
    QPointF _pivot;
    double _a;
    double _b;
};

#endif // SAMPLE_H
