#include "mainwindow.h"
#include <QApplication>
#include "pi.h"
#include "obiekt.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PI *pi = new PI(1,0,0,0);
    obiekt *ob = new obiekt(20, 0.8);
    MainWindow w(pi,ob);
    w.show();



    return a.exec();
}
