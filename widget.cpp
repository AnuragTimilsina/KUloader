#include "widget.h"
#include "ui_widget.h"
#include <aria2/aria2.h>
#include <utility>
#include <memory>
#include <QString>
#include <cstring>
#include "aria2cpp.h"
#include <QMessageBox>
#include <iostream>
#include <QUrl>
#include <QFileDialog>

//auto tempID = 0;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("KU Loader 1.0.0");
    setFixedSize(680, 295);
}

int Widget::doDownload()
{
    auto url = this->getUrl();

    const auto outputFileName = this->getFileName();
    const auto outputDirectory = this->getdirectory();

    auto& session = aria2cpp::Session::init();
    session.set_global_option({{"max-overall-download-limit", "10M"},
                              {"max-overall-upload-limit", "10M"}});

//    //the first value is response value and second is the download id
//    std::pair<int, unsigned int> values  = session.add_download(
//            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});

    auto [response_value, id] = session.add_download(
            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
//    tempID = id;
    if(id == 1){
        QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
        ui->downloadButton->setDisabled(false);
        return 0;
    }

    if (response_value < 0) {
        QMessageBox::warning(this, "ERROR MESSAGE", "Please enter valid url");
        ui->downloadButton->setDisabled(false);
        return EXIT_FAILURE;
    }
//            std::cout << "Added download. Download ID is:" << id << std::endl;

    auto start = std::chrono::steady_clock::now();
    for (response_value = 0; (response_value = session.run()) == 1;) {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
        if (count >= 100) {
            start = now;
            printInfo();
        }
    }

    resetWindow();
        return EXIT_SUCCESS;
}



void Widget::printInfo()
{
    auto& session = aria2cpp::Session::get();

    auto ids = session.get_active_downloads();
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

    int index = 0;

    for (auto id : ids) {

        auto download_handle = session.get_download_handle(id);

        if (index < 1) {
            double size = download_handle->getTotalLength();


            ui->fileSize->setText(convertFileSize(size));
            index++;
        }

        if (download_handle) {

            double value = (download_handle->getTotalLength() > 0 ?
                           (100 * download_handle->getCompletedLength() /
                            download_handle->getTotalLength()) : 0);

            double speedInBytes = download_handle->getDownloadSpeed();

            double uploadSpeedInBytes = download_handle->getUploadSpeed();

            QString convertedSpeed = convertSpeed(speedInBytes);

            QString convertedUploadSpeed = convertSpeed(uploadSpeedInBytes);
            ui->progressBar->setValue(value);

            ui->downloadSpeed->setText(convertedSpeed);

            ui->uploadSpeed->setText(convertedUploadSpeed);
        }
    }
}


void Widget::resetWindow()
{
    ui->progressBar->setValue(100);

    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
    ui->downloadButton->setDisabled(false);
    ui->progressBar->reset();
    ui->urlPath->setText("");
    ui->directoryPath->setText("");
    ui->fileName->setText("");
    ui->fileSize->setText("");
    ui->downloadSpeed->setText("");
    ui->uploadSpeed->setText("");
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_downloadButton_clicked()
{
    bool isDirectoryValid = checkDirectory(QString::fromStdString(getdirectory()));
    if(isDirectoryValid) {
        ui->downloadButton->setDisabled(true);
        doDownload();
    }
    else {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
}

void Widget::on_quitButton_clicked()
{
    QApplication::quit();
}

void Widget::on_urlPath_editingFinished()
{

    this->setUrl(ui->urlPath->text().toStdString());

}

void Widget::on_urlPath_textChanged(const QString &arg1)
{
    this->setUrl(arg1.toStdString());
}

void Widget::on_fileName_editingFinished()
{
    this->setFileName(ui->fileName->text().toStdString());
}

void Widget::on_fileName_textChanged(const QString &arg1)
{
    this->setFileName(arg1.toStdString());
}



void Widget::on_browseButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Choose Directory");

    if(path.isEmpty()) {
        return;
    }
    else {

    ui->directoryPath->setText(path);
    }
}

void Widget::on_directoryPath_editingFinished()
{
    this->setDirectory(ui->directoryPath->text().toStdString());
}


void Widget::on_directoryPath_textChanged(const QString &arg1)
{
    this->setDirectory(arg1.toStdString());
}



void Widget::on_pauseButton_clicked()
{

}

void Widget::on_resumeButton_clicked()
{

}
