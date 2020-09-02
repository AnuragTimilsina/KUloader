#include "widget.h"
#include "ui_widget.h"
#include <QDebug>

void Widget::printInfo()
{
    qDebug() << "printInfo called";

    auto& session = aria2cpp::Session::get();

    auto ids = session.get_active_downloads();
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);

//    int index = 0;
    qDebug() << ids[0];
//    qDebug() << ids[1];
//    qDebug() << ids[2];

    for (auto id : ids) {

        auto download_handle = session.get_download_handle(id);

//        if (index < 1) {
            double size = download_handle->getTotalLength();
            ui->fileSize->setText(convertFileSize(size));
//            index++;
//        }

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

