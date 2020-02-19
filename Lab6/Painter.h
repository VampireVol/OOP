#ifndef PAINTER_H
#define PAINTER_H
#include <QList>
#include <QPainter>

#include "Sample.h"

class Painter : public QPainter
{
public:
    Painter ();
    void setList (QList<Sample> *list);
private:
    QList<Sample> *_list;
};

#endif // PAINTER_H
