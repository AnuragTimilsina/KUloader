#include "widget.h"
#include <QDebug>
#include <QFileDialog>
#include <QApplication>
#include <QMessageBox>

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
    bool isDirectoryValid = checkDirectory(QString::fromStdString(getDirectory()));

    if(isDirectoryValid) {
        this->downloadButton->setDisabled(true);
        //doDownload();
        threadInitialize = true;
    }
    else {
        QMessageBox::warning(this, "ERROR MESSAGE", "Your directory path is invalid.\nPlease enter a valid path", QMessageBox::Ok);
    }
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
