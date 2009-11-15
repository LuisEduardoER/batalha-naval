#ifndef CONEXAO_H
#define CONEXAO_H
#define SERVIDOR 1
#define CLIENTE 2

#include <QtGui/QWidget>

namespace Ui {
    class Conexao;
}

class Conexao : public QWidget {
    Q_OBJECT
    Q_DISABLE_COPY(Conexao)
public:
    explicit Conexao(QWidget *parent = 0);
    virtual ~Conexao();

    QString host();
    int port();
    int tipo_conexao;

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::Conexao *m_ui;

private slots:
    void on_rbCliente_clicked();
    void on_rbServidor_clicked();
};

#endif // CONEXAO_H
