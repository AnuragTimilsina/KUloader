/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *heading;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *downloadButton;
    QPushButton *pauseButton;
    QPushButton *resumeButton;
    QPushButton *quitButton;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_8;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QLineEdit *fileSize;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QLineEdit *downloadSpeed;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QLineEdit *uploadSpeed;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *urlPath;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *directoryPath;
    QPushButton *browseButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *fileName;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QProgressBar *progressBar;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(671, 329);
        heading = new QLabel(Widget);
        heading->setObjectName(QString::fromUtf8("heading"));
        heading->setGeometry(QRect(270, 10, 161, 31));
        QFont font;
        font.setFamily(QString::fromUtf8("Tlwg Typewriter"));
        font.setPointSize(22);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        heading->setFont(font);
        heading->setAlignment(Qt::AlignCenter);
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 250, 340, 27));
        horizontalLayout_9 = new QHBoxLayout(layoutWidget);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        downloadButton = new QPushButton(layoutWidget);
        downloadButton->setObjectName(QString::fromUtf8("downloadButton"));

        horizontalLayout_9->addWidget(downloadButton);

        pauseButton = new QPushButton(layoutWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));

        horizontalLayout_9->addWidget(pauseButton);

        resumeButton = new QPushButton(layoutWidget);
        resumeButton->setObjectName(QString::fromUtf8("resumeButton"));

        horizontalLayout_9->addWidget(resumeButton);

        quitButton = new QPushButton(layoutWidget);
        quitButton->setObjectName(QString::fromUtf8("quitButton"));

        horizontalLayout_9->addWidget(quitButton);

        layoutWidget1 = new QWidget(Widget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(20, 210, 631, 31));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(layoutWidget1);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font1;
        font1.setPointSize(10);
        label_5->setFont(font1);

        horizontalLayout_7->addWidget(label_5);

        fileSize = new QLineEdit(layoutWidget1);
        fileSize->setObjectName(QString::fromUtf8("fileSize"));

        horizontalLayout_7->addWidget(fileSize);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font1);

        horizontalLayout_5->addWidget(label_6);

        downloadSpeed = new QLineEdit(layoutWidget1);
        downloadSpeed->setObjectName(QString::fromUtf8("downloadSpeed"));

        horizontalLayout_5->addWidget(downloadSpeed);


        horizontalLayout_7->addLayout(horizontalLayout_5);


        horizontalLayout_8->addLayout(horizontalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font1);

        horizontalLayout_6->addWidget(label_7);

        uploadSpeed = new QLineEdit(layoutWidget1);
        uploadSpeed->setObjectName(QString::fromUtf8("uploadSpeed"));

        horizontalLayout_6->addWidget(uploadSpeed);


        horizontalLayout_8->addLayout(horizontalLayout_6);

        layoutWidget2 = new QWidget(Widget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 50, 631, 151));
        verticalLayout = new QVBoxLayout(layoutWidget2);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget2);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font2;
        font2.setPointSize(14);
        label->setFont(font2);

        horizontalLayout->addWidget(label);

        urlPath = new QLineEdit(layoutWidget2);
        urlPath->setObjectName(QString::fromUtf8("urlPath"));

        horizontalLayout->addWidget(urlPath);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        horizontalLayout_2->addWidget(label_2);

        directoryPath = new QLineEdit(layoutWidget2);
        directoryPath->setObjectName(QString::fromUtf8("directoryPath"));

        horizontalLayout_2->addWidget(directoryPath);

        browseButton = new QPushButton(layoutWidget2);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));

        horizontalLayout_2->addWidget(browseButton);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font2);

        horizontalLayout_3->addWidget(label_3);

        fileName = new QLineEdit(layoutWidget2);
        fileName->setObjectName(QString::fromUtf8("fileName"));

        horizontalLayout_3->addWidget(fileName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font2);

        horizontalLayout_4->addWidget(label_4);

        progressBar = new QProgressBar(layoutWidget2);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(0);

        horizontalLayout_4->addWidget(progressBar);


        verticalLayout->addLayout(horizontalLayout_4);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", nullptr));
        heading->setText(QApplication::translate("Widget", "KU Loader", nullptr));
        downloadButton->setText(QApplication::translate("Widget", "Download", nullptr));
        pauseButton->setText(QApplication::translate("Widget", "Pause", nullptr));
        resumeButton->setText(QApplication::translate("Widget", "Resume", nullptr));
        quitButton->setText(QApplication::translate("Widget", "Quit", nullptr));
        label_5->setText(QApplication::translate("Widget", "File Size:", nullptr));
        label_6->setText(QApplication::translate("Widget", "Download Speed:", nullptr));
        label_7->setText(QApplication::translate("Widget", "Upload Speed:", nullptr));
        label->setText(QApplication::translate("Widget", "Enter URL:", nullptr));
        label_2->setText(QApplication::translate("Widget", "Enter Directory:", nullptr));
        browseButton->setText(QApplication::translate("Widget", "Browse", nullptr));
        label_3->setText(QApplication::translate("Widget", "Enter File Name:", nullptr));
        label_4->setText(QApplication::translate("Widget", "Downloading...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
