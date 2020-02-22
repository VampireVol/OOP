#ifndef POLYNOM_H
#define POLYNOM_H
#include "Number.h"
#include <iostream>

using namespace std;

class Polynom
{
public:
    Polynom ();
    Polynom (number a, number b, number c);

    int roots (number *x);

    friend ostream &operator<< (ostream& os, Polynom& p);

private:
    number _a;
    number _b;
    number _c;
};

#endif // POLYNOM_H
