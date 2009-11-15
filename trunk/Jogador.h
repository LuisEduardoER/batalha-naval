#ifndef JOGADOR_H
#define JOGADOR_H

#define SERVIDOR 1
#define CLIENTE 2


#include <qthread.h>
#include <QString>
#include "Servidor.h"
#include "Socket.h"
#include "Chat.h"

class Jogador: public QThread{
    Q_OBJECT
public:
    Jogador(int);
    Servidor *server;
    Socket *cliente;
    Chat *chat;

    void init();
    int tipo_conexao;
public slots:
    void EnviarMensagem();
    void LerMensagem();
private:
    void run();

};

#endif // JOGADOR_H
