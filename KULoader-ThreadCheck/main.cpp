#include "widget.h"
#include <QApplication>
#include <thread>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    std::thread worker(&Widget::doDownload, w);
    if(w.isStopped == true)
        worker.join();
    return a.exec();
}
