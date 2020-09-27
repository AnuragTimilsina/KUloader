#include "widget.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>
#include <QProgressBar>
#include <QLineEdit>
#include <QApplication>
#include <QFileDialog>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("KU Loader 1.0.0");
    setFixedSize(700,280);

    initUi();

    thread = new MyThread;

    connect(thread, SIGNAL(numberChanged(double, double, double, double)),
            this, SLOT(onNumberChanged(double, double, double, double)));
    connect(thread, SIGNAL(idIsOne()), this, SLOT(ifIdIsOne()));
    connect(thread, SIGNAL(success()), this, SLOT(onSuccess()));
    connect(thread, SIGNAL(failure()), this, SLOT(onFailure()));

    QPixmap backGround("/home/saskar/Desktop/index.jpeg");
    backGround = backGround.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, backGround);
    this->setPalette(palette);
//    setStyleSheet("*{background-image:url(\"/home/saskar/Desktop/ima80-1.jpg\");}");

}

std::string Widget::fname = "";
std::string Widget::url = "";
std::string Widget::directory = "";

void Widget::setUrl(const std::string &value)
{
    this->url = value;
}

std::string Widget::getDirectory() const
{
    return this->directory;
}

void Widget::setDirectory(const std::string &value)
{
    this->directory = value;
}

void Widget::setFname(const std::string &value)
{
    this->fname = value;
}


Widget::~Widget()
{
    delete label;
    delete label1;
    delete label2;
    delete label3;
    delete label4;
    delete label5;
    delete label6;
    delete label7;
    delete urlPath;
    delete directoryPath;
    delete fileName;
    delete fileSize;
    delete downloadSpeed;
    delete uploadSpeed;
    delete browseButton;
    delete quitButton;
    delete downloadButton;
    delete pauseButton;
    delete resumeButton;
    delete progress;
    delete urlLayout;
    delete dirLayout;
    delete progressLayout;
    delete fileNameLayout;
    delete buttonsLayout;
    delete downloadDetails;
    delete formLayout;
}
