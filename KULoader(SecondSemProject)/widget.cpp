#include "widget.h"
#include <QPixmap>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    //default constructor

    ui->setupUi(this);

      setWindowTitle("KU Loader 1.0.0");
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

        QString values[] = {"500KB/s", "1MB/s", "2MB/s", "5MB/s", "10MB/s"};
        for(int i = 0; i < 5; i++) {
            ui->controlUpload->addItem(values[i]);
            ui->controlDownload->addItem(values[i]);
        }
        ui->controlUpload->setCurrentIndex(4);
        ui->controlDownload->setCurrentIndex(4);

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

int Widget::controlUploadIndex = 4;
int Widget::controlDownloadIndex = 4;

void Widget::setControlUploadIndex(const int &value)
{
    this->controlUploadIndex = value;
}
void Widget::setControlDownloadIndex(const int &value)
{
    this->controlDownloadIndex = value;
}

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

void Widget::on_controlDownload_currentIndexChanged(int index)
{
    setControlDownloadIndex(index);
}

void Widget::on_controlUpload_currentIndexChanged(int index)
{
    setControlUploadIndex(index);
}

Widget::~Widget()
{
    //destructor
    delete ui;
}

