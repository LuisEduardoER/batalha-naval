#ifndef SOCKET_H
#define SOCKET_H

#define CHAT 1
#define JOGADA 2
#define RESPOSTA 3
#define FIM 4

#include <QTcpSocket>
#include <iostream>
#include <QString>
using namespace std;
class Socket:public QObject{
    Q_OBJECT

public:
    Socket(int, QString);
    void init();
    QString LerMensagem();
    void EnviarMensagem(QString _msg, int _mode);
    QTcpSocket *socket;

    int port;
    QString host;
public slots:
    void ErroDeConexao();
private:

    bool error;
    bool finish;
};

#endif // CAMADASOCKET_H
