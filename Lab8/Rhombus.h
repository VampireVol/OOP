#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Parallelogram.h"

class Rhombus : virtual public Parallelogram
{
public:
    Rhombus (const double &a, const double &alpha);
    QString toString () override;
};

#endif // RHOMBUS_H
