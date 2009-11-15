#include "Socket.h"
#include <QMessageBox>
Socket::Socket(int p, QString h) : QObject(){
    host=h;
    port=p;
    this->socket = 0;
    this->error = false;
    this->finish = false;
}

void Socket::init(){
    this->socket = new QTcpSocket();
    this->socket->connectToHost(host,port);
    connect (this->socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(ErroDeConexao()));
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
void  Socket::EnviarMensagem(QString _msg,int _mode){
    if(_mode == CHAT)
        _msg.push_front("chat::");
    else if(_mode == JOGADA)
        _msg.push_front("game::");
    else if(_mode == RESPOSTA)
        _msg.push_front("hit::");
    else if(_mode == FIM)
        _msg.push_front("end::");
    QByteArray data;
    QDataStream out (&data, QIODevice::WriteOnly);
    out.setVersion(QDataStream::Qt_4_0);
    out << _msg;
    if (!this->socket->isOpen()) {
        this->socket->open(QIODevice::ReadWrite);
    }
    this->socket->write(data);
}
void Socket::ErroDeConexao(){
    QMessageBox msgBox;
    msgBox.setText("Ocorreu um erro na conexão com o servidor");
    msgBox.exec();
}
