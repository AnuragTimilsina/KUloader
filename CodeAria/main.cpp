#include "widget.h"

#include <QApplication>
#include <QSplashScreen>
#include <QTimer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSplashScreen *splash = new QSplashScreen;
//    std::unique_ptr<QSplashScreen> splash (new QSplashScreen);  cannot do this
    splash->setPixmap(QPixmap("/home/saskar/Documents/splashscreen.jpg"));
    splash->show();

    Widget w;
    QTimer::singleShot(3000, splash, SLOT(close()));


    QTimer::singleShot(3000, &w, SLOT(show()));

//    w.show();
    return a.exec();
}
