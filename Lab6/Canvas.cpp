#include "Canvas.h"
#include "ui_Canvas.h"

Canvas::Canvas (QWidget *parent)
    : QWidget (parent)
    , _ui (new Ui::Canvas)
{
    _ui->setupUi (this);

}

Canvas::~Canvas ()
{
    delete _ui;
}

void Canvas::setPainter (Painter *painter)
{
    _painter = painter;
}

void Canvas::slotPrintNext()
{
    repaint ();
}

void Canvas::mousePressEvent (QMouseEvent *event)
{
    emit sendPivot (event->x(), event->y());
    QWidget::mousePressEvent (event);
}

void Canvas::paintEvent (QPaintEvent *event)
{
    QPainter painter (this);
    painter.setBrush (QBrush (Qt::blue, Qt::SolidPattern));
    for (int i = 0; i < _painter->sizeList (); ++i)
    {
        painter.drawPolygon (_painter->print (i));

    }

}
