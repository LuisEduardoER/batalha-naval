/********************************************************************************
** Form generated from reading ui file 'frmconexao.ui'
**
** Created: Mon 16. Nov 03:04:28 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_FRMCONEXAO_H
#define UI_FRMCONEXAO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_frmConexao
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *frmConexao)
    {
        if (frmConexao->objectName().isEmpty())
            frmConexao->setObjectName(QString::fromUtf8("frmConexao"));
        frmConexao->resize(400, 300);
        verticalLayout = new QVBoxLayout(frmConexao);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(frmConexao);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(frmConexao);
        QObject::connect(buttonBox, SIGNAL(accepted()), frmConexao, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), frmConexao, SLOT(reject()));

        QMetaObject::connectSlotsByName(frmConexao);
    } // setupUi

    void retranslateUi(QDialog *frmConexao)
    {
        frmConexao->setWindowTitle(QApplication::translate("frmConexao", "Dialog", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(frmConexao);
    } // retranslateUi

};

namespace Ui {
    class frmConexao: public Ui_frmConexao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRMCONEXAO_H
