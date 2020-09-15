#include "widget.h"

#include <QApplication>
#include <thread>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    std::unique_ptr<QSplashScreen> splash(new QSplashScreen);
    QSplashScreen *splash = new QSplashScreen;
    splash->setPixmap(QPixmap("/home/saskar/Documents//splashscreen.jpg"));
    splash->show();

    Widget w;

    //whats happening in Qtimer is that as soon as the 1st qtimer is executed, the second qtimer
    //is also executed. So giving them same time basically means that as soon as the splash screeen
    //is closed, our main window is opened.

    // singleShot = ?

    //we will show the splash screen for 3sec time and then we will show our main window
    QTimer::singleShot(3000, splash, SLOT(close()));

    //after 3s after splashscreen is shown our mainwindwow will show
    QTimer::singleShot(3000, &w, SLOT(show()));

//    w.show();
//    std::thread worker(&Widget::doDownload, w);
//    if(w.isStopped) worker.join();
    return a.exec();
}
