#include "Servidor.h"
#include <iostream>

using namespace std;


Servidor::Servidor(): QObject()
{
    this->server=0;
}

void Servidor::addCliente(){
    qDebug("conectado");
    this->cliente = this->server->nextPendingConnection();
    //this->cliente.append(this->server->nextPendingConnection());
}

void Servidor::init(){
    this->server = new QTcpServer;
    this->server->listen(QHostAddress::Any, 8000);
    connect (this->server, SIGNAL(newConnection()), this, SLOT(addCliente()));

}
void Servidor::EnviarMensagem(QString _msg){
    QByteArray data;
    QDataStream out (&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << _msg;
    if (!this->cliente->isOpen()) {
        this->cliente->open(QIODevice::ReadWrite);
    }

    this->cliente->write(data);

}

