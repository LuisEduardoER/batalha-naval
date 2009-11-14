#ifndef SOCKET_H
#define SOCKET_H
#include <QTcpSocket>
#include <iostream>
#include <QString>
using namespace std;
class Socket:public QObject{
    Q_OBJECT

public:
    Socket();
    void init();
    QString LerMensagem();
    QTcpSocket *socket;
private:

    bool error;
    bool finish;
};

#endif // CAMADASOCKET_H
