#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include "aria2cpp.h"
#include "mythread.h"
#include <QMutex>
int MyThread::doDownload()
{
    double progressValue;    //to keep track of the value progress bar
//    Widget *wi = new Widget;
    const auto url = Widget::url;
    const auto outputFileName = Widget::fname;
    const auto outputDirectory = Widget::directory;

//    auto& session = aria2cpp::Session::init();
//    aria2cpp::Session *session = new aria2cpp::Session();
//    session = new aria2cpp::Session();
    session->set_global_option({{"max-overall-download-limit", "10M"}, //10mb
                              {"max-overall-upload-limit", "10M"}});

    auto [response_value, id] = session->add_download(
            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
    this->tempID = id;
    if(id == 1){
        emit idIsOne();
        return EXIT_FAILURE;
    }

    auto start = std::chrono::steady_clock::now();
    for (response_value = 0; (response_value = session->run()) == 1;) {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
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
//    return 0;
}

