#include "mythread.h"
#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include "aria2cpp.h"
void MyThread::run()
{
    doDownload();
}

MyThread::MyThread()
{
}

unsigned long MyThread::tempID = 0;

int MyThread::doDownload()
{
    double progressValue;    //to keep track of the value progress bar
//    Widget *wi = new Widget;
    const auto url = Widget::url;
    const auto outputFileName = Widget::directory;
    const auto outputDirectory = Widget::fname;

    auto& session = aria2cpp::Session::init();
    session.changeGlobalOption({{"max-overall-download-limit", "10M"},
                              {"max-overall-upload-limit", "10M"}});

    auto [response_value, id] = session.addDownload(
            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
    this->tempID = id;
    if(id == 1){
        emit idIsOne();
        return EXIT_FAILURE;
    }

    auto start = std::chrono::steady_clock::now();

    for (response_value = 0; (response_value = session.run()) == 1;) {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
        if (count >= 750) {
            start = now;
           progressValue = printInfo();
        }
    }

    if(progressValue >= 1) {
        emit success();
        return EXIT_SUCCESS;
    }
    else{
        emit failure();
        return EXIT_FAILURE;
    };
}

int MyThread::printInfo()
{
    double progressValue;
    auto& session = aria2cpp::Session::get();

    auto ids = session.getActiveDownloads();

    for (auto id : ids) {
        auto download_handle = session.getDownloadHandle(id);

        double size = download_handle->getTotalLength();

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


