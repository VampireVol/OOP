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
    ~Canvas () override;
    void setPainter (Painter *painter);
public slots:
    void slotPrintNext ();
signals:
    void sendPivot (int x, int y);
private slots:
    void mousePressEvent (QMouseEvent *event) override;
private:
    void paintEvent (QPaintEvent *event) override;
    Ui::Canvas *_ui;
    Painter *_painter;
};

#endif // CANVAS_H
