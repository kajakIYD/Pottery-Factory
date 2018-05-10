#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(PI *pi, obiekt *ob, QWidget *parent) :
    s_pi(pi),
    s_ob(ob),
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->Plot1->addGraph();
    ui->Plot1->addGraph();
    ui->Plot1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));   // PV
    ui->Plot1->graph(1)->setPen(QPen(Qt::red));                    //  Setpoint

    ui->Plot2->addGraph();
    ui->Plot2->graph(0)->setPen(QPen(Qt::green));                  // q

    ui->Plot3->addGraph();
    ui->Plot3->addGraph();
    ui->Plot3->graph(0)->setPen(QPen(Qt::yellow));                 // n*q
    ui->Plot3->graph(1)->setPen(QPen(Qt::magenta));                // n*q + q


    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateView()));
    timer->start(1000);

    I2C = new I2CDevice(2,5);

    frame[1] = '$';

}

void MainWindow::updateView()
{
    time++;
    x.push_back(time);                  // time vector
    y.push_back(s_ob->T);               // temperature vector
    sp.push_back(s_pi->setpoint);       // setpoint vector

    // regulator PI
    double up = s_pi->simulate(s_ob->T, 0.01);
    v_u.push_back(up);                  // q vector
    nq.push_back(up*7);                 // n*q vector
    nq_plus_q.push_back(up*7+up);       // n*q + q vector

    // s_ob->T = s_ob->simulate(up, 0.01, s_pi->setpoint);  // funkcja do symulacji obiektu

    // skalowanie Q 0-2000 -> 0-255

    frame[0] = (int)(up * 0.1275);
    frame[2] = (int)(s_pi->setpoint * 0.1275);

    cout << "Frame1: ";
    cout << (int)(frame[0]);
    cout << "\n";
    cout << "Frame2 q: ";
    cout << (int)(frame[1]);
    cout << "\n";
    cout << "Frame3 tp: ";
    cout << (int)(frame[2]);
    cout << "\n";

    int temp = I2C->readData(frame);


    s_ob->T = (double)(temp / 0.1275);
    cout << "Final value: ";
    cout << temp / 0.1275;
    cout << "\n";

    double tmp = s_ob->T;
    ui->Plot1->graph(0)->setData(x,y);
    ui->Plot1->graph(1)->setData(x,sp);
    ui->Plot1->xAxis->setLabel("time[h]");
    ui->Plot1->yAxis->setLabel("temperature[°C]");
    ui->Plot1->xAxis->setRange(x.size()-50, x.size());
    ui->Plot1->yAxis->rescale();
    ui->Plot1->graph(0)->setName("T");
    ui->Plot1->graph(1)->setName("SP");
    ui->Plot1->replot();


    ui->Plot2->graph(0)->setData(x,v_u);
    ui->Plot2->xAxis->setLabel("time[h]");
    ui->Plot2->yAxis->setLabel("q[m³/h]");
    ui->Plot2->xAxis->setRange(x.size()-50, x.size());
    ui->Plot2->yAxis->rescale();
    ui->Plot2->replot();

    ui->Plot3->graph(0)->setData(x,nq);
    ui->Plot3->graph(1)->setData(x,nq_plus_q);
    ui->Plot3->xAxis->setLabel("time[h]");
    ui->Plot3->yAxis->setLabel("q[m³/h]");
    ui->Plot3->xAxis->setRange(x.size()-50, x.size());
    ui->Plot3->yAxis->rescale();
    ui->Plot3->graph(0)->setName("n*q");
    ui->Plot3->graph(1)->setName("n*q+q");
    ui->Plot3->replot();
}




void MainWindow::on_w_changeKr_valueChanged(double arg1)
{
    s_pi->Kr = arg1;
}

void MainWindow::on_w_changeTi_valueChanged(double arg1)
{
    s_pi->Ti = arg1;
}

void MainWindow::on_w_changeMax_u_valueChanged(double arg1)
{
    s_pi->max_u = arg1;
}

void MainWindow::on_w_changeSp_valueChanged(double arg1)
{
    s_pi->setpoint = arg1;
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    timer->start(value);
}



MainWindow::~MainWindow()
{
    delete ui;
}






