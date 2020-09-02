#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <cstring>
#include "aria2cpp.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    static uint64_t tempID;
private:
    std::string url;
    std::string fileName;
    std::string directory;

public:
    bool isStopped;
public:

    Widget(QWidget *parent = nullptr);

    //getters and setters
    void setUrl(std::string);
    std::string getUrl();

    void setDirectory(std::string);
    std::string getdirectory();

    void setFileName(std::string);
    std::string getFileName();

    int doDownload();
    void printInfo();

    //check and convert
    QString convertSpeed(double);

    QString convertFileSize(double);

    bool checkDirectory(QString);

    //reset window
    void resetWindow();

    ~Widget();

private slots:
    void on_downloadButton_clicked();

    void on_quitButton_clicked();

    void on_urlPath_editingFinished();

    void on_urlPath_textChanged(const QString &arg1);

    void on_fileName_editingFinished();

    void on_fileName_textChanged(const QString &arg1);

    void on_browseButton_clicked();

    void on_directoryPath_editingFinished();

    void on_directoryPath_textChanged(const QString &arg1);

    void on_pauseButton_clicked();

    void on_resumeButton_clicked();


public:
    Ui::Widget *ui;
};
#endif // WIDGET_H
