#include "Painter.h"
#include <QtCore/QDebug>

Painter::Painter ()
{
}

Painter::~Painter ()
{

}

void Painter::setList (QList<Sample*> *list)
{
    _list = list;
}

QPolygon Painter::print (int i)
{
    return (_list->at(i)->getPolygon ());
}

int Painter::sizeList()
{
    return _list->size ();
}
