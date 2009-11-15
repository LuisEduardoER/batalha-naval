#ifndef SERVIDOR_H
#define SERVIDOR_H

#define CHAT 1
#define JOGADA 2
#define RESPOSTA 3
#define FIM 4

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
    void EnviarMensagem(QString _msg, int _mode);
    QString LerMensagem();

    int port;
public slots:
    void addCliente();
private:
    QTcpServer *server;

};

#endif // SERVIDOR_H
