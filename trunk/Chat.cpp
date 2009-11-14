#include "Chat.h"
#include "ui_Chat.h"
#include <QDebug>
#include <iostream>

using namespace std;
Chat::Chat(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Chat)
{
    m_ui->setupUi(this);
    //m_ui->textoConversa->setReadOnly(true);
}

Chat::~Chat()
{
    delete m_ui;
}

void Chat::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void Chat::on_enviarButton_clicked()
{
    emit EnviarMensagem();
}

QString Chat::getMensagem()
{
    return this->m_ui->linhaDeEdicao->text();
}
void Chat::clearMensagem()
{
    this->m_ui->linhaDeEdicao->setText(QString(""));
}
void Chat::adicionarAConversa(QString _msg)
{
    QString conversa("\n"+_msg);
    this->m_ui->textoConversa->append(conversa);
}
