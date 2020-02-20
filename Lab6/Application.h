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
signals:
    void printNext ();
private slots:
    void slotAddSample (SampleData &data);
private:
    InterfaceWindow *_interfaceWindow {nullptr};
    Canvas *_canvas {nullptr};
    Painter *_painter {nullptr};
    QList<Sample*> _list;
};

#endif // APPLICATION_H
