#ifndef QUADRANGLE_H
#define QUADRANGLE_H
#include "Polygon.h"

class Quadrangle : public Polygon
{
public:
    explicit Quadrangle (double a, double b,
                         double c, double d,
                         double alpha, double beta);

    double area () override;
    double perimetr () override;
    QString toString () override;
    //friend ostream& operator<< (ostream &out, const Quadrangle *obj);
protected:
    double _a;
    double _b;
    double _c;
    double _d;
    double _alpha;
    double _beta;
};

#endif // QUADRANGLE_H
