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

    QPixmap backGround("/home/saskar/Desktop/ima80-1.jpg");
    backGround = backGround.scaled(this->size(), Qt::IgnoreAspectRatio);

    QPalette palette;
    palette.setBrush(QPalette::Window, backGround);
    this->setPalette(palette);
//    setStyleSheet("*{background-image:url(\"/home/saskar/Desktop/ima80-1.jpg\");}");
    initUi();
}

Widget::~Widget()
{
//    QLabel *label1;
//    QLabel *label2;
//    QLabel *label3;
//    QLabel *label4;
//    QLabel *label5;
//    QLabel *label6;
//    QLabel *label7;
//    QLineEdit *urlPath;
//    QLineEdit *directoryPath;
//    QLineEdit *fileName;
//    QLineEdit *fileSize;
//    QLineEdit *downloadSpeed;
//    QLineEdit *uploadSpeed;
//    QPushButton *browseButton;
//    QPushButton *quitButton;
//    QPushButton *downloadButton;
//    QPushButton *pauseButton;
//    QPushButton *resumeButton;
//    QProgressBar *progress;
//    QHBoxLayout *urlLayout;
//    QHBoxLayout *dirLayout;
//    QHBoxLayout *progressLayout;
//    QHBoxLayout *fileNameLayout;
//    QHBoxLayout *buttonsLayout;
//    QHBoxLayout *downloadDetails;
//    QFormLayout *formLayout;
}



