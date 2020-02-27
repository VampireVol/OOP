#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkDatagram>

class CommunicatorServer : public QUdpSocket
{
    Q_OBJECT
public:
    CommunicatorServer (QObject *parent);
    void sendAnswer (const QString &data);
signals:
    void sendData (const QString &data);
private slots:
    void readPendingDatagrams ();
private:
    void processTheDatagram (QNetworkDatagram &data);
};

#endif // COMMUNICATOR_H
