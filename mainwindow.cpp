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
    //connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),
    //        ui->progressBar,SLOT(setValue(int)));
            //connect - tworzy połączenie między widżetami
            //1. sender - wejscie
            //2. signal -
            //3. receiver - wyjście
            //4. slot -
            //disconnect - dezaktywuje połączenie
    ui->Plot1->addGraph();
    ui->Plot1->addGraph();
    ui->Plot1->graph(1)->setPen(QPen(Qt::red)); // line color red for second graph
    ui->Plot2->addGraph();
    ui->Plot2->graph(0)->setPen(QPen(Qt::green));
ui->Plot1->graph(0)->setBrush(QBrush(QColor(0, 0, 255, 20)));
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateView()));
    timer->start(1000);

}

void MainWindow::updateView()
{
    time++;
    x.push_back(time);
    y.push_back(s_ob->h);
    sp.push_back(s_pi->setpoint);

    double up = s_pi->simulate(s_ob->h, 1);
    v_u.push_back(up);
    s_ob->h = s_ob->simulate(up, 1);
    double tmp = s_ob->h;
    ui->Plot1->graph(0)->setData(x,y);
    ui->Plot1->graph(1)->setData(x,sp);
    ui->Plot1->xAxis->setLabel("x");
    ui->Plot1->yAxis->setLabel("y");
    ui->Plot1->xAxis->setRange(x.size()-50, x.size());
    //ui->Plot1->yAxis->setRange(0, 50);
    ui->Plot1->yAxis->rescale();

    ui->Plot1->replot();


    ui->Plot2->graph(0)->setData(x,v_u);
    ui->Plot2->xAxis->setLabel("x");
    ui->Plot2->yAxis->setLabel("y");
    ui->Plot2->xAxis->setRange(x.size()-50, x.size());
    ui->Plot2->yAxis->rescale();



    ui->Plot2->replot();
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

/*
void MainWindow::on_pushButton_2_clicked()
{
    // example of messege box
    // critical
    // information
    // question
    // warning
    //QMessageBox::about(this, "Myt title", "This is my custom message");
    //QMessageBox::critical(this, "My title", "My information");
    QMessageBox::StandardButton reply = QMessageBox::question(this,"My title","Question?",
                                                 QMessageBox::Yes | QMessageBox::No);
    if(reply == QMessageBox::Yes){
        QApplication::quit();
    } else{
        qDebug() <<"No is clicked";
    }
}*/


