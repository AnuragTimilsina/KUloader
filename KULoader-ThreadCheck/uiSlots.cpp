#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QFileDialog>
#include <pthread.h>
#include <thread>
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

void Widget::on_directoryPath_editingFinished()
{
    this->setDirectory(ui->directoryPath->text().toStdString());
}

void Widget::on_directoryPath_textChanged(const QString &arg1)
{
    this->setDirectory(arg1.toStdString());
}

void Widget::on_downloadButton_clicked()
{

    bool isDirectoryValid = checkDirectory(QString::fromStdString(getdirectory()));
    if(isDirectoryValid) {
        ui->downloadButton->setDisabled(true);
        doDownload();
//        std::thread worker(doDownload());
//        if(this->isStopped == true) {
//            worker.join();
//        }

    }
    else {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
}

void Widget::on_browseButton_clicked()
{
    QString path = QFileDialog::getExistingDirectory(this, "Choose Directory");

    if(path.isEmpty()) {
        return;
    }
    else {
//    this->setDirectory(path.toStdString());
    ui->directoryPath->setText(path);
    }
}

void Widget::on_pauseButton_clicked()
{

}

void Widget::on_resumeButton_clicked()
{

}
