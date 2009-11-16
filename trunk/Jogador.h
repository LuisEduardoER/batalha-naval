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
    Jogador(int, int, QString);
    Servidor *server;
    Socket *cliente;
    Chat *chat;

    void init();
    int tipo_conexao;
    int port;
    QString host;
public slots:
    void EnviarMensagem();
    void EnviarMensagem(QString _msg, int _mode);
    void LerMensagem();
private:
    void run();

};

#endif // JOGADOR_H
