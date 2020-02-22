#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H
#include "Quadrangle.h"

class Parallelogram : public Quadrangle
{
public:
    Parallelogram (const double &a, const double &b, const double &alpha);
    QString toString () override;
};

#endif // PARALLELOGRAM_H
