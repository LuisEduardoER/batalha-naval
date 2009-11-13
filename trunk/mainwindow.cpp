#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    numN=-1;
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

            connect(ui->listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(setNumN()));
        }
    }
}

void MainWindow::AdicionarNavios(){
    QSize tam;

    QListWidgetItem *barco1 = new QListWidgetItem(ui->listWidget);
    barco1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco1->setIcon(QIcon("navio1v.gif"));
    tam.setHeight(50);
    tam.setWidth(35);
    barco1->setSizeHint(tam);
    tam_barco.append(2);
    pos_barco.append(VERTICAL);
    num_barco.append(0);

    QListWidgetItem *barco2 = new QListWidgetItem(ui->listWidget);
    barco2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco2->setIcon(QIcon("navio2v.gif"));
    tam.setHeight(75);
    barco2->setSizeHint(tam);
    tam_barco.append(3);
    pos_barco.append(VERTICAL);
    num_barco.append(1);

    QListWidgetItem *barco3 = new QListWidgetItem(ui->listWidget);
    barco3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco3->setIcon(QIcon("navio3v.gif"));
    tam.setHeight(100);
    barco3->setSizeHint(tam);
    tam_barco.append(4);
    pos_barco.append(VERTICAL);
    num_barco.append(2);

    QListWidgetItem *barco4 = new QListWidgetItem(ui->listWidget);
    barco4->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco4->setIcon(QIcon("navio4v.gif"));
    tam.setHeight(100);
    barco4->setSizeHint(tam);
    tam_barco.append(4);
    pos_barco.append(VERTICAL);
    num_barco.append(3);

    QListWidgetItem *barco5 = new QListWidgetItem(ui->listWidget);
    barco5->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco5->setIcon(QIcon("navio5v.gif"));
    tam.setHeight(100);
    barco5->setSizeHint(tam);
    tam_barco.append(5);
    pos_barco.append(VERTICAL);
    num_barco.append(4);

    QListWidgetItem *sub = new QListWidgetItem(ui->listWidget);
    sub->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    sub->setIcon(QIcon("icon.gif"));
    tam.setHeight(30);
    tam.setWidth(30);
    sub->setSizeHint(tam);
    tam_barco.append(1);
    pos_barco.append(VERTICAL);
    num_barco.append(5);
}

int MainWindow::click_btn1(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));

    if(numN>-1){
        btn_gp1->button(num)->hide();
        ui->listWidget->takeItem(numN);
        ui->listWidget->clearSelection();
        tam_barco.takeAt(numN);
        pos_barco.takeAt(numN);
        num_barco.takeAt(numN);
        numN=-1;
    }
}

int MainWindow::click_btn2(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));

}

void MainWindow::setNumN(){
    for(int i=0; i<ui->listWidget->count(); i++){
        if(ui->listWidget->isItemSelected(ui->listWidget->item(i)))
            numN = ui->listWidget->row(ui->listWidget->item(i));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}


void MainWindow::on_radioButton_clicked()
{
    QSize tam;
    tam.setHeight(35);

    switch(num_barco.at(numN)){
        case 0: ui->listWidget->item(numN)->setIcon(QIcon("navio1.gif"));
            tam.setWidth(50);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), HORIZONTAL);
            break;
        case 1: ui->listWidget->item(numN)->setIcon(QIcon("navio2.gif"));
            tam.setWidth(75);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), HORIZONTAL);
            break;
        case 2: ui->listWidget->item(numN)->setIcon(QIcon("navio3.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), HORIZONTAL);
            break;
        case 3: ui->listWidget->item(numN)->setIcon(QIcon("navio4.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), HORIZONTAL);
            break;
        case 4: ui->listWidget->item(numN)->setIcon(QIcon("navio5.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), HORIZONTAL);
            break;
        default: break;
    }
    ui->listWidget->reset();
}

void MainWindow::on_radioButton_2_clicked()
{
    QSize tam;
    tam.setWidth(35);

    switch(num_barco.at(numN)){
        case 0: ui->listWidget->item(numN)->setIcon(QIcon("navio1v.gif"));
            tam.setHeight(50);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), VERTICAL);
            break;
        case 1: ui->listWidget->item(numN)->setIcon(QIcon("navio2v.gif"));
            tam.setHeight(75);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), VERTICAL);
            break;
        case 2: ui->listWidget->item(numN)->setIcon(QIcon("navio3v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), VERTICAL);
            break;
        case 3: ui->listWidget->item(numN)->setIcon(QIcon("navio4v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), VERTICAL);
            break;
        case 4: ui->listWidget->item(numN)->setIcon(QIcon("navio5v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(pos_barco.at(numN), VERTICAL);
            break;
        default: break;
    }
    ui->listWidget->reset();
}
