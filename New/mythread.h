#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "aria2cpp.h"
class MyThread : public QThread
{
    Q_OBJECT
    void run() override;
public:
    MyThread();
    int doDownload();
    int printInfo();
    bool isStopped;
    static unsigned long tempID;
signals:
    void numberChanged(double, double, double, double);
    void idIsOne();
    void success();
    void failure();

};

#endif // MYTHREAD_H