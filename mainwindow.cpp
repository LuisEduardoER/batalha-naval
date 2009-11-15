#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    numN=-1;
    IniciaTabuleiro();
    AdicionarNavios();
    BloqueiaMapa2();
}

void MainWindow::IniciaTabuleiro(){
    chat = new Chat();
    ui->horizontalLayout_2->addWidget(chat,Qt::AlignRight);

    btn_gp1 = new QButtonGroup();
    btn_gp2 = new QButtonGroup();
    int cont=0;
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            pos_mapa1.append(MAR);
            pos_mapa2.append(MAR);

            QPushButton *btn1 = new QPushButton();
            QPushButton *btn2 = new QPushButton();

            QFrame *frm1 = new QFrame();
            QFrame *frm2 = new QFrame();

            frm1->setFrameShape(QFrame::Panel);
            frm1->setFrameShadow(QFrame::Plain);
            frm1->setStyleSheet("background: grey");
            ui->gridLayout->addWidget(frm1, i, j);

            frm2->setFrameShape(QFrame::Panel);
            frm2->setFrameShadow(QFrame::Plain);
            frm2->setStyleSheet("background: grey");
            ui->gridLayout_3->addWidget(frm2, i, j);

            frm_mapa1.append(frm1);
            frm_mapa2.append(frm2);

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

            ui->radioButton_2->setChecked(true);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);

        }
    }
    connect(ui->listWidget, SIGNAL(clicked(QModelIndex)), this, SLOT(setNumN()));
    connect(btn_gp1, SIGNAL(buttonClicked(int)),this, SLOT(click_btn1(int)));
    connect(btn_gp2, SIGNAL(buttonClicked(int)),this, SLOT(click_btn2(int)));
}

void MainWindow::AdicionarNavios(){
    qtdBarco=0;
    QSize tam;

    QListWidgetItem *barco1 = new QListWidgetItem(ui->listWidget);
    barco1->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco1->setIcon(QIcon("navio1v.gif"));
    tam.setHeight(50);
    tam.setWidth(35);
    barco1->setSizeHint(tam);
    tam_barco.append(2);
    pos_barco.append(VERTICAL);
    num_barco.append(BARCO1);
    qtdBarco++;

    QListWidgetItem *barco2 = new QListWidgetItem(ui->listWidget);
    barco2->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco2->setIcon(QIcon("navio2v.gif"));
    tam.setHeight(75);
    barco2->setSizeHint(tam);
    tam_barco.append(3);
    pos_barco.append(VERTICAL);
    num_barco.append(BARCO2);
    qtdBarco++;

    QListWidgetItem *barco3 = new QListWidgetItem(ui->listWidget);
    barco3->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco3->setIcon(QIcon("navio3v.gif"));
    tam.setHeight(100);
    barco3->setSizeHint(tam);
    tam_barco.append(4);
    pos_barco.append(VERTICAL);
    num_barco.append(BARCO3);
    qtdBarco++;

    QListWidgetItem *barco4 = new QListWidgetItem(ui->listWidget);
    barco4->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco4->setIcon(QIcon("navio4v.gif"));
    tam.setHeight(100);
    barco4->setSizeHint(tam);
    tam_barco.append(4);
    pos_barco.append(VERTICAL);
    num_barco.append(BARCO4);
    qtdBarco++;

    QListWidgetItem *barco5 = new QListWidgetItem(ui->listWidget);
    barco5->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    barco5->setIcon(QIcon("navio5v.gif"));
    tam.setHeight(100);
    barco5->setSizeHint(tam);
    tam_barco.append(5);
    pos_barco.append(VERTICAL);
    num_barco.append(BARCO5);
    qtdBarco++;


    QListWidgetItem *sub = new QListWidgetItem(ui->listWidget);
    sub->setFlags(Qt::ItemIsSelectable | Qt::ItemIsEnabled);
    sub->setIcon(QIcon("icon.gif"));
    tam.setHeight(30);
    tam.setWidth(30);
    sub->setSizeHint(tam);
    tam_barco.append(1);
    pos_barco.append(VERTICAL);
    num_barco.append(SUBMARINO);
}

void MainWindow::click_btn1(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));

    if(numN>-1){
        if(pos_barco.at(numN)==HORIZONTAL){
            if(VerificaCantoDireito(num, tam_barco.at(numN))){
                AddBarcoHorizontal(num);
                RemoveBarcoLista();
            }
        } else if(pos_barco.at(numN)==VERTICAL){
            if(VerificaCantoInferior(num, tam_barco.at(numN))){
                AddBarcoVertical(num);
                RemoveBarcoLista();
            }
        }

    }
}

void MainWindow::click_btn2(int pos){
    int num = btn_gp1->id(btn_gp1->button(pos));
    if(VerificaJogada(pos)==false){
        btn_gp2->button(pos)->hide();
        frm_mapa2.at(pos)->setStyleSheet("");
        //BloqueiaMapa2();
    }
}

void MainWindow::setNumN(){
    for(int i=0; i<ui->listWidget->count(); i++){
        if(ui->listWidget->isItemSelected(ui->listWidget->item(i))){
            numN = ui->listWidget->row(ui->listWidget->item(i));
            if(pos_barco.at(numN)==HORIZONTAL)
                ui->radioButton->setChecked(true);
            else
                ui->radioButton_2->setChecked(true);
        }
    }
    ui->radioButton->setEnabled(true);
    ui->radioButton_2->setEnabled(true);
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
            pos_barco.replace(num_barco.at(numN), HORIZONTAL);
            break;
        case 1: ui->listWidget->item(numN)->setIcon(QIcon("navio2.gif"));
            tam.setWidth(75);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), HORIZONTAL);
            break;
        case 2: ui->listWidget->item(numN)->setIcon(QIcon("navio3.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), HORIZONTAL);
            break;
        case 3: ui->listWidget->item(numN)->setIcon(QIcon("navio4.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), HORIZONTAL);
            break;
        case 4: ui->listWidget->item(numN)->setIcon(QIcon("navio5.gif"));
            tam.setWidth(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), HORIZONTAL);
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
            pos_barco.replace(num_barco.at(numN), VERTICAL);
            break;
        case 1: ui->listWidget->item(numN)->setIcon(QIcon("navio2v.gif"));
            tam.setHeight(75);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), VERTICAL);
            break;
        case 2: ui->listWidget->item(numN)->setIcon(QIcon("navio3v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), VERTICAL);
            break;
        case 3: ui->listWidget->item(numN)->setIcon(QIcon("navio4v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), VERTICAL);
            break;
        case 4: ui->listWidget->item(numN)->setIcon(QIcon("navio5v.gif"));
            tam.setHeight(100);
            ui->listWidget->item(numN)->setSizeHint(tam);
            pos_barco.replace(num_barco.at(numN), VERTICAL);
            break;
        default: break;
    }
    ui->listWidget->reset();
}

void MainWindow::RemoveBarcoLista(){
        ui->listWidget->takeItem(numN);
        ui->listWidget->clearSelection();
        tam_barco.takeAt(numN);
        pos_barco.takeAt(numN);
        num_barco.takeAt(numN);
        numN=-1;
        if(ui->listWidget->count()==0){
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);
            BloqueiaMapa1();
            DesbloqueiaMapa2();
        }

}

bool MainWindow::VerificaCantoDireito(int posAtu, int tam){
    int aux;
    for(aux=posAtu; aux>10; aux=aux-10);
    if((aux+tam-1)<10){
        for(int i=0; i<tam; i++){
            if(pos_mapa1.at(posAtu+i)!=MAR)
                return(false);
        }
        return(true);
    }
    else
        return(false);
}

bool MainWindow::VerificaCantoInferior(int posAtu, int tam){
    int aux = posAtu;
    if((aux+(tam-1)*10)<100){
        for(int i=0; i<tam; i++){
            if(pos_mapa1.at(aux+i*10)!=MAR)
                return(false);
        }
        return(true);
    }
    else
        return(false);
}

void MainWindow::AddBarcoHorizontal(int pos){
    switch(tam_barco.at(numN)){
                case 1:
                    btn_gp1->button(pos)->hide();
                    pos_mapa1.replace(pos, SUBMARINO);
                    break;
                case 2:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+1)->hide();
                    pos_mapa1.replace(pos, BARCO1);
                    pos_mapa1.replace(pos+1, BARCO1);
                    break;
                case 3:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+1)->hide();
                    btn_gp1->button(pos+2)->hide();
                    pos_mapa1.replace(pos, BARCO2);
                    pos_mapa1.replace(pos+1, BARCO2);
                    pos_mapa1.replace(pos+2, BARCO2);
                    break;
                case 4:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+1)->hide();
                    btn_gp1->button(pos+2)->hide();
                    btn_gp1->button(pos+3)->hide();
                    if(num_barco.at(numN)==BARCO3){
                        pos_mapa1.replace(pos, BARCO3);
                        pos_mapa1.replace(pos+1, BARCO3);
                        pos_mapa1.replace(pos+2, BARCO3);
                        pos_mapa1.replace(pos+3, BARCO3);
                    }
                    else{
                        pos_mapa1.replace(pos, BARCO4);
                        pos_mapa1.replace(pos+1, BARCO4);
                        pos_mapa1.replace(pos+2, BARCO4);
                        pos_mapa1.replace(pos+3, BARCO4);
                    }
                    break;
                case 5:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+1)->hide();
                    btn_gp1->button(pos+2)->hide();
                    btn_gp1->button(pos+3)->hide();
                    btn_gp1->button(pos+4)->hide();
                    pos_mapa1.replace(pos, BARCO5);
                    pos_mapa1.replace(pos+1, BARCO5);
                    pos_mapa1.replace(pos+2, BARCO5);
                    pos_mapa1.replace(pos+3, BARCO5);
                    pos_mapa1.replace(pos+4, BARCO5);
                    break;

    }
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
}

void MainWindow::AddBarcoVertical(int pos){
    switch(tam_barco.at(numN)){
                case 1:
                    btn_gp1->button(pos)->hide();
                    pos_mapa1.replace(pos, SUBMARINO);
                    break;
                case 2:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+10)->hide();
                    pos_mapa1.replace(pos, BARCO1);
                    pos_mapa1.replace(pos+10, BARCO1);
                    break;
                case 3:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+10)->hide();
                    btn_gp1->button(pos+20)->hide();
                    pos_mapa1.replace(pos, BARCO2);
                    pos_mapa1.replace(pos+10, BARCO2);
                    pos_mapa1.replace(pos+20, BARCO2);
                    break;
                case 4:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+10)->hide();
                    btn_gp1->button(pos+20)->hide();
                    btn_gp1->button(pos+30)->hide();
                    if(num_barco.at(numN)==BARCO3){
                        pos_mapa1.replace(pos, BARCO3);
                        pos_mapa1.replace(pos+10, BARCO3);
                        pos_mapa1.replace(pos+20, BARCO3);
                        pos_mapa1.replace(pos+30, BARCO3);
                    }
                    else{
                        pos_mapa1.replace(pos, BARCO4);
                        pos_mapa1.replace(pos+10, BARCO4);
                        pos_mapa1.replace(pos+20, BARCO4);
                        pos_mapa1.replace(pos+30, BARCO4);
                    }
                    break;
                case 5:
                    btn_gp1->button(pos)->hide();
                    btn_gp1->button(pos+10)->hide();
                    btn_gp1->button(pos+20)->hide();
                    btn_gp1->button(pos+30)->hide();
                    btn_gp1->button(pos+40)->hide();
                    pos_mapa1.replace(pos, BARCO5);
                    pos_mapa1.replace(pos+10, BARCO5);
                    pos_mapa1.replace(pos+20, BARCO5);
                    pos_mapa1.replace(pos+30, BARCO5);
                    pos_mapa1.replace(pos+40, BARCO5);
                    break;

    }
    ui->radioButton->setEnabled(false);
    ui->radioButton_2->setEnabled(false);
}

bool MainWindow::VerificaJogada(int pos){

    if(pos>-1 && pos <100){
        int aux = pos_mapa1.at(pos);
        if(aux==MAR)
            return(false);
        else{
            btn_mapa2.at(pos)->hide();
            frm_mapa1.at(pos)->setStyleSheet("background-image: url(explodido.gif)");
            pos_mapa1.replace(pos, aux+BARCOATINGIDO);
            for(int i=0; i<100; i++){
                if(pos_mapa1.at(i)==aux){
                    return(true); // ainda existe navio X
                }
            }

            if((pos+10)<100)
                if(pos_mapa1.at(pos+10)==aux+BARCOATINGIDO){
                    NaufragarEmbarcacao(aux);
                    return(true);
                }
            if((pos-10)>-1)
                if(pos_mapa1.at(pos-10)==aux+BARCOATINGIDO){
                    NaufragarEmbarcacao(aux);
                    return(true);
                }

            int auxPos;
            for(auxPos=pos; auxPos>10; auxPos=auxPos-10);
            if((auxPos+1)<10)
                if(pos_mapa1.at(pos+1)==aux+BARCOATINGIDO){
                    NaufragarEmbarcacao(aux);
                    return(true);
                }
            if((auxPos-1)>-1)
                if(pos_mapa1.at(pos-1)==aux+BARCOATINGIDO){
                    NaufragarEmbarcacao(aux);
                    return(true);
                }
            //se passar por todos os ifs quer dizer que entao é um submarino
            pos_mapa1.replace(pos, MAR);
            return(true);
        }
    }
    return(true);
}

void MainWindow::BloqueiaMapa1(){
    for(int i=0; i< btn_mapa1.count(); i++)
                btn_mapa1.at(i)->setEnabled(false);
}

void MainWindow::DesbloqueiaMapa1(){
    for(int i=0; i< btn_mapa1.count(); i++)
                btn_mapa1.at(i)->setEnabled(true);
}

void MainWindow::BloqueiaMapa2(){
    for(int i=0; i< btn_mapa2.count(); i++)
                btn_mapa2.at(i)->setEnabled(false);
}

void MainWindow::DesbloqueiaMapa2(){
    for(int i=0; i< btn_mapa2.count(); i++)
                btn_mapa2.at(i)->setEnabled(true);
}

void MainWindow::NaufragarEmbarcacao(int barco){
    for(int i=0; i<100; i++)
                if(pos_mapa1.at(i)==barco+BARCOATINGIDO)
                    pos_mapa1.replace(barco, MAR);
    qtdBarco--;
    QMessageBox msg;
    msg.setText("Um navio foi afundado!");
    msg.exec();
    if(VerificaFim()){
        BloqueiaMapa1();
        BloqueiaMapa2();
        msg.setText("Fim de Jogo!");
        msg.exec();
    }
}

bool MainWindow::VerificaFim(){
    if(qtdBarco==0)
        return(true);
    else
        return(false);
}


void MainWindow::on_actionConectar_triggered()
{
    frmConexao *conexao = new frmConexao();
    if(conexao->exec()){
        port=conexao->con->port();
        host=conexao->con->host();
        tipo_conexao=conexao->con->tipo_conexao;
        server = new Servidor();
        cliente = new Socket();
        init();
        run();
    }
}

void MainWindow::init(){
    if(tipo_conexao==CLIENTE){
        this->cliente->init();
        this->chat->show();
    }
    else {
        this->server->init();
        this->chat->show();
    }
}


void MainWindow::run(){
    if(tipo_conexao==CLIENTE){
        connect (this->chat, SIGNAL(EnviarMensagem()), this, SLOT(EnviarMensagem()));
        connect (this->cliente->socket, SIGNAL(readyRead()), this, SLOT(LerMensagem()));
    }
    else{
        connect (this->chat, SIGNAL(EnviarMensagem()), this, SLOT(EnviarMensagem()));
        while(this->server->cliente ==0);
        if(this->server->cliente != 0){
            qDebug("tomo no cu");
            connect (this->server->cliente, SIGNAL(readyRead()), this, SLOT(LerMensagem()));
        }
    }
}

void MainWindow::LerMensagem(){
    if(tipo_conexao==CLIENTE){
        QString msg;
        msg = this->cliente->LerMensagem();
        qDebug()<<msg;
        this->chat->adicionarAConversa(msg);
    }
    else{
        QString msg;
        msg = this->server->LerMensagem();
        qDebug()<<msg;
        this->chat->adicionarAConversa(msg);
    }
}

void MainWindow::EnviarMensagem(){
    if(tipo_conexao==CLIENTE){
        QString msg;
        msg = this->chat->getMensagem();
        this->chat->clearMensagem();
        this->cliente->EnviarMensagem(msg);
        this->chat->adicionarAConversa(msg);
    }
    else{
        QString msg;
        msg = this->chat->getMensagem();
        this->chat->clearMensagem();
        this->server->EnviarMensagem(msg);
        this->chat->adicionarAConversa(msg);
        qDebug()<<msg;
    }
}

