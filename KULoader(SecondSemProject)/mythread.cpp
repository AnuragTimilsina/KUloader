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

MyThread::~MyThread()
{
    delete session;
}

int MyThread::doDownload()
{
    // The functions doDownload and printInfo collectively performs the download opeartion

    std::string index[] = {"512000","1048576","2097152","5242880","10485760"};
    session = new aria2cpp::Session;
    double progressValue;    //to keep track of the value progress bar

    const auto url = Widget::url;
    const auto outputFileName = Widget::fname;
    const auto outputDirectory = Widget::directory;

    session->changeGlobalOption({{"max-overall-download-limit", "10485760"},
                              {"max-overall-upload-limit", "10485760"}});

    auto [responseValue, id] = session->addDownload(
                                {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
    if(id == 1){
        emit idIsOne();
        return EXIT_FAILURE;
    }

    auto start = std::chrono::steady_clock::now();

    for (responseValue = 0; (responseValue = session->run()) == 1;) {
        for(int i = 0; i < 5; i++) {
            if(Widget::controlDownloadIndex == i)
                session->changeGlobalOption({{"max-overall-download-limit", index[i]}});
            if(Widget::controlUploadIndex == i)
                session->changeGlobalOption({{"max-overall-upload-limit", index[i]}});
        }

        auto now = std::chrono::steady_clock::now();
        auto count = std::chrono::duration_cast<std::chrono::milliseconds>(now - start).count();
        if (count >= 750) {
            start = now;
           progressValue = printInfo(session);

        }
    }

    if(progressValue >= 1) {
        emit success();
        return EXIT_SUCCESS;
    }
    else{
        emit failure();
        return EXIT_FAILURE;
    }
}

int MyThread::printInfo(aria2cpp::Session* session)
{
    double progressValue;

    auto ids = session->getActiveDownloads();

    for (auto id : ids) {
        auto downloadHandle = session->getDownloadHandle(id);

        double size = downloadHandle->getTotalLength();

        if (downloadHandle) {

            progressValue = (downloadHandle->getTotalLength() > 0 ?
                           (100 * downloadHandle->getCompletedLength() /
                            downloadHandle->getTotalLength()) : 0);

            double speedInBytes = downloadHandle->getDownloadSpeed();

            double uploadSpeedInBytes = downloadHandle->getUploadSpeed();

            emit numberChanged(size, progressValue, speedInBytes, uploadSpeedInBytes);
        }
    }
    return progressValue;
}


