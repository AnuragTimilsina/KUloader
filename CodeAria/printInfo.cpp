#include "widget.h"
#include <QDebug>
#include "aria2cpp.h"
#include "mythread.h"
int MyThread::printInfo(aria2cpp::Session *session)
{
    double progressValue;
    qDebug() << "Print Info Called";
//    auto& session = aria2cpp::Session::get();

    auto ids = session->get_active_downloads();

    for (auto id : ids) {
        auto download_handle = session->get_download_handle(id);

        double size = download_handle->getTotalLength();
//        this->fileSize->setText(this->convertFileSize(size));

        if (download_handle) {

            progressValue = (download_handle->getTotalLength() > 0 ?
                           (100 * download_handle->getCompletedLength() /
                            download_handle->getTotalLength()) : 0);

            double speedInBytes = download_handle->getDownloadSpeed();

            double uploadSpeedInBytes = download_handle->getUploadSpeed();

            emit numberChanged(size, progressValue, speedInBytes, uploadSpeedInBytes);
        }
    }
    return progressValue;
}

