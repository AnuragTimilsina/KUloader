#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include "aria2cpp.h"
#include <QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
//    explicit MyThread(QObject *parent = nullptr);
    MyThread();
    void run();

    bool isStopped;
    bool isPaused;

    void printInfo();
    int doDownload();
signals:
void valueChanged(double, double, double, double);

bool finished();

};

#endif // MYTHREAD_H
