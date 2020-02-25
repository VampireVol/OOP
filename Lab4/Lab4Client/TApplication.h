#ifndef TAPPLICATION_H
#define TAPPLICATION_H
#include <QApplication>
#include "TInterface.h"
#include "CommunicatorClient.h"

class TApplication : public QApplication
{
public:
    TApplication (int & argc ,char** argv);
    ~TApplication ();
    int exec ();

private:
    CommunicatorClient *_client;
    TInterface *_interface;
};

#endif // TAPPLICATION_H
