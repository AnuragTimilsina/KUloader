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
}

std::string Widget::fname = "";
std::string Widget::url = "";
std::string Widget::directory = "";
//QProgressBar* Widget::progress = nullptr;
//QPushButton* Widget::downloadButton = nullptr;
//QLineEdit* Widget::urlPath = nullptr;
//QLineEdit* Widget::directoryPath = nullptr;
//QLineEdit* Widget::fileName = nullptr;
//QLineEdit* Widget::fileSize = nullptr;
//QLineEdit* Widget::downloadSpeed = nullptr;
//QLineEdit* Widget::uploadSpeed = nullptr;
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



