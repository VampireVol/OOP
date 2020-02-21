#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "Polygon.h"

class Quadrangle : public Polygon
{
public:
    explicit Quadrangle (double a, double b, double c,
                         double alpha, double beta);
    QString toString () override;
};

#endif // QUADRANGLE_H
