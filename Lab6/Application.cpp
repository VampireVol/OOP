#include "Application.h"

Application::Application (int &argc, char **argv)
    : QApplication (argc, argv)
    , _interfaceWindow (new InterfaceWindow)
    , _canvas (new Canvas)
    , _painter (new Painter)

{
    connect (_interfaceWindow, &InterfaceWindow::sendData,
             this, &Application::slotAddSample);
    connect (_canvas, &Canvas::sendPivot,
             _interfaceWindow, &InterfaceWindow::setPivot);
    connect (_interfaceWindow, &InterfaceWindow::printNext,
             _canvas, &Canvas::slotPrintNext);
    _painter->setList (&_list);
    _canvas->setPainter (_painter);
}

Application::~Application ()
{
    if (_interfaceWindow)
        delete _interfaceWindow;
    if (_painter)
        delete _painter;
    if (_canvas)
        delete _canvas;
    for (int i = 0; i < _list.size (); ++i)
        if (_list[i])
            delete _list[i];
}

int Application::exec ()
{
    _canvas->show ();
    _interfaceWindow->show ();

    return QApplication::exec ();
}

void Application::slotAddSample (SampleData &data)
{
    Sample *s = new Sample (data);
    _list.append (s);
}
