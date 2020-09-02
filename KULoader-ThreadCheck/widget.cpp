#include "widget.h"
#include "ui_widget.h"
#include <QString>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("KU Loader 1.0.0");
    setFixedSize(680, 295);
}

Widget::~Widget()
{
    delete ui;
}

uint64_t Widget::tempID = 0;

