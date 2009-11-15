#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
class Servidor : public QObject
{
    Q_OBJECT
public:
    Servidor(int);
    void init();
    //QList<QTcpSocket*> cliente;
    QTcpSocket *cliente;
    void EnviarMensagem(QString _msg);
    QString LerMensagem();

    int port;
public slots:
    void addCliente();
private:
    QTcpServer *server;

};

#endif // SERVIDOR_H
