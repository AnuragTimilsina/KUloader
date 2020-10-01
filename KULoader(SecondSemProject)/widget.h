#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "aria2cpp.h"
#include <mythread.h>
#include "ui_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    static std::string url;
    static std::string directory;
    static std::string fname;

public:
    static int controlUploadIndex;
    static int controlDownloadIndex;

private:
    MyThread *thread;

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void setUrl(const std::string &value);

    std::string getDirectory() const;
    void setDirectory(const std::string &value);

    void setFname(const std::string &value);

    void setControlUploadIndex(const int &value);

    void setControlDownloadIndex(const int &value);

    //check and convert
    QString convertSpeed(double);

    QString convertFileSize(double);

    bool checkDirectory(QString);

    //clear window for next download
    void resetWindow();

private slots:    
    //slots for thread
    void onNumberChanged(double, double, double, double);
    void ifIdIsOne();
    void onSuccess();
    void onFailure();

   //slots for ui
   void on_quitButton_clicked();
   void on_browseButton_clicked();
   void on_downloadButton_clicked();

   void on_urlPath_editingFinished();
   void on_directory_editingFinished();
   void on_fileName_editingFinished();

   void on_homeButton_clicked();
   void on_downloadsButton_clicked();
   void on_aboutButton_clicked();
   void on_exploreButton_clicked();

   void on_controlDownload_currentIndexChanged(int index);
   void on_controlUpload_currentIndexChanged(int index);

private:
    Ui::Widget *ui;

};
#endif // WIDGET_H
