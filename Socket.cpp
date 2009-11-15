#include "Socket.h"
#include <QMessageBox>
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
void  Socket::EnviarMensagem(QString _msg){
    QByteArray data;
    QDataStream out (&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << _msg;
    if (!this->socket->isOpen()) {
        this->socket->open(QIODevice::ReadWrite);
    }
    this->socket->write(data);
}
