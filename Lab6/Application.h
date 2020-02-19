#ifndef APPLICATION_H
#define APPLICATION_H
#include <QApplication>
#include <QList>

#include "InterfaceWindow.h"
#include "Canvas.h"
#include "Painter.h"

class Application : public QApplication
{
public:
    Application (int & argc ,char** argv);
    virtual ~Application ();

    int exec ();

private slots:
    void slotAddSample (SampleData &data);
private:
    InterfaceWindow *_interfaceWindow {nullptr};
    Painter *_painter {nullptr};
    Canvas *_canvas {nullptr};
    QList<Sample> _list;
};

#endif // APPLICATION_H
