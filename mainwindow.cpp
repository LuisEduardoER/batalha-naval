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
    btn_gp2 = new QButtonGroup();
    int cont=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            pos_mapa1.append(0);
            pos_mapa2.append(0);

            QFrame *frm1 = new QFrame();
            QPushButton *btn2 = new QPushButton();

            btn2->setMinimumSize(36, 36);
            frm1->setFrameShape(QFrame::Panel);
            frm1->setFrameShadow(QFrame::Plain);


            frm_mapa1.append(frm1);
            btn_mapa2.append(btn2);

            ui->gridLayout->addWidget(frm1, i, j);
            ui->gridLayout_3->addWidget(btn2, i, j);

            btn_gp2->addButton(btn2);
            btn_gp2->setId(btn2, cont++);

            connect(btn_gp2, SIGNAL(buttonClicked(int)),this, SLOT(click_btn2(int)));
        }
    }
}

void MainWindow::AdicionarNavios(){
    QListWidgetItem *barco1 = new QListWidgetItem(ui->listWidget);
    barco1->setIcon(QIcon("navio.jpg"));
}


int MainWindow::click_btn2(int pos){
    int num = btn_gp2->id(btn_gp2->button(pos));

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSair_triggered()
{
    this->close();
}

