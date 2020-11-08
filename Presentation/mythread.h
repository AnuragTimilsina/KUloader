#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "aria2cpp.h"
class MyThread : public QThread
{
    Q_OBJECT  
    void run();

private:
    aria2cpp::Session *session;
public:
    MyThread() {}
    ~MyThread();
    int doDownload();
    int printInfo(aria2cpp::Session*);

signals:
    void numberChanged(double, double, double, double);
    void idIsOne();
    void success();
    void failure();

};

#endif // MYTHREAD_H
