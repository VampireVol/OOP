#include "Application.h"

Application::Application (int &argc, char **argv)
    : QApplication (argc, argv)
    , _interfaceWindow (new InterfaceWindow)
    , _painter (new Painter)
    , _canvas (new Canvas)
{
    connect (_interfaceWindow, &InterfaceWindow::sendData,
             this, &Application::slotAddSample);
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
}

int Application::exec ()
{
    _canvas->show ();
    _interfaceWindow->show ();

    return QApplication::exec ();
}

void Application::slotAddSample (SampleData &data)
{
    Sample s (data);
    _list.append (data);
}
