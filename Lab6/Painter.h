#ifndef PAINTER_H
#define PAINTER_H
#include <QList>
#include <QPainter>

#include "Sample.h"

class Painter : public QPainter
{

public:
    Painter ();
    ~Painter ();
    void setList (QList<Sample*> *list);
    QPolygon print (int i);
    int sizeList ();
private:
    QList<Sample*> *_list;
};

#endif // PAINTER_H
