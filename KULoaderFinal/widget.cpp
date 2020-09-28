#include "widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //default constructor

    ui->setupUi(this);

      setWindowTitle("KU Loader 1.0.0");
//          setFixedSize(1500,800);
       QPixmap pix(":/image/logo.png");
       QPixmap pix1(":/image/about.png");

        int w = ui->logo->width();
        int h = ui->logo->height();
        ui->logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        ui->logo2->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        ui->about->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
        ui->homeButton->setIcon(QIcon(":/image/house.png"));
        ui->downloadsButton->setIcon(QIcon(":/image/download.png"));
        ui->aboutButton->setIcon(QIcon(":/image/info.png"));

    thread = new MyThread;

    connect(thread, SIGNAL(numberChanged(double, double, double, double)),
            this, SLOT(onNumberChanged(double, double, double, double)));
    connect(thread, SIGNAL(idIsOne()), this, SLOT(ifIdIsOne()));
    connect(thread, SIGNAL(success()), this, SLOT(onSuccess()));
    connect(thread, SIGNAL(failure()), this, SLOT(onFailure()));
}

std::string Widget::url = "";
std::string Widget::directory = "";
std::string Widget::fname = "";

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
    //destructor
    delete ui;
}











