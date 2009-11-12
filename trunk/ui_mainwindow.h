/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Wed 11. Nov 23:04:22 2009
**      by: Qt User Interface Compiler version 4.5.1
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSair;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QFrame *mapa1;
    QGridLayout *_2;
    QGridLayout *gridLayout;
    QFrame *mapa2;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_3;
    QListWidget *listWidget;
    QMenuBar *menuBar;
    QMenu *menuArquivo;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(800, 600));
        MainWindow->setMaximumSize(QSize(800, 600));
        actionSair = new QAction(MainWindow);
        actionSair->setObjectName(QString::fromUtf8("actionSair"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setMargin(11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        mapa1 = new QFrame(centralWidget);
        mapa1->setObjectName(QString::fromUtf8("mapa1"));
        mapa1->setFrameShape(QFrame::Panel);
        mapa1->setFrameShadow(QFrame::Plain);
        _2 = new QGridLayout(mapa1);
        _2->setSpacing(6);
        _2->setMargin(11);
        _2->setObjectName(QString::fromUtf8("_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMinAndMaxSize);

        _2->addLayout(gridLayout, 0, 1, 1, 1);


        horizontalLayout->addWidget(mapa1);

        mapa2 = new QFrame(centralWidget);
        mapa2->setObjectName(QString::fromUtf8("mapa2"));
        mapa2->setFrameShape(QFrame::Panel);
        mapa2->setFrameShadow(QFrame::Plain);
        gridLayout_2 = new QGridLayout(mapa2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setMargin(11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));

        gridLayout_2->addLayout(gridLayout_3, 0, 0, 1, 1);


        horizontalLayout->addWidget(mapa2);


        verticalLayout->addLayout(horizontalLayout);

        listWidget = new QListWidget(centralWidget);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setMaximumSize(QSize(16777215, 150));
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setMovement(QListView::Free);
        listWidget->setLayoutMode(QListView::Batched);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setUniformItemSizes(false);
        listWidget->setWordWrap(false);

        verticalLayout->addWidget(listWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuArquivo = new QMenu(menuBar);
        menuArquivo->setObjectName(QString::fromUtf8("menuArquivo"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuArquivo->menuAction());
        menuArquivo->addAction(actionSair);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionSair->setText(QApplication::translate("MainWindow", "Sair", 0, QApplication::UnicodeUTF8));
        mapa1->setStyleSheet(QApplication::translate("MainWindow", "background-image: url(Mar.jpg);", 0, QApplication::UnicodeUTF8));
        mapa2->setStyleSheet(QApplication::translate("MainWindow", "background-image: url(Mar.jpg);", 0, QApplication::UnicodeUTF8));
        menuArquivo->setTitle(QApplication::translate("MainWindow", "Arquivo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
