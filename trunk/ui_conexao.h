/********************************************************************************
** Form generated from reading ui file 'conexao.ui'
**
** Created: Mon 16. Nov 03:04:28 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CONEXAO_H
#define UI_CONEXAO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Conexao
{
public:
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QRadioButton *rbServidor;
    QRadioButton *rbCliente;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *edtPorta;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *edtIP;

    void setupUi(QWidget *Conexao)
    {
        if (Conexao->objectName().isEmpty())
            Conexao->setObjectName(QString::fromUtf8("Conexao"));
        Conexao->resize(233, 128);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Conexao->sizePolicy().hasHeightForWidth());
        Conexao->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(Conexao);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(Conexao);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        rbServidor = new QRadioButton(groupBox);
        rbServidor->setObjectName(QString::fromUtf8("rbServidor"));

        horizontalLayout->addWidget(rbServidor);

        rbCliente = new QRadioButton(groupBox);
        rbCliente->setObjectName(QString::fromUtf8("rbCliente"));

        horizontalLayout->addWidget(rbCliente);


        verticalLayout_2->addWidget(groupBox);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Conexao);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        edtPorta = new QLineEdit(Conexao);
        edtPorta->setObjectName(QString::fromUtf8("edtPorta"));

        horizontalLayout_2->addWidget(edtPorta);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(Conexao);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        edtIP = new QLineEdit(Conexao);
        edtIP->setObjectName(QString::fromUtf8("edtIP"));

        horizontalLayout_3->addWidget(edtIP);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(Conexao);

        QMetaObject::connectSlotsByName(Conexao);
    } // setupUi

    void retranslateUi(QWidget *Conexao)
    {
        Conexao->setWindowTitle(QApplication::translate("Conexao", "Form", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("Conexao", "Tipo", 0, QApplication::UnicodeUTF8));
        rbServidor->setText(QApplication::translate("Conexao", "Servidor", 0, QApplication::UnicodeUTF8));
        rbCliente->setText(QApplication::translate("Conexao", "Cliente", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Conexao", "Porta", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Conexao", "IP", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Conexao);
    } // retranslateUi

};

namespace Ui {
    class Conexao: public Ui_Conexao {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONEXAO_H
