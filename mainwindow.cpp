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
            QFrame *fr1 = new QFrame();
            QFrame *fr2 = new QFrame();
            fr1->setFrameShape(QFrame::Panel);
            fr1->setFrameShadow(QFrame::Plain);
            fr2->setFrameShape(QFrame::Panel);
            fr2->setFrameShadow(QFrame::Plain);
            frame1.append(fr1);
            frame2.append(fr2);
            ui->gridLayout->addWidget(fr1, i, j);
            ui->gridLayout_3->addWidget(fr2, i, j);
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

