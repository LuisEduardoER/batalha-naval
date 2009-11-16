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
        this->cliente->EnviarMensagem(msg,CHAT);
        this->chat->adicionarAConversa(msg);
    }
    else{
        QString msg;
        msg = this->chat->getMensagem();
        this->chat->clearMensagem();
        this->server->EnviarMensagem(msg, CHAT);
        this->chat->adicionarAConversa(msg);
        qDebug()<<msg;
    }
}
void Jogador::EnviarMensagem(QString _msg, int _mode){
    if(tipo_conexao==CLIENTE){
        this->cliente->EnviarMensagem(_msg,_mode);
    }
    else{
        this->server->EnviarMensagem(_msg,_mode);
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
    if(msgSplit.at(0) == "chat"){
        if(tipo_conexao==CLIENTE){
            this->chat->adicionarAConversa(msgSplit.at(1));
        }
        else{
            this->chat->adicionarAConversa(msgSplit.at(1));
        }
    }else if(msgSplit.at(0) == "game"){
        emit pacoteJogada(msgSplit.at(1));
    }else if(msgSplit.at(0) == "hit"){
        emit pacoteAcerto(msgSplit.at(1));
    }else if(msgSplit.at(0) == "end"){
        emit pacoteFim(msgSplit.at(1));
    }
}
void Jogador::FimDeJogo(bool _resposta){
    if(_resposta == true)
        emit AcabouOJogo();
    else
        emit NaoAcabouAinda();

}
void Jogador::AlvoDoTiro(bool _resposta){
    if(_resposta == true)
        emit AcertouOTiro();
    else
        emit Agua();
}
