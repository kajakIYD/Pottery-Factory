#include "mainwindow.h"
#include <QApplication>
#include "pi.h"
#include "obiekt.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PI *pi = new PI(1,0,0,0);
    obiekt *ob = new obiekt();
    MainWindow w(pi,ob);
    w.show();
    w.setFixedSize(480,272);



    return a.exec();
}
