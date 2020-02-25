#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include <QCoreApplication>
#include "CommunicatorServer.h"
#include "Polynom.h"

class TApplication : public QCoreApplication
{
    //Q_OBJECT
public:
    TApplication (int & argc ,char** argv);
    ~TApplication ();
    int exec ();

private slots:
    void doCommand (const QString &data);
private:
    CommunicatorServer *_server {nullptr};
    Polynom _polynom;
};

#endif // TAPPLICATION_H
