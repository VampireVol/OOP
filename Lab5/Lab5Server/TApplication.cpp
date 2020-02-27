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
        if (list[1] == "D") {
            QList<double> nums;
            for (int i = 2; i < list.size (); ++i) {
                nums.append(list[i].toDouble ());
            }
            _pD = Polynom<double> (nums[0], nums[1], nums[2]);
            double x[2];
            int roots = _pD.roots(x);
            if (2 == roots) {
                _server->sendAnswer (QString ("x[0] = %1; x[1] = %2")
                                     .arg (x[0])
                                     .arg (x[1]));
            } else if (1 == roots) {
                _server->sendAnswer (QString ("x[0], x[1] = %1")
                                     .arg (x[0]));
            } else {
                _server->sendAnswer (QString ("Roots not found"));
            }
        }
        else if (list[1] == "C") {
            QList<Complex> nums;
            for (int i = 2; i < list.size (); i += 2) {
                double r = list[i].toDouble ();
                double img = list[i + 1].toDouble ();
                nums.append(Complex (r, img));
            }
            _pC = Polynom<Complex> (nums[0], nums[1], nums[2]);
            Complex x[2];
            int roots = _pC.roots(x);
            if (2 == roots) {
                _server->sendAnswer (QString ("x[0] = %1; x[1] = %2")
                                     .arg (x[0])
                                     .arg (x[1]));
            } else if (1 == roots) {
                _server->sendAnswer (QString ("x[0], x[1] = %1")
                                     .arg (x[0]));
            } else {
                _server->sendAnswer (QString ("Roots not found"));
            }
        } else
            qDebug () << "[CommunicatorServer][processTheDatagram] command error: " << qPrintable(data);
    } else if (list[0] == "S") {
        if (list[1] == "D")
            _server->sendAnswer (_pD.toString ());
        else if (list[1] == "C")
            _server->sendAnswer (_pC.toString ());
        else
            qDebug () << "[CommunicatorServer][processTheDatagram] command error: " << qPrintable(data);
    } else {
        qDebug () << "[CommunicatorServer][processTheDatagram] command error: " << qPrintable(data);
    }
}
