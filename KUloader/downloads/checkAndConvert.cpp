#include "widget.h"
#include <QDir>

QString Widget::convertFileSize(double sizeInByte)
{
    double sizeInKb, sizeInMb, sizeInGb;

    if (sizeInByte > 1024) {
        sizeInKb = sizeInByte / 1024;

        if(sizeInKb > 1024) {
            sizeInMb = sizeInKb / 1024;
        }
        else {
            return QString::number(sizeInKb) + "KB";
        }
        if(sizeInMb > 1024) {
            sizeInGb = sizeInMb / 1024;
            return QString::number(sizeInGb) + "GB";
        }
        else{
            return QString::number(sizeInMb) + "MB";
        }
    }
    else {
        return QString::number(sizeInByte) + "B";
    }
}

bool Widget::checkDirectory(QString path)
{

    if(!path.isEmpty()) {

        QDir dir(path);

        if(!dir.exists())
            return false;
        else
            return true;
        }
    return false;

}

QString Widget::convertSpeed(double speedInBytes)
{
    double speedInKb;
    double speedInMb;

    if(speedInBytes > 1024) {
        speedInKb = speedInBytes / 1024;

        if(speedInKb > 1024) {
            speedInMb = speedInKb / 1024;
            return QString::number(speedInMb) + "MB/s";
        }
        else {
            return QString::number(speedInKb) + "KB/s";
        }
    }
    else {
        return QString::number(speedInBytes) + "B/s";
    }
}

