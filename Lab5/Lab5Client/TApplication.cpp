#include "TApplication.h"

TApplication::TApplication (int &argc, char **argv)
    : QApplication (argc, argv)
    , _client (new CommunicatorClient (this))
    , _interface (new TInterface)

{
    connect (_interface, &TInterface::sendData, _client, &CommunicatorClient::sendData);
    connect (_client, &CommunicatorClient::sendAnswer, _interface, &TInterface::slotSetLabel);
}

TApplication::~TApplication ()
{
    if (_client)
        delete _client;
    if (_interface)
        delete _interface;
}

int TApplication::exec ()
{
    _interface->show ();
    return QApplication::exec ();
}
