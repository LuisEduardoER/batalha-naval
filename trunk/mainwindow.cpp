#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            pos_mapa1.append(0);
            pos_mapa2.append(0);

            QPushButton *btn1 = new QPushButton();
            QPushButton *btn2 = new QPushButton();


            btn1->setMinimumSize(36, 36);
            btn2->setMinimumSize(36, 36);
            btn_mapa1.append(btn1);
            btn_mapa2.append(btn2);

            ui->gridLayout->addWidget(btn1, i, j);
            ui->gridLayout_3->addWidget(btn2, i, j);
        }
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{

    ui->lineEdit->setText(QString::number(event->x()));
    ui->lineEdit_2->setText(QString::number(event->y()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}

