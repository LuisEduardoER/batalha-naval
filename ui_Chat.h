/********************************************************************************
** Form generated from reading ui file 'Chat.ui'
**
** Created: Thu 12. Nov 22:21:44 2009
**      by: Qt User Interface Compiler version 4.5.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QTextEdit>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Chat
{
public:
    QPushButton *enviarButton;
    QLineEdit *linhaDeEdicao;
    QTextEdit *textoConversa;

    void setupUi(QWidget *Chat)
    {
        if (Chat->objectName().isEmpty())
            Chat->setObjectName(QString::fromUtf8("Chat"));
        Chat->resize(211, 324);
        enviarButton = new QPushButton(Chat);
        enviarButton->setObjectName(QString::fromUtf8("enviarButton"));
        enviarButton->setGeometry(QRect(140, 290, 61, 21));
        linhaDeEdicao = new QLineEdit(Chat);
        linhaDeEdicao->setObjectName(QString::fromUtf8("linhaDeEdicao"));
        linhaDeEdicao->setGeometry(QRect(10, 290, 113, 20));
        textoConversa = new QTextEdit(Chat);
        textoConversa->setObjectName(QString::fromUtf8("textoConversa"));
        textoConversa->setGeometry(QRect(10, 10, 191, 271));

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
