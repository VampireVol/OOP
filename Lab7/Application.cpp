#include "Application.h"

Application::Application (int &argc, char **argv)
    : QApplication (argc, argv)
    , _interface (new Interface)
    , _target (new Target (&_list, this))

{
    connect (_interface, &Interface::sendSampleData,
             this, &Application::slotAddSample);
    connect (_interface, &Interface::sendCheckData,
             _target, &Target::calcResult);
    connect (_target, &Target::sendResult,
             _interface, &Interface::setResult);

}

Application::~Application ()
{
    if (_interface)
        delete _interface;
    for (int i = 0; i < _list.size (); ++i)
        if (_list[i])
            delete _list[i];
}

int Application::exec ()
{
    _interface->show ();

    return QApplication::exec ();
}

void Application::slotAddSample (const SampleData &data)
{
    Sample *s;
    if (SampleData::Rectangle == data._type) {
        s = new Rectangle (data._pivot, data._a, data._b);
    }
    else if (SampleData::Square == data._type) {
        s = new Square (data._pivot, data._a);
    }
    else if (SampleData::Ellipse == data._type) {
        s = new Ellipse (data._pivot, data._a, data._b);
    }
    else {
        s = new Circle (data._pivot, data._a);
    }
    _list.append (s);
}
