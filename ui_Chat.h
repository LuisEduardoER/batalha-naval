/********************************************************************************
** Form generated from reading ui file 'Chat.ui'
**
** Created: Sat 14. Nov 22:42:35 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QVBoxLayout *verticalLayout_4;
    QTextEdit *textoConversa;
    QHBoxLayout *horizontalLayout;
    QLineEdit *linhaDeEdicao;
    QPushButton *enviarButton;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(216, 323);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Chat->sizePolicy().hasHeightForWidth());
        Chat->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(Chat);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        textoConversa = new QTextEdit(Chat);
        textoConversa->setObjectName(QString::fromUtf8("textoConversa"));
        textoConversa->setReadOnly(true);

        verticalLayout_4->addWidget(textoConversa);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        linhaDeEdicao = new QLineEdit(Chat);
        linhaDeEdicao->setObjectName(QString::fromUtf8("linhaDeEdicao"));

        horizontalLayout->addWidget(linhaDeEdicao);

        enviarButton = new QPushButton(Chat);
        enviarButton->setObjectName(QString::fromUtf8("enviarButton"));

        horizontalLayout->addWidget(enviarButton);


        verticalLayout_4->addLayout(horizontalLayout);


        retranslateUi(Chat);

        QMetaObject::connectSlotsByName(Chat);
    } // setupUi

    void retranslateUi(QWidget *Chat)
    {
        Chat->setWindowTitle(QApplication::translate("Chat", "Form", 0, QApplication::UnicodeUTF8));
        enviarButton->setText(QApplication::translate("Chat", "Enviar", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(Chat);
    } // retranslateUi

};

namespace Ui {
    class Chat: public Ui_Chat {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
