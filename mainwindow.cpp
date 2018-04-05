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
    ui->Plot1->graph(0)->setPen(QPen(Qt::blue));
    ui->Plot1->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    ui->Plot1->yAxis->scaleRange(0,10);
    ui->Plot2->addGraph();
    ui->Plot2->graph(0)->setPen(QPen(Qt::green));
    ui->Plot1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    ui->Plot1->xAxis->setLabel("t");
    ui->Plot1->yAxis->setLabel("y");
    ui->Plot2->xAxis->setLabel("t");
    ui->Plot2->yAxis->setLabel("u");
    ui->Plot1->yAxis->setRange(0, 30);
    ui->Plot1->xAxis->setRange(0, 50);
    ui->Plot1->replot();
    ui->Plot2->yAxis->setRange(0, 30);
    ui->Plot2->xAxis->setRange(0, 50);
    ui->Plot2->replot();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateView()));
    timer->start(1000);
}

void MainWindow::updateView()
{
    if (start)
    {
        time++;
        x.push_back(time);
        y.push_back(s_ob->h);
        sp.push_back(s_pi->setpoint);

        double up = s_pi->simulate(s_ob->h, 0.1);
        v_u.push_back(up);
        s_ob->h = s_ob->simulate(up, 0.1, s_pi->setpoint);
        double tmp = s_ob->h;
        ui->Plot1->graph(0)->setData(x,y);
        ui->Plot1->graph(1)->setData(x,sp);
        ui->Plot1->xAxis->setLabel("x");
        ui->Plot1->yAxis->setLabel("y");
        ui->Plot1->xAxis->setRange(x.size()-50, x.size());

        ui->Plot1->replot();
        ui->Plot1->yAxis->rescale();

        ui->Plot2->graph(0)->setData(x,v_u);
        ui->Plot2->xAxis->setLabel("x");
        ui->Plot2->yAxis->setLabel("y");
        ui->Plot2->xAxis->setRange(x.size()-50, x.size());
        ui->Plot2->yAxis->rescale();

        ui->Plot2->replot();
    }
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


void MainWindow::on_pushButton_clicked()
{
    start = !(start);
}
