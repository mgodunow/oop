#include "customtextbrowser.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"

#include <QtWidgets/QTextBrowser>
#include <QColor>

CustomTextBrowser::CustomTextBrowser (QWidget*& widget)
{

}

void CustomTextBrowser::appendPink(const QString text, CustomTextBrowser*& tb){
    tb->setTextColor(QColor(255, 102, 102));
    tb->append(text);
}

void CustomTextBrowser::appendGreen(const QString text, CustomTextBrowser*& tb){
    tb->setTextColor(QColor(0, 204, 102));
    tb->append(text);
}

void CustomTextBrowser::appendBlue(const QString text, CustomTextBrowser*& tb){
    tb->setTextColor(QColor(0, 51, 153));
    tb->append(text);
}

void CustomTextBrowser::appendRed(const QString text, CustomTextBrowser*& tb){
    tb->setTextColor(QColor(255, 51, 0));
    tb->append(text);
}
