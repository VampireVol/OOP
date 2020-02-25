#ifndef POLYNOM_H
#define POLYNOM_H
#include "Number.h"
#include <iostream>
#include <QString>

using namespace std;

class Polynom
{
public:
    Polynom ();
    Polynom (number a, number b, number c);

    int roots (number *x);
    QString toString ();

private:
    number _a;
    number _b;
    number _c;
};

#endif // POLYNOM_H
