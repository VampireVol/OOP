#ifndef TARGET_H
#define TARGET_H

#include <QObject>
#include "Sample.h"

struct CheckData
{
    enum Type {
        Regular,
        Random
    };
    CheckData (const Type &type, const double &w, const double &h, const int &i, const int &j = 0);
    Type _type {Regular};
    int _i;
    int _j;
    double _w;
    double _h;
};

class Target : public QObject
{
    Q_OBJECT
public:
    explicit Target (QList<Sample*> *list, QObject *parent = nullptr);
    explicit Target (const double &w, const double &h, QList<Sample*> *list, QObject *parent = nullptr);
public slots:
    void calcResult (const CheckData &data);
signals:
    void sendResult (const double &res);
private:
    double _w;
    double _h;
    QList<Sample*> *_list;

};

#endif // TARGET_H
