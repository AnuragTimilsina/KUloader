#include "widget.h"

void Widget::setUrl(std::string url)
{
    this->url = url;
}

std::string Widget::getUrl()
{
    return this->url;
}

void Widget::setDirectory(std::string directory)
{
    this->directory = directory;
}

std::string Widget::getdirectory()
{
    return this->directory;
}

void Widget::setFileName(std::string fname)
{
    this->fileName = fname;
}

std::string Widget::getFileName()
{
    return fileName;
}
