#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    btn_gp1 = new QButtonGroup();
    btn_gp2 = new QButtonGroup();
    int cont=0;
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
            
            btn_gp1->addButton(btn1);
            btn_gp1->setId(btn1, cont);

            btn_gp2->addButton(btn2);
            btn_gp2->setId(btn2, cont++);

            connect(btn_gp1, SIGNAL(buttonClicked(int)),this, SLOT(click_btn1(int)));
            connect(btn_gp2, SIGNAL(buttonClicked(int)),this, SLOT(click_btn2(int)));
        }
    }
}

int MainWindow::click_btn1(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));
    ui->lineEdit->setText(QString::number(num));
}

int MainWindow::click_btn2(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));
    ui->lineEdit_2->setText(QString::number(num));
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

