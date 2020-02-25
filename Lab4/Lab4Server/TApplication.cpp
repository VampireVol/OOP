#include "TApplication.h"

TApplication::TApplication (int &argc, char **argv)
    : QCoreApplication (argc, argv)
    , _server (new CommunicatorServer (this))

{
    connect (_server, &CommunicatorServer::sendData, this, &TApplication::doCommand);
}

TApplication::~TApplication ()
{
    if (_server)
        delete _server;

}

int TApplication::exec ()
{

    return QCoreApplication::exec ();
}

void TApplication::doCommand (const QString &data)
{
    QStringList list = data.split(" ");
    if (list[0] == "C") {
        QList<number> nums;
        for (int i = 1; i < list.size (); i += 2) {
            double r = list[i].toDouble ();
            double img = list[i + 1].toDouble ();
            nums.append(number (r, img));
        }
        _polynom = Polynom (nums[0], nums[1], nums[2]);
        number x[2];
        int roots = _polynom.roots(x);
        if (2 == roots) {
            _server->sendAnswer (QString ("x[0] = %1; x[1] = %2")
                                 .arg (x[0].toString ())
                                 .arg (x[1].toString ()));
        } else if (1 == roots) {
            _server->sendAnswer (QString ("x[0], x[1] = %1")
                                 .arg (x[0].toString ()));
        } else {
            _server->sendAnswer (QString ("Roots not found"));
        }

    } else if (list[0] == "S") {
        _server->sendAnswer (_polynom.toString ());
    } else {
        qDebug () << "[CommunicatorServer][processTheDatagram] command error: " << qPrintable(data);
    }
}
