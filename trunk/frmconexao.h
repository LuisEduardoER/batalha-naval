#ifndef FRMCONEXAO_H
#define FRMCONEXAO_H

#include <QtGui/QDialog>

#include "conexao.h"

namespace Ui {
    class frmConexao;
}

class frmConexao : public QDialog {
    Q_OBJECT
    Q_DISABLE_COPY(frmConexao)
public:
    explicit frmConexao(QWidget *parent = 0);
    virtual ~frmConexao();
    Conexao *con;

protected:
    virtual void changeEvent(QEvent *e);

private:
    Ui::frmConexao *m_ui;

};

#endif // FRMCONEXAO_H
