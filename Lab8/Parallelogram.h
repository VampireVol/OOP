#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram (double a, double b, double alpha);
    QString toString () override;
};

#endif // PARALLELOGRAM_H
