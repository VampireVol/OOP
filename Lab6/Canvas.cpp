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
