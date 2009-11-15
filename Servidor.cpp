#include "Servidor.h"
#include <iostream>

using namespace std;


Servidor::Servidor(int p): QObject()
{
    port=p;
    this->server=0;
    this->cliente = 0;
}

void Servidor::addCliente(){
    qDebug("conectado");
    this->cliente = new QTcpSocket();
    this->cliente = this->server->nextPendingConnection();
   // connect(this->cliente,SIGNAL(readyRead()), this, SLOT(LerMensagem()));
}

void Servidor::init(){
    this->server = new QTcpServer;
    this->server->listen(QHostAddress::Any, port);
    connect (this->server, SIGNAL(newConnection()), this, SLOT(addCliente()));

}
void Servidor::EnviarMensagem(QString _msg){
    QByteArray data;
    QDataStream out (&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << _msg;
    /*
    for(int i=0; i<this->cliente.size(); i++){
        if (!this->cliente.at(i)->isOpen()) {
            this->cliente.at(i)->open(QIODevice::ReadWrite);
        }
        this->cliente.at(i)->write(data);
    }
    */
    if (!this->cliente->isOpen()) {
        this->cliente->open(QIODevice::ReadWrite);
    }
    this->cliente->write(data);

}
QString Servidor::LerMensagem(){
    qDebug("ola");
    QDataStream in(this->cliente);
    in.setVersion(QDataStream::Qt_4_0);
    QString text;
    in >> text;
    qDebug("ola");
    cout<<text.toStdString()<<endl;
    return text;
}

