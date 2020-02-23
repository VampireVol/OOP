#include "Complex.h"

Complex::Complex ()
    : _real (0)
    , _img (0)
{

}

Complex::Complex (double real, double img)
    : _real (real)
    , _img (img)
{

}

Complex::Complex (double n)
    : _real (n)
    , _img (0)
{

}

QString Complex::toString ()
{
    return QString ("(%1 + %2i)")
            .arg(_real)
            .arg(_img);
}

Complex operator* (const Complex &left, const Complex &right)
{
    return Complex (left._real * right._real - left._img * right._img,
                    left._real * right._img + left._img * right._real);
}

Complex operator* (const double &left, const Complex &right)
{
    return Complex (left * right._real, left * right._img);
}

Complex operator/ (const Complex &left, const Complex &right)
{
    return Complex ((left._real * right._real + left._img * right._img) / (right._real * right._real + right._img * right._img),
                    (left._img * right._real - left._real * right._img) / (right._real * right._real + right._img * right._img));
}

bool operator== (const Complex &left, const Complex &right)
{
    if (left._real == right._real && left._img == right._img)
        return true;
    else
        return false;
}

bool operator== (const Complex &left, const double &right)
{
    if (left._real == right && left._img == 0)
        return true;
    else
        return false;
}

Complex sqrt (const Complex &n)
{
    double r = sqrt (n._real * n._real + n._img * n._img);
    double phi = acos (n._real / r);
    return Complex (sqrt(r) * (cos(phi / 2)), sqrt(r) * (sin(phi / 2)));
}

Complex operator- (const Complex &left, const Complex &right)
{
    return Complex (left._real - right._real, left._img - right._img);
}

Complex operator+ (const Complex &left, const Complex &right)
{
    return Complex (left._real + right._real, left._img + right._img);
}

Complex operator- (const Complex &right)
{
    return Complex (-right._real, -right._img);
}


bool operator> (const Complex &left, const int &right)
{
    (void) left;
    (void) right;
    if (right == 0 && left._real == 0 && left._img == 0)
        return false;
    else
        return true;
}

ostream &operator<< (ostream &os, const Complex &n)
{
    os << "(" << n._real << " + " << n._img << "i)";
    return os;
}

istream &operator>> (istream &is, Complex &n)
{
    cout << "real = ";
    is >> n._real;
    cout << "img = ";
    is >> n._img;
    return is;
}
