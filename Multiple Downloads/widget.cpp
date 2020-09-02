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
    isStopped = false;
}




