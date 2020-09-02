#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include "aria2cpp.h"
int Widget::doDownload()
{
    auto url = this->getUrl();

    const auto outputFileName = this->getFileName();
    const auto outputDirectory = this->getdirectory();

    auto& session = aria2cpp::Session::init();
    session.set_global_option({{"max-overall-download-limit", "10485760"}, //10mb
                              {"max-overall-upload-limit", "10240"},   //10kb
                               {"bt-load-saved-metadata","true"},
                               {"enable-peer-exchange","false"}});

//    //the first value is response value and second is the download id
//    std::pair<int, unsigned int> values  = session.add_download(
//            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});

    auto [response_value, id] = session.add_download(
            {url}, {{"out", outputFileName}, {"dir", outputDirectory}});
    this->tempID = id;
    if(id == 1){
        QMessageBox::warning(this, "ERROR MESSAGE", "Downnload Error.\nPlease check if your URL is valid.");
        ui->downloadButton->setDisabled(false);
        return 0;
    }

//    if (response_value < 0) {
//        QMessageBox::warning(this, "ERROR MESSAGE", "Please enter valid url");
//        ui->downloadButton->setDisabled(false);
//        return EXIT_FAILURE;
//    }
//            std::cout << "Added download. Download ID is:" << id << std::endl;

    auto start = std::chrono::steady_clock::now();
    for (response_value = 0; (response_value = session.run()) == 1;) {
        auto now = std::chrono::steady_clock::now();
        auto count =
            std::chrono::duration_cast<std::chrono::milliseconds>(now - start)
                .count();
//        qDebug() << count;
        if (count >= 750) {
            start = now;
            printInfo();
        }
    }

    if(ui->progressBar->value() >= 1) {
        resetWindow();
        return EXIT_SUCCESS;
    }
    else{
        QMessageBox::warning(this, "ERROR MESSAGE", "Download Failed.\nPlease check if your URL is valid");
        ui->downloadButton->setDisabled(false);
        return EXIT_FAILURE;
    }
}

void Widget::resetWindow()
{
    ui->progressBar->setValue(100);

    QMessageBox::information(this, "MESSAGE", "Your download is complete", QMessageBox::Ok);
    this->isStopped = true;
    ui->downloadButton->setDisabled(false);
    ui->progressBar->reset();
    ui->urlPath->setText("");
    ui->directoryPath->setText("");
    ui->fileName->setText("");
    ui->fileSize->setText("");
    ui->downloadSpeed->setText("");
    ui->uploadSpeed->setText("");
}
