#ifndef POLYNOM_H
#define POLYNOM_H
#include <iostream>
#include <QString>

using namespace std;
template<typename T>
class Polynom
{
public:
    Polynom ();
    Polynom (T a, T b, T c);
    int roots (T *x);
    QString toString ();

private:
    T _a;
    T _b;
    T _c;
};

template<typename T>
Polynom<T>::Polynom ()
    : _a (0)
    , _b (0)
    , _c (0)
{

}

template<typename T>
Polynom<T>::Polynom (T a, T b, T c)
    : _a (a)
    , _b (b)
    , _c (c)
{}

template<typename T>
int Polynom<T>::roots (T *x)
{
    T D = _b * _b - 4 * _a * _c;

    if (D > 0) {
        x[0] = (-_b + sqrt (D)) / (2 * _a);
        x[1] = (-_b - sqrt (D)) / (2 * _a);
        return 2;
    } else if (D == 0) {
        x[0] = -_b / (2 * _a);
        return 1;
    }
    return 0;
}

template<typename T>
QString Polynom<T>::toString ()
{
    return QString ("%1x^2 + %2x + %3")
            .arg(_a)
            .arg(_b)
            .arg(_c);
}


#endif // POLYNOM_H
