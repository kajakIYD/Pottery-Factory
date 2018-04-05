#ifndef SUBJECT_H
#define SUBJECT_H

#include <iostream>
#include <vector>
#include "mainwindow.h"

class Subject
{
    std::vector<MainWindow*> obs_list;

public:
    void Attach(MainWindow *obs);
    //void Detach(MainWindow *obs);
    void Notify();
};

#endif // SUBJECT_H
