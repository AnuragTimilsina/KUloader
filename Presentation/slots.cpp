#include "widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <QUrl>
#include <QDesktopServices>

void Widget::on_downloadsButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void Widget::on_homeButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::on_aboutButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Widget::on_exploreButton_clicked()
{
    QString link = "https://github.com/AnuragTimilsina/KUloader";
    QDesktopServices::openUrl(QUrl(link));
}

void Widget::on_quitButton_clicked()
{
    qDebug() << "Quit clicked";
    delete thread;
    QApplication::quit();
}

void Widget::on_browseButton_clicked()
{
    qDebug() << "Browse clicked";
    QString path = QFileDialog::getExistingDirectory(this, "Choose Directory");

    if(path.isEmpty())
        return;
    else {
        ui->directory->setText(path);
        setDirectory(path.toStdString());
    }
}

void Widget::on_downloadButton_clicked()
{
    qDebug() << "Download Clicked";
    try {
        checkDirectory(QString::fromStdString(getDirectory()));
        if(this->url.substr(0, 5).compare("https")) {
            QMessageBox msgBox;
            msgBox.setWindowTitle("NOT SECURE");
            msgBox.setText("Your website is not secure");
            msgBox.setInformativeText("Do you wish to continue?");
            msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
            msgBox.setDefaultButton(QMessageBox::No);
            int response = msgBox.exec();
            switch (response) {
                case QMessageBox::Yes:
                    this->isSecured = true;
                    break;
                case QMessageBox::No:
                    this->isSecured = false;
                    return;
                    break;
                default:
                    break;
            }
        }
        ui->downloadButton->setDisabled(true);
        thread->start();
        ui->stackedWidget->setCurrentIndex(1);

    }
    catch(const int &i) {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
    catch(const char* error) {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is empty.\nPlease enter a valid path", QMessageBox::Ok);
    }
}


void Widget::on_urlPath_editingFinished()
{
    this->setUrl(ui->urlPath->text().toStdString());
}

void Widget::on_directory_editingFinished()
{
    this->setDirectory(ui->directory->text().toStdString());
}

void Widget::on_fileName_editingFinished()
{
    this->setFname(ui->fileName->text().toStdString());
}

void Widget::onNumberChanged(double fileSize, double progressValue, double downSpeedInBytes, double upSpeedInBytes)
{
    ui->fileSize->setText(this->convertFileSize(fileSize));

    QString convertedSpeed = this->convertSpeed(downSpeedInBytes);

    QString convertedUploadSpeed = this->convertSpeed(upSpeedInBytes);
    ui->progressBar->setValue(progressValue);
    ui->downloadSpeed->setText(convertedSpeed);

    ui->uploadSpeed->setText(convertedUploadSpeed);
}

void Widget::ifIdIsOne()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
    ui->downloadButton->setDisabled(false);
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::onSuccess()
{
    this->resetWindow();
    ui->stackedWidget->setCurrentIndex(0);
}
void Widget::onFailure()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
    ui->downloadButton->setDisabled(false);
    ui->stackedWidget->setCurrentIndex(0);
}

void Widget::resetWindow()
{
    ui->progressBar->setValue(100);

    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
    ui->downloadButton->setDisabled(false);
    ui->progressBar->reset();
    ui->urlPath->setText("");
    ui->directory->setText("");
    ui->fileName->setText("");
    ui->fileSize->setText("");
    ui->downloadSpeed->setText("");
    ui->uploadSpeed->setText("");
    setUrl("");
    setDirectory("");
    setFname("");
}
