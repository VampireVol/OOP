#include "CommunicatorServer.h"
#include <QDebug>

CommunicatorServer::CommunicatorServer (QObject *parent)
    : QUdpSocket (parent)
{
    bind (QHostAddress::LocalHost, 7755, QUdpSocket::ReuseAddressHint);
    connect (this, &QUdpSocket::readyRead, this, &CommunicatorServer::readPendingDatagrams);
}

void CommunicatorServer::sendAnswer (const QString &data)
{
    writeDatagram (data.toUtf8 (), QHostAddress::LocalHost, 7754);
}

void CommunicatorServer::readPendingDatagrams ()
{
    while (hasPendingDatagrams ()) {
        QNetworkDatagram datagram = receiveDatagram ();
        processTheDatagram (datagram);
    }
}

void CommunicatorServer::processTheDatagram (QNetworkDatagram &data)
{
    if (!data.isNull())
    {
        QByteArray b = data.data();
        QString d = QString::fromUtf8(b);
        emit sendData (d);
    }
    else
    {
        qDebug () << "[CommunicatorServer][processTheDatagram] data is null";
    }
}
