#ifndef COMMUNICATORCLIENT_H
#define COMMUNICATORCLIENT_H
#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QNetworkDatagram>

class CommunicatorClient : public QUdpSocket
{
    Q_OBJECT
public:
    CommunicatorClient (QObject *parent);
public slots:
    void sendData (const QString &data);
signals:
    void sendAnswer (const QString &data);
private slots:
    void readPendingDatagrams ();
private:
    void processTheDatagram (QNetworkDatagram &data);
};

#endif // COMMUNICATORCLIENT_H
