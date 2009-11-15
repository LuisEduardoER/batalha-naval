#include "Jogador.h"
#include <QDebug>

Jogador::Jogador(int t, int p, QString h) : QThread()
{
    tipo_conexao=t;
    port=p;
    host=h;
    this->server = new Servidor(port);
    this->cliente = new Socket(port, host);
    this->chat = new Chat();
}

void Jogador::init(){
    if(tipo_conexao==CLIENTE){
        this->cliente->init();
        //this->chat->show();
    }
    else {
        this->server->init();
        //this->chat->show();
    }
}

void Jogador::run(){
    if(tipo_conexao==CLIENTE){
        connect (this->chat, SIGNAL(EnviarMensagem()), this, SLOT(EnviarMensagem()));
        connect (this->cliente->socket, SIGNAL(readyRead()), this, SLOT(LerMensagem()));
    }
    else{
        connect (this->chat, SIGNAL(EnviarMensagem()), this, SLOT(EnviarMensagem()));
        while(this->server->cliente ==0);
        if(this->server->cliente != 0){
            connect (this->server->cliente, SIGNAL(readyRead()), this, SLOT(LerMensagem()));
        }
    }
}

void Jogador::EnviarMensagem(){
    if(tipo_conexao==CLIENTE){
        QString msg;
        msg = this->chat->getMensagem();
        this->chat->clearMensagem();
        this->cliente->EnviarMensagem(msg);
        this->chat->adicionarAConversa(msg);
    }
    else{
        QString msg;
        msg = this->chat->getMensagem();
        this->chat->clearMensagem();
        this->server->EnviarMensagem(msg);
        this->chat->adicionarAConversa(msg);
        qDebug()<<msg;
    }
}
void Jogador::LerMensagem(){
    QStringList msgSplit;
    QString msg;
    if(tipo_conexao==CLIENTE){
        msg = this->cliente->LerMensagem();
    }
    else{
        msg = this->server->LerMensagem();
   }
    msgSplit = msg.split("::");
    if(tipo_conexao==CLIENTE && msgSplit.at(0) == "chat"){
        this->chat->adicionarAConversa(msgSplit.at(1));
    }
    else if(msgSplit.at(0) == "chat"){
        this->chat->adicionarAConversa(msgSplit.at(1));
    }

}
