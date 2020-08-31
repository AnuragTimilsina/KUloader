#include "widget.h"
#include <QDebug>
#include "aria2cpp.h"

void Widget::printInfo( aria2cpp::Session* session)
{
//    auto& session = aria2cpp::Session::get();

//    auto ids = session.get_active_downloads();

    auto ids = session->get_active_downloads();

    for (auto id : ids) {
        auto download_handle = session->get_download_handle(id);

        double size = download_handle->getTotalLength();
        this->fileSize->setText(convertFileSize(size));

        if (download_handle) {

            double value = (download_handle->getTotalLength() > 0 ?
                           (100 * download_handle->getCompletedLength() /
                            download_handle->getTotalLength()) : 0);

            double speedInBytes = download_handle->getDownloadSpeed();

            double uploadSpeedInBytes = download_handle->getUploadSpeed();

            QString convertedSpeed = convertSpeed(speedInBytes);

            QString convertedUploadSpeed = convertSpeed(uploadSpeedInBytes);
            this->progress->setValue(value);
            this->downloadSpeed->setText(convertedSpeed);

            this->uploadSpeed->setText(convertedUploadSpeed);
        }
    }
}

