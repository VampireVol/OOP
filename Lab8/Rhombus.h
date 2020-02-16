#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "Parallelogram.h"

class Rhombus : virtual public Parallelogram
{
public:
    Rhombus (double a, double alpha);
    double area () override;
    double perimetr () override;
    QString toString () override;
    //friend ostream& operator<< (ostream &out, const Rhombus *obj);

};

#endif // RHOMBUS_H
