#include "Target.h"
#include <QDebug>
#include <iostream>

double fRand (double fMin, double fMax)
{
    double f = static_cast<double>(rand()) / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

CheckData::CheckData (const Type &type, const double &w, const double &h, const int &i, const int &j)
    : _type (type), _i (i), _j (j), _w (w), _h (h)
{

}

Target::Target (QList<Sample *> *list, QObject *parent)
    : QObject (parent), _w (0), _h (0), _list (list)
{

}

Target::Target (const double &w, const double &h, QList<Sample *> *list, QObject *parent)
    : QObject (parent), _w (w), _h (h), _list (list)
{

}

void Target::calcResult (const CheckData &data)
{
    double result;
    int fillCount = 0;
    _w = data._w;
    _h = data._h;
    if (CheckData::Regular == data._type) {
        double dw = _w / (data._i + 1);
        double dh = _h / (data._j + 1);

        int count = 0;
        for (int i = 0; i < data._i; ++i)
        {
            double x = dw * (i + 1);
            for (int j = 0; j < data._j; ++j)
            {
                double y = dh * (j + 1);
                for (int k = 0; k < _list->size (); ++k)
                {
                    if (_list->at(k)->checkPoint(x, y)) {
                        ++fillCount;
                        break;
                    }
                }
                ++count;
            }
        }
        qDebug () << count << " " << data._i * data._j << endl;
        result = static_cast<double>(fillCount) / count;
        emit sendResult (result);
    }
    else {
        for (int i = 0; i < data._i; ++i) {
            double x = fRand (0, _w);
            double y = fRand (0, _h);
            for (int j = 0; j < _list->size (); ++j)
            {
                if (_list->at(j)->checkPoint(x, y)) {
                    ++fillCount;
                    break;
                }
            }
        }
        result = static_cast<double>(fillCount) / data._i;
        emit sendResult (result);
    }
}
