#include "conexao.h"
#include "ui_conexao.h"

Conexao::Conexao(QWidget *parent) :
    QWidget(parent),
    m_ui(new Ui::Conexao)
{
    m_ui->setupUi(this);
}

Conexao::~Conexao()
{
    delete m_ui;
}

void Conexao::changeEvent(QEvent *e)
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

void Conexao::on_rbServidor_clicked()
{
    m_ui->edtIP->setEnabled(false);
}

void Conexao::on_rbCliente_clicked()
{
    m_ui->edtIP->setEnabled(true);
}
