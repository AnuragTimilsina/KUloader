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
}

unsigned long MyThread::tempID = 0;