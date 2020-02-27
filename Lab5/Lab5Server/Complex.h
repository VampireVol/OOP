#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
#include <QString>

using namespace std;

class Complex
{
public:
    Complex ();
    Complex (double real, double img);
    Complex (double n);

    friend ostream &operator<< (ostream& os, const Complex& n);
    friend istream &operator>> (istream& is, Complex& n);

    friend Complex operator- (const Complex &right);
    friend Complex operator+ (const Complex &left, const Complex &right);
    friend Complex operator- (const Complex &left, const Complex &right);
    friend Complex operator* (const Complex &left, const Complex &right);
    friend Complex operator* (const double &left, const Complex &right);
    friend Complex operator/ (const Complex &left, const Complex &right);
    friend bool operator== (const Complex &left, const Complex &right);
    friend bool operator== (const Complex &left, const double &right);
    friend bool operator> (const Complex &left, const int &right);
    friend Complex sqrt (const Complex &n);
    operator QString ();

private:
    double _real;
    double _img;
};

#endif // COMPLEX_H
