/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QPushButton *homeButton;
    QPushButton *downloadsButton;
    QPushButton *aboutButton;
    QLabel *label_10;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLineEdit *urlPath;
    QLabel *label;
    QLineEdit *directory;
    QLabel *label_2;
    QLineEdit *fileName;
    QLabel *label_3;
    QPushButton *downloadButton;
    QLabel *logo;
    QWidget *widget_3;
    QPushButton *browseButton;
    QWidget *page_2;
    QLabel *label_11;
    QWidget *widget_2;
    QLineEdit *uploadSpeed;
    QLineEdit *fileSize;
    QLabel *label_5;
    QLineEdit *downloadSpeed;
    QLabel *label_6;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *quitButton;
    QLabel *label_4;
    QProgressBar *progressBar;
    QWidget *page_3;
    QLabel *label_9;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *logo2;
    QPushButton *exploreButton;
    QLabel *label_12;
    QPlainTextEdit *plainTextEdit;
    QFrame *line;
    QLabel *about;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1549, 759);
        Widget->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid white;\n"
"    border-radius: 10px;\n"
"    padding: 0 20px;\n"
"    \n"
"	background-color: rgb(244, 244, 244);\n"
"	\n"
"    selection-background-color: darkgray;\n"
"}\n"
"\n"
"QProgressBar {\n"
"    border: transparent;\n"
"    border-radius: 15px;\n"
"    text-align: center;\n"
"}\n"
"QPushButton{\n"
"color:white;\n"
"	border-radius:10px;\n"
"	border-solid:red;\n"
"	background: transparent;\n"
"\n"
"\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"  \n"
"   color:white;\n"
"	\n"
"	border-radius:7px;\n"
"	border: transparent;\n"
"	\n"
"	background-color:transparent;\n"
"	\n"
"}"));
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, -20, 261, 1071));
        widget->setStyleSheet(QString::fromUtf8("#widget{\n"
"	\n"
"	background:#091A2B;\n"
"}"));
        homeButton = new QPushButton(widget);
        homeButton->setObjectName(QString::fromUtf8("homeButton"));
        homeButton->setGeometry(QRect(40, 280, 201, 71));
        QFont font;
        font.setFamily(QString::fromUtf8("Nirmala UI Semilight"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        homeButton->setFont(font);
        homeButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"border: 2px solid white;\n"
"}"));
        homeButton->setIconSize(QSize(45, 45));
        downloadsButton = new QPushButton(widget);
        downloadsButton->setObjectName(QString::fromUtf8("downloadsButton"));
        downloadsButton->setGeometry(QRect(50, 350, 191, 71));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nirmala UI"));
        font1.setPointSize(11);
        downloadsButton->setFont(font1);
        downloadsButton->setLayoutDirection(Qt::LeftToRight);
        downloadsButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"border: 2px solid white;\n"
"}"));
        downloadsButton->setIconSize(QSize(30, 30));
        aboutButton = new QPushButton(widget);
        aboutButton->setObjectName(QString::fromUtf8("aboutButton"));
        aboutButton->setGeometry(QRect(40, 420, 201, 61));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nirmala UI Semilight"));
        font2.setPointSize(12);
        aboutButton->setFont(font2);
        aboutButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"border: 2px solid white;\n"
"}"));
        aboutButton->setIconSize(QSize(30, 30));
        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(100, 680, 101, 31));
        QFont font3;
        font3.setFamily(QString::fromUtf8("MS UI Gothic"));
        font3.setPointSize(10);
        label_10->setFont(font3);
        label_10->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        stackedWidget = new QStackedWidget(Widget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(260, -10, 1301, 831));
        stackedWidget->setLineWidth(1);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        urlPath = new QLineEdit(page);
        urlPath->setObjectName(QString::fromUtf8("urlPath"));
        urlPath->setGeometry(QRect(450, 290, 531, 51));
        QFont font4;
        font4.setFamily(QString::fromUtf8("Nirmala UI Semilight"));
        font4.setPointSize(9);
        urlPath->setFont(font4);
        urlPath->setStyleSheet(QString::fromUtf8(""));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(200, 300, 151, 51));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Nirmala UI Semilight"));
        font5.setPointSize(14);
        label->setFont(font5);
        directory = new QLineEdit(page);
        directory->setObjectName(QString::fromUtf8("directory"));
        directory->setGeometry(QRect(450, 390, 411, 51));
        directory->setFont(font4);
        label_2 = new QLabel(page);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(200, 400, 181, 41));
        label_2->setFont(font5);
        fileName = new QLineEdit(page);
        fileName->setObjectName(QString::fromUtf8("fileName"));
        fileName->setGeometry(QRect(450, 500, 521, 51));
        fileName->setFont(font4);
        label_3 = new QLabel(page);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(200, 500, 191, 51));
        label_3->setFont(font5);
        downloadButton = new QPushButton(page);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));
        downloadButton->setGeometry(QRect(480, 620, 181, 61));
        QFont font6;
        font6.setFamily(QString::fromUtf8("SansSerif"));
        font6.setPointSize(14);
        font6.setBold(true);
        font6.setWeight(75);
        downloadButton->setFont(font6);
        downloadButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:white;\n"
"	border-radius:30px;\n"
"	border: transparent;\n"
"	background-color: rgb(234, 64, 22);\n"
"\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"  \n"
"   color:white;\n"
"	border-radius:30px;\n"
"	border: transparent;\n"
"	\n"
"	background-color: rgb(191, 34, 14);\n"
"}"));
        logo = new QLabel(page);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(440, 20, 551, 241));
        widget_3 = new QWidget(page);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(140, 220, 871, 391));
        widget_3->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        browseButton = new QPushButton(widget_3);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        browseButton->setGeometry(QRect(730, 170, 111, 51));
        browseButton->setStyleSheet(QString::fromUtf8("#browseButton{\n"
"	 color: #000;\n"
"	\n"
"	background-color: rgb(241, 241, 241);\n"
"border-radius: 20px;\n"
" border: 1px black;\n"
"}\n"
"#browseButton:hover{\n"
"	background-color:#2EE59D;\n"
" border: 1px solid black;\n"
"}"));
        stackedWidget->addWidget(page);
        widget_3->raise();
        urlPath->raise();
        label->raise();
        directory->raise();
        label_2->raise();
        fileName->raise();
        label_3->raise();
        downloadButton->raise();
        logo->raise();
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        label_11 = new QLabel(page_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(350, 120, 511, 71));
        QFont font7;
        font7.setFamily(QString::fromUtf8("Poor Richard"));
        font7.setPointSize(26);
        font7.setItalic(false);
        label_11->setFont(font7);
        label_11->setStyleSheet(QString::fromUtf8("color:#64dd17;"));
        widget_2 = new QWidget(page_2);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(80, 210, 881, 381));
        widget_2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);\n"
"border-radius:15px;"));
        uploadSpeed = new QLineEdit(widget_2);
        uploadSpeed->setObjectName(QString::fromUtf8("uploadSpeed"));
        uploadSpeed->setGeometry(QRect(700, 90, 111, 41));
        uploadSpeed->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid grey;\n"
"    border-radius: 10px;\n"
"    padding: 0 20px;\n"
"    \n"
"	background-color:transparent;\n"
"	\n"
"    selection-background-color: darkgray;\n"
"}"));
        fileSize = new QLineEdit(widget_2);
        fileSize->setObjectName(QString::fromUtf8("fileSize"));
        fileSize->setGeometry(QRect(120, 90, 111, 41));
        fileSize->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid grey;\n"
"    border-radius: 10px;\n"
"    padding: 0 20px;\n"
"    \n"
"	background-color:transparent;\n"
"	\n"
"    selection-background-color: darkgray;\n"
"}"));
        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(260, 90, 151, 51));
        label_5->setFont(font2);
        downloadSpeed = new QLineEdit(widget_2);
        downloadSpeed->setObjectName(QString::fromUtf8("downloadSpeed"));
        downloadSpeed->setGeometry(QRect(420, 90, 121, 41));
        downloadSpeed->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    border: 1px solid grey;\n"
"    border-radius: 10px;\n"
"    padding: 0 20px;\n"
"    \n"
"	background-color:transparent;\n"
"	\n"
"    selection-background-color: darkgray;\n"
"}"));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(570, 90, 121, 51));
        label_6->setFont(font2);
        pauseButton = new QPushButton(widget_2);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(180, 260, 151, 61));
        QFont font8;
        font8.setFamily(QString::fromUtf8("Nirmala UI"));
        font8.setPointSize(9);
        pauseButton->setFont(font8);
        pauseButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"	border-radius:10px;\n"
"	border:1px solid grey;\n"
"	\n"
"	\n"
"	background-color:transparent ;\n"
"	\n"
"\n"
"}\n"
"QPushButton:hover{\n"
"  \n"
"   color:white;\n"
"	border-radius:10px;\n"
"	\n"
"	border: 0px solid white;\n"
"	background-color: #FFD62C;\n"
"}\n"
""));
        pauseButton->setIconSize(QSize(30, 30));
        resumeButton = new QPushButton(widget_2);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));
        resumeButton->setGeometry(QRect(360, 260, 141, 61));
        resumeButton->setFont(font8);
        resumeButton->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"color:black;\n"
"	border-radius:10px;\n"
"	border:1px solid grey;\n"
"	\n"
"	\n"
"	background-color:transparent ;\n"
"	\n"
"\n"
"}\n"
"\n"
"QPushButton:hover{\n"
"  \n"
"   color:white;\n"
"	border-radius:10px;\n"
"	border: 0px solid white;\n"
"	\n"
"		background-color:#66af46;\n"
"}"));
        resumeButton->setIconSize(QSize(30, 30));
        quitButton = new QPushButton(widget_2);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));
        quitButton->setGeometry(QRect(530, 260, 151, 61));
        quitButton->setStyleSheet(QString::fromUtf8("#quitButton{\n"
"	background:white;\n"
"	border-radius:10px;\n"
"	border: 1px solid grey;\n"
"	color: black;\n"
"	\n"
"}\n"
"#quitButton:hover{\n"
"background: black;\n"
"border-radius:10px;\n"
"	color: white;\n"
"background:#091A2B;\n"
"}"));
        label_4 = new QLabel(widget_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(30, 90, 71, 51));
        label_4->setFont(font2);
        progressBar = new QProgressBar(widget_2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(30, 190, 791, 21));
        progressBar->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        progressBar->setValue(0);
        stackedWidget->addWidget(page_2);
        widget_2->raise();
        label_11->raise();
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        page_3->setStyleSheet(QString::fromUtf8("background:#948EEE;"));
        label_9 = new QLabel(page_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(340, 600, 211, 16));
        QFont font9;
        font9.setFamily(QString::fromUtf8("SansSerif"));
        font9.setPointSize(12);
        font9.setBold(false);
        font9.setWeight(50);
        label_9->setFont(font9);
        label_9->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_7 = new QLabel(page_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(280, 620, 481, 61));
        QFont font10;
        font10.setFamily(QString::fromUtf8("Poor Richard"));
        font10.setPointSize(9);
        label_7->setFont(font10);
        label_7->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        label_8 = new QLabel(page_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(330, 660, 341, 41));
        label_8->setFont(font10);
        label_8->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        logo2 = new QLabel(page_3);
        logo2->setObjectName(QString::fromUtf8("logo2"));
        logo2->setGeometry(QRect(460, 50, 491, 181));
        exploreButton = new QPushButton(page_3);
        exploreButton->setObjectName(QString::fromUtf8("exploreButton"));
        exploreButton->setGeometry(QRect(270, 480, 311, 61));
        QFont font11;
        font11.setFamily(QString::fromUtf8("SansSerif"));
        font11.setPointSize(10);
        exploreButton->setFont(font11);
        exploreButton->setStyleSheet(QString::fromUtf8("QPushButton:hover{\n"
"	border:2px white;\n"
"border-radius:30px;\n"
"color:white;\n"
"background:transparent;\n"
"}\n"
"QPushButton{\n"
"	border:2px  black;\n"
"	background:black;\n"
"	border-radius:30px;\n"
"}"));
        label_12 = new QLabel(page_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(740, 310, 171, 71));
        QFont font12;
        font12.setFamily(QString::fromUtf8("Poor Richard"));
        font12.setPointSize(22);
        label_12->setFont(font12);
        label_12->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        plainTextEdit = new QPlainTextEdit(page_3);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(640, 400, 441, 221));
        QFont font13;
        font13.setFamily(QString::fromUtf8("Poor Richard"));
        font13.setPointSize(12);
        plainTextEdit->setFont(font13);
        plainTextEdit->setStyleSheet(QString::fromUtf8("border:transparent;\n"
"color: rgb(255, 255, 255);"));
        line = new QFrame(page_3);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(700, 370, 231, 31));
        line->setStyleSheet(QString::fromUtf8(""));
        line->setLineWidth(1);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        about = new QLabel(page_3);
        about->setObjectName(QString::fromUtf8("about"));
        about->setGeometry(QRect(230, 230, 361, 241));
        stackedWidget->addWidget(page_3);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        homeButton->setText(QCoreApplication::translate("Widget", "Home", nullptr));
        downloadsButton->setText(QCoreApplication::translate("Widget", "Downloads", nullptr));
        aboutButton->setText(QCoreApplication::translate("Widget", "About", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "Version 1.0.0", nullptr));
        label->setText(QCoreApplication::translate("Widget", "Enter Url:", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "Enter Directory", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "Enter File name", nullptr));
        downloadButton->setText(QCoreApplication::translate("Widget", "Download", nullptr));
        logo->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        browseButton->setText(QCoreApplication::translate("Widget", "Browse", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "Pending Download:", nullptr));
        label_5->setText(QCoreApplication::translate("Widget", "Download Speed:", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "Upload Speed:", nullptr));
        pauseButton->setText(QCoreApplication::translate("Widget", "Pause", nullptr));
        resumeButton->setText(QCoreApplication::translate("Widget", "Resume", nullptr));
        quitButton->setText(QCoreApplication::translate("Widget", "Quit", nullptr));
        label_4->setText(QCoreApplication::translate("Widget", "File Size:", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "COPYRIGHT(R) 2020", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "Grab your music, TV shows, movies, games and other files faster", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", " with a smart multi-stream download manager.", nullptr));
        logo2->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
        exploreButton->setText(QCoreApplication::translate("Widget", "EXPLORE IN GITHUB", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "About Us:", nullptr));
        plainTextEdit->setPlainText(QCoreApplication::translate("Widget", "This app is designed by students of Kathmandu University department of Computer Engineering. Currently we are working with 5 team members. We hope to extend our project further for easier excess to every people. \n"
"\n"
"Keep Supporting!", nullptr));
        about->setText(QCoreApplication::translate("Widget", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
