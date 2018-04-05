#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "observer.h"
#include "qcustomplot.h"
#include "pi.h"
#include "obiekt.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow, public observer
{
    Q_OBJECT

public:
    explicit MainWindow(PI *pi, obiekt *ob, QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updateView();

    void on_w_changeKr_valueChanged(double arg1);

    void on_w_changeTi_valueChanged(double arg1);

    void on_w_changeMax_u_valueChanged(double arg1);

    void on_w_changeSp_valueChanged(double arg1);

    void on_horizontalSlider_valueChanged(int value);

private:
    QTimer *timer;
    PI *s_pi;
    obiekt *s_ob;

    QVector<double> x;
    QVector<double> y;
    QVector<double> sp;
    QVector<double> v_u;
    int time = 0;

public:

    //void Update(QVector<double> x, QVector<double> y);

    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
