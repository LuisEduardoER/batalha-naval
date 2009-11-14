#include "Socket.h"

Socket::Socket() : QObject(){
    this->socket = 0;
    this->error = false;
    this->finish = false;
}

void Socket::init(){
    this->socket = new QTcpSocket();
    this->socket->connectToHost("localhost",8000);
    //connect (this->socket, SIGNAL(readyRead()), this, SLOT(LerMensagem()));
}

QString Socket::LerMensagem(){
    QDataStream in(this->socket);
    in.setVersion(QDataStream::Qt_4_0);
    QString text;
    in >> text;
    qDebug("ola");
    cout<<text.toStdString()<<endl;
    return text;
}
