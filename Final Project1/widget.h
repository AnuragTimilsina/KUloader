#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QProgressBar>
#include "aria2cpp.h"
#include <QThread>
#include <mythread.h>

class Widget : public QWidget
{
    Q_OBJECT
private:
    QLabel *label;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label6;
    QLabel *label7;
    QLineEdit *urlPath;
    QLineEdit *directoryPath;
    QLineEdit *fileName;
    QLineEdit *fileSize;
    QLineEdit *downloadSpeed;
    QLineEdit *uploadSpeed;
    QPushButton *browseButton;
    QPushButton *quitButton;
    QPushButton *downloadButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
//    static QProgressBar *progress;
    QProgressBar *progress;
    QHBoxLayout *urlLayout;
    QHBoxLayout *dirLayout;
    QHBoxLayout *progressLayout;
    QHBoxLayout *fileNameLayout;
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *downloadDetails;
    QFormLayout *formLayout;

public:
    static std::string url;
    static std::string directory;
    static std::string fname;

private:
    //initialize ui
    void initUi();

public:
    MyThread *thread;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    std::string getUrl() const;
    void setUrl(const std::string &value);

    std::string getDirectory() const;
    void setDirectory(const std::string &value);

    std::string getFname() const;
    void setFname(const std::string &value);

public:
    //check and convert
    QString convertSpeed(double);

    QString convertFileSize(double);

    bool checkDirectory(QString);

    //clear window for next download
    void resetWindow();

private slots:    
    void onNumberChanged(double, double, double, double);
    void ifIdIsOne();
    void onSuccess();
    void onFailure();

private slots:
    void quitClicked();
    void browseClicked();
    void downloadClicked();
    void pauseClicked();
    void resumeClicked();
    void urlPathEditingFinished();
    void directoryPathEditingFinished();
    void fileNameEditingFinished();
};
#endif // WIDGET_H
