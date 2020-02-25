#include "CommunicatorClient.h"

CommunicatorClient::CommunicatorClient (QObject *parent)
    : QUdpSocket (parent)
{
    this->bind(QHostAddress::LocalHost, 7754, QUdpSocket::ReuseAddressHint);
    connect (this, &QUdpSocket::readyRead, this, &CommunicatorClient::readPendingDatagrams);
}

void CommunicatorClient::sendData (const QString &data)
{
    writeDatagram (data.toUtf8 (), QHostAddress::LocalHost, 7755);
}

void CommunicatorClient::readPendingDatagrams ()
{
    while (hasPendingDatagrams ()) {
        QNetworkDatagram datagram = receiveDatagram ();
        processTheDatagram (datagram);
    }
}

void CommunicatorClient::processTheDatagram (QNetworkDatagram &data)
{
    if (!data.isNull())
    {
        QByteArray b = data.data();
        QString d = QString::fromUtf8(b);
        emit sendAnswer (d);
    }
    else
    {
        qDebug () << "[CommunicatorClient][processTheDatagram] data is null";
    }
}
