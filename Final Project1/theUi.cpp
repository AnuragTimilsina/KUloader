#include "widget.h"

void Widget::initUi()
{
    //making fonts for our labels
    QFont font("Times", 16);
    QFont font2("Times", 12);
    QFont headerFont("Times", 18, QFont::Bold);

    //creating labels to name a widget
    QLabel *label = new QLabel;
    label->setText("KU Loader");
    label->setFont(headerFont);
    label->setAlignment(Qt::AlignCenter);

    QLabel *label1 = new QLabel;
    label1->setText("Enter URL: ");
    label1->setFont(font);

    QLabel *label2 = new QLabel;
    label2->setText("Enter Directory: ");
    label2->setFont(font);

    QLabel *label3 = new QLabel;
    label3->setText("Enter File Name: ");
    label3->setFont(font);

    QLabel *label4 = new QLabel;
    label4->setText("Downloading... ");
    label4->setFont(font);

    QLabel *label5 = new QLabel;
    label5->setText("File Size: ");
    label5->setFont(font2);

    QLabel *label6 = new QLabel;
    label6->setText("Download Speed: ");
    label6->setFont(font2);

    QLabel *label7 = new QLabel;
    label7->setText("Upload Speed: ");
    label7->setFont(font2);


    //creating line edit to accept text from the user
    urlPath = new QLineEdit;
    //connecting the signal from line edit to it's desired slot
    connect(urlPath, SIGNAL(editingFinished()), this, SLOT(urlPathEditingFinished()));

    directoryPath = new QLineEdit;
    connect(directoryPath, SIGNAL(editingFinished()), this, SLOT(directoryPathEditingFinished()));

    fileName = new QLineEdit;
    connect(fileName, SIGNAL(editingFinished()), this, SLOT(fileNameEditingFinished()));

    fileSize = new QLineEdit;
    downloadSpeed = new QLineEdit;
    uploadSpeed = new QLineEdit;


    //creating different buttons for different purposes
    browseButton = new QPushButton;
    browseButton->setText("Browse");
    //connecting the signal genearted from the button to it's respective slot
    connect(browseButton, SIGNAL(clicked()), this, SLOT(browseClicked()));

    downloadButton = new QPushButton;
    downloadButton->setText("Download");
    connect(downloadButton, SIGNAL(clicked()), this, SLOT(downloadClicked()));
    downloadButton->setDisabled(false);  //enabling the download button by default

    pauseButton = new QPushButton;
    pauseButton->setText("Pause");
    connect(pauseButton, SIGNAL(clicked()), this, SLOT(pauseClicked()));

    resumeButton = new QPushButton;
    resumeButton->setText("Resume");
    connect(resumeButton, SIGNAL(clicked()), this, SLOT(resumeClicked()));

    quitButton = new QPushButton;
    quitButton->setText("Quit");
    connect(quitButton, SIGNAL(clicked()), this, SLOT(quitClicked()));


    //progress bar
    progress = new QProgressBar;
    progress->setRange(0, 100);
    progress->setValue(0);


    //cretaing a horizontal layout for each components
    urlLayout = new QHBoxLayout;
    urlLayout->addWidget(label1);
    urlLayout->addWidget(urlPath);

    dirLayout = new QHBoxLayout;
    dirLayout->addWidget(label2);
    dirLayout->addWidget(directoryPath);
    dirLayout->addWidget(browseButton);


    fileNameLayout = new QHBoxLayout;
    fileNameLayout->addWidget(label3);
    fileNameLayout->addWidget(fileName);

    progressLayout = new QHBoxLayout;
    progressLayout->addWidget(label4);
    progressLayout->addWidget(progress);

    buttonsLayout = new QHBoxLayout;
    buttonsLayout->addWidget(downloadButton);
    buttonsLayout->addWidget(pauseButton);
    buttonsLayout->addWidget(resumeButton);
    buttonsLayout->addWidget(quitButton);

    downloadDetails = new QHBoxLayout;
    downloadDetails->addWidget(label5);
    downloadDetails->addWidget(fileSize);
    downloadDetails->addWidget(label6);
    downloadDetails->addWidget(downloadSpeed);
    downloadDetails->addWidget(label7);
    downloadDetails->addWidget(uploadSpeed);


    //finally creating a form layout for our main window
    formLayout = new QFormLayout;
    formLayout->addRow(label);
    formLayout->addRow(urlLayout);
    formLayout->addRow(dirLayout);
    formLayout->addRow(fileNameLayout);
    formLayout->addRow(progressLayout);
    formLayout->addRow(downloadDetails);
    formLayout->addRow(buttonsLayout);
    setLayout(formLayout);
}
