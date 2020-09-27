#include "widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>
#include <thread>
#include <QTimer>
void Widget::quitClicked()
{
    qDebug() << "Quit clicked";
    QApplication::quit();
}

void Widget::browseClicked()
{
    qDebug() << "Browse clicked";
    QString path = QFileDialog::getExistingDirectory(this, "Choose Directory");

    if(path.isEmpty())
        return;
    else {
        this->directoryPath->setText(path);
        setDirectory(path.toStdString());
    }
}

void Widget::downloadClicked()
{
    qDebug() << "Download CLicked";
    bool isDirectoryValid = checkDirectory(QString::fromStdString(getDirectory()));

    if(isDirectoryValid) {
        this->downloadButton->setDisabled(true);
        thread->start();
    }
    else {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
}

void Widget::pauseClicked()
{
    qDebug() << "Pause Clicked";
    auto& session = aria2cpp::Session::get();
    int value = session.pauseDownload(thread->tempID);
    downloadSpeed->setText("0B/s");
    uploadSpeed->setText("0B/s");
    qDebug() << value;
}
void Widget::resumeClicked()
{
    qDebug() << "Resume Clicked";
    auto& session = aria2cpp::Session::get();
    int value = session.resumeDownload(thread->tempID);
    qDebug() << value;
}

void Widget::urlPathEditingFinished()
{
    this->setUrl(this->urlPath->text().toStdString());
}

void Widget::directoryPathEditingFinished()
{
    this->setDirectory(this->directoryPath->text().toStdString());
}

void Widget::fileNameEditingFinished()
{
    this->setFname(this->fileName->text().toStdString());
}

void Widget::onNumberChanged(double fileSize, double progressValue, double downSpeedInBytes, double upSpeedInBytes)
{
    this->fileSize->setText(this->convertFileSize(fileSize));

    QString convertedSpeed = this->convertSpeed(downSpeedInBytes);

    QString convertedUploadSpeed = this->convertSpeed(upSpeedInBytes);
    this->progress->setValue(progressValue);
    this->downloadSpeed->setText(convertedSpeed);

    this->uploadSpeed->setText(convertedUploadSpeed);
}

void Widget::ifIdIsOne()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
    this->downloadButton->setDisabled(false);
}

void Widget::onSuccess()
{
    this->resetWindow();
    QApplication::quit();
}

void Widget::onFailure()
{
    QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
    this->downloadButton->setDisabled(false);
    QApplication::quit();
}

void Widget::resetWindow()
{
    this->progress->setValue(100);

    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
    this->downloadButton->setDisabled(false);
    this->progress->reset();
    this->urlPath->setText("");
    this->directoryPath->setText("");
    this->fileName->setText("");
    this->fileSize->setText("");
    this->downloadSpeed->setText("");
    this->uploadSpeed->setText("");
}
