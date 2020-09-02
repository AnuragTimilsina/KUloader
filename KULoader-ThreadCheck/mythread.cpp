#include "mythread.h"
#include "aria2cpp.h"
#include <QMutex>
//MyThread::MyThread(QObject *parent) : QObject(parent)
MyThread::MyThread()
{
}

//run will be called when the thread starts
void MyThread::run()
{
    doDownload();
    //    auto& session = aria2cpp::Session::get();
    //    auto start = std::chrono::steady_clock::now();

    //    for (int response_value = 0; (response_value = session.run()) == 1;) {

    //        QMutex mutex;

    //        //prevents other threads from changing the value of stop
    ////        mutex.lock();

    //        if(this->isStopped) break;
    //        mutex.unlock();

    //        auto now = std::chrono::steady_clock::now();
    //        auto count =
    //            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
    //                .count();
    ////        qDebug() << count;
    //        if (count >= 750) {
    //            start = now;
    //            printInfo();
    //        }
    //    }

    //    emit finished();
}
