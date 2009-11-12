#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    IniciaTabuleiro();
    AdicionarNavios();
}

void MainWindow::IniciaTabuleiro(){
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
            btn1->setMouseTracking(true);
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

            connect(ui->listWidget, SIGNAL(currentRowChanged(int)), this, SLOT(setNumN(int)));
        }
    }
}

void MainWindow::AdicionarNavios(){
    QListWidgetItem *barco1 = new QListWidgetItem(ui->listWidget);
    barco1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco1->setIcon(QIcon("navio.jpg"));

    QListWidgetItem *barco2 = new QListWidgetItem(ui->listWidget);
    barco2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco2->setIcon(QIcon("navio.jpg"));

    QListWidgetItem *barco3 = new QListWidgetItem(ui->listWidget);
    barco3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco3->setIcon(QIcon("navio.jpg"));

    QListWidgetItem *barco4 = new QListWidgetItem(ui->listWidget);
    barco4->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco4->setIcon(QIcon("navio.jpg"));
}

int MainWindow::click_btn1(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));

}

int MainWindow::click_btn2(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));

}

void MainWindow::setNumN(int num){
    numN = num;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}

