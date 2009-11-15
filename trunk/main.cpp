#include <QtGui/QApplication>
#include "mainwindow.h"
#include "Jogador.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //Jogador player;
    //player.init();
    //player.start();
    w.show();
    return a.exec();
}
