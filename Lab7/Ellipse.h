#ifndef ELLIPSE_H
#define ELLIPSE_H
#include "Sample.h"

class Ellipse : public Sample
{
public:
    Ellipse (const QPointF &pivot, const double &a, const double &b);
    bool checkPoint (const double &x, const double &y) override;
};

#endif // ELLIPSE_H
