#ifndef POLYNOM_H
#define POLYNOM_H
#include "Number.h"
#include <iostream>

using namespace std;

//!
//! \brief Класс полинома второй степени
//! \author Balanin Sergey
//!
class Polynom
{
public:
    //! \brief Конструктор
    //! \param a
    //! \param b
    //! \param c
    Polynom (number a, number b, number c);

    //! \brief Вычисление корней
    //! \param[out] x Полученные корни
    //! \return Число корней
    int roots (number *x);

    //! \brief Переопределение оператора вывода
    //! \param os Поток вывода
    //! \param p Объект
    //! \return Поток вывода
    friend ostream &operator<< (ostream& os, Polynom& p);

private:
    number _a;  //!< a
    number _b;  //!< b
    number _c;  //!< c
};

#endif // POLYNOM_H
