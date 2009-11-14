#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QList>
class Servidor : public QObject
{
    Q_OBJECT
public:
    Servidor();
    void init();
    //QList<QTcpSocket*> cliente;
    QTcpSocket *cliente;
    void EnviarMensagem(QString _msg);
public slots:
    void addCliente();
private:
    QTcpServer *server;

};

#endif // SERVIDOR_H
