#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include "Painter.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:
    explicit Canvas (QWidget *parent = nullptr);
    ~Canvas ();
    void setPainter (Painter *painter);

private:
    Ui::Canvas *_ui;
    Painter *_painter;
};

#endif // CANVAS_H
