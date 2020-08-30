#include "widget.h"

std::string Widget::getUrl() const
{
    return this->url;
}

void Widget::setUrl(const std::string &value)
{
    this->url = value;
}

std::string Widget::getDirectory() const
{
    return this->directory;
}

void Widget::setDirectory(const std::string &value)
{
    this->directory = value;
}

std::string Widget::getFname() const
{
    return this->fname;
}

void Widget::setFname(const std::string &value)
{
    this->fname = value;
}
