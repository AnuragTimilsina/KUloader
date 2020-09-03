#include "mythread.h"
#include "widget.h"
#include <QMessageBox>
#include <QDebug>
void MyThread::run()
{
    doDownload();
}

MyThread::MyThread()
{
    isStopped = false;
    session = new aria2cpp::Session();
}

unsigned long MyThread::tempID = 0;
