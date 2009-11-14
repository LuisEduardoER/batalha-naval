#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#define HORIZONTAL 1
#define VERTICAL 2

#define MAR -1
#define BARCO1 0
#define BARCO2 1
#define BARCO3 2
#define BARCO4 3
#define BARCO5 4
#define SUBMARINO 5

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QFrame>
#include <QList>
#include <QMouseEvent>
#include <QPushButton>
#include <QButtonGroup>
#include <QMessageBox>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void IniciaTabuleiro();
    void AdicionarNavios();
    void RemoveBarcoLista();
    bool VerificaCantoDireito(int, int);
    bool VerificaCantoInferior(int, int);
    void AddBarcoHorizontal(int);
    void AddBarcoVertical(int);

    bool VerificaJogada(int);

    void BloqueiaMapa1();
    void DesbloqueiaMapa1();
    void BloqueiaMapa2();
    void DesbloqueiaMapa2();

private:
    Ui::MainWindow *ui;

    QList<int> pos_mapa1;
    QList<int> pos_mapa2;
    QList<QPushButton*> btn_mapa1;
    QList<QPushButton*> btn_mapa2;

    QList<QFrame*> frm_mapa1;
    QList<QFrame*> frm_mapa2;

    QList<int> tam_barco;
    QList<int> pos_barco;
    QList<int> num_barco;

    QButtonGroup *btn_gp1;
    QButtonGroup *btn_gp2;

    int numN;

private slots:
    void on_radioButton_2_clicked();
    void on_radioButton_clicked();
    void on_actionSair_triggered();

public slots:
    int click_btn1(int);
    int click_btn2(int);
    void setNumN();

protected:

};


#endif // MAINWINDOW_H
