#ifndef SOCKET_H
#define SOCKET_H
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
    void EnviarMensagem(QString _msg);
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
