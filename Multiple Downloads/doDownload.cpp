#include "widget.h"
#include <QMessageBox>
#include <QDebug>
#include "aria2cpp.h"

int Widget::doDownload()
{
    const auto url = this->getUrl();
    const auto outputFileName = this->getFname();
    const auto outputDirectory = this->getDirectory();

    aria2cpp::Session* session = new aria2cpp::Session();
//    aria2cpp::Session *session = new aria2cpp::Session();
    session->set_global_option({{"max-overall-download-limit", "10M"},
                              {"max-overall-upload-limit", "10M"}});

    auto [response_value, id] = session->add_download(
            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
//    this->tempID = id;
    if(id == 1){
        QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
        this->downloadButton->setDisabled(false);
        return 0;
    }

    auto start = std::chrono::steady_clock::now();
    for (response_value = 0; (response_value = session->run()) == 1;) {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
        if (count >= 750) {
            start = now;
            printInfo(session);
        }
    }

    if(this->progress->value() >= 1) {
        resetWindow();
        return EXIT_SUCCESS;
    }
    else{
        QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
        this->downloadButton->setDisabled(false);
        return EXIT_FAILURE;
    }
}

void Widget::resetWindow()
{
    this->progress->setValue(100);

    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
//    this->isStopped = true;
    this->downloadButton->setDisabled(false);
    this->progress->reset();
    this->urlPath->setText("");
    this->directoryPath->setText("");
    this->fileName->setText("");
    this->fileSize->setText("");
    this->downloadSpeed->setText("");
    this->uploadSpeed->setText("");
}
