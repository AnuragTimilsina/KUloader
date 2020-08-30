#include "widget.h"
#include <QDebug>
#include "aria2cpp.h"

void Widget::printInfo()
{
    qDebug() << "Print Info Called";
    auto& session = aria2cpp::Session::get();

    auto ids = session.get_active_downloads();

    for (auto id : ids) {
        qDebug() << "Print Info Called";
        auto download_handle = session.get_download_handle(id);

        double size = download_handle->getTotalLength();
        qDebug() << "Print Info Called";
        this->fileSize->setText(convertFileSize(size));
        qDebug() << "Print Info Called";

        if (download_handle) {

            double value = (download_handle->getTotalLength() > 0 ?
                           (100 * download_handle->getCompletedLength() /
                            download_handle->getTotalLength()) : 0);

            double speedInBytes = download_handle->getDownloadSpeed();

            double uploadSpeedInBytes = download_handle->getUploadSpeed();

            QString convertedSpeed = convertSpeed(speedInBytes);

            QString convertedUploadSpeed = convertSpeed(uploadSpeedInBytes);
            qDebug() << "Here";
            this->progress->setValue(value);
            qDebug() << "there";
            this->downloadSpeed->setText(convertedSpeed);

            this->uploadSpeed->setText(convertedUploadSpeed);
        }
    }
}

