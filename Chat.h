#ifndef CHAT_H
#define CHAT_H

#include <QtGui/QWidget>
#include <QString>
namespace Ui {
    class Chat;
}

class Chat : public QWidget {
    Q_OBJECT
public:
    Chat(QWidget *parent = 0);
    ~Chat();
    QString getMensagem();
    void clearMensagem();
    void adicionarAConversa(QString _msg);
signals:
    void EnviarMensagem();
protected:
    void changeEvent(QEvent *e);
private:
    Ui::Chat *m_ui;
private slots:
    void on_enviarButton_clicked();
};

#endif // CHAT_H
