#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include <QCoreApplication>
#include "CommunicatorServer.h"
#include "Complex.h"
#include "Polynom.h"

class TApplication : public QCoreApplication
{
public:
    TApplication (int & argc ,char** argv);
    ~TApplication ();
    int exec ();
private slots:
    void doCommand (const QString &data);
private:
    CommunicatorServer *_server {nullptr};
    Polynom<double> _pD;
    Polynom<Complex> _pC;
};

#endif // TAPPLICATION_H
