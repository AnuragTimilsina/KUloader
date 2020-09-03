#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "aria2cpp.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QProgressBar>
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
    QProgressBar *progress;
    QHBoxLayout *urlLayout;
    QHBoxLayout *dirLayout;
    QHBoxLayout *progressLayout;
    QHBoxLayout *fileNameLayout;
    QHBoxLayout *buttonsLayout;
    QHBoxLayout *downloadDetails;
    QFormLayout *formLayout;

    std::string url;
    std::string directory;
    std::string fname;

private:
    //initialize ui
    void initUi();

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

    int doDownload();
    void printInfo( aria2cpp::Session*);

    //check and convert
    QString convertSpeed(double);

    QString convertFileSize(double);

    bool checkDirectory(QString);

    //reset window
    void resetWindow();

private slots:
    void quitClicked();
    void browseClicked();
    void downloadClicked();
    void urlPathEditingFinished();
    void directoryPathEditingFinished();
    void fileNameEditingFinished();
};
#endif // WIDGET_H
