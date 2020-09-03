#include "widget.h"
#include <thread>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    if (w.threadInitialize == true){
        std::thread worker(&Widget::doDownload, w);
        worker.join();
    }
    return a.exec();
}
