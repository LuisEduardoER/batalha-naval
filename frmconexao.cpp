#include "frmconexao.h"
#include "ui_frmconexao.h"

frmConexao::frmConexao(QWidget *parent) :
    QDialog(parent),
    m_ui(new Ui::frmConexao)
{
    m_ui->setupUi(this);
    con= new Conexao();
    m_ui->horizontalLayout->addWidget(con);
}

frmConexao::~frmConexao()
{
    delete m_ui;
}

void frmConexao::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        m_ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
