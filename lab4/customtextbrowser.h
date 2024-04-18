#ifndef CUSTOMTEXTBROWSER_H
#define CUSTOMTEXTBROWSER_H

#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>


class CustomTextBrowser : public QTextBrowser {
public:
    CustomTextBrowser(QWidget*& widget);
    void appendPink(const QString text, CustomTextBrowser*& tb);
    void appendGreen(const QString text, CustomTextBrowser*& tb);
    void appendBlue(const QString text, CustomTextBrowser*& tb);
    void appendRed(const QString text, CustomTextBrowser*& tb);

private:

};

#endif // CUSTOMTEXTBROWSER_H
