#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QLabel>
#include <QFrame>
#include <QList>
#include <QMouseEvent>


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


private:
    Ui::MainWindow *ui;

    QList<int> pos_mapa1;
    QList<int> pos_mapa2;
    QList<QFrame*> frame1;
    QList<QFrame*> frame2;

private slots:
    void on_actionSair_triggered();

protected:
    void mouseReleaseEvent(QMouseEvent *event);
};


#endif // MAINWINDOW_H
