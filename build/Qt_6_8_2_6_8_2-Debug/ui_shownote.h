/********************************************************************************
** Form generated from reading UI file 'shownote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWNOTE_H
#define UI_SHOWNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_shownote
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listview_shownote;
    QPushButton *openButton_shownote;
    QPushButton *backButton_shownote;
    QPushButton *searchButton_shownote;

    void setupUi(QWidget *shownote)
    {
        if (shownote->objectName().isEmpty())
            shownote->setObjectName("shownote");
        shownote->resize(800, 600);
        label = new QLabel(shownote);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 181, 31));
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollArea = new QScrollArea(shownote);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(50, 100, 561, 401));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 559, 399));
        listview_shownote = new QListWidget(scrollAreaWidgetContents);
        listview_shownote->setObjectName("listview_shownote");
        listview_shownote->setGeometry(QRect(0, 0, 561, 401));
        listview_shownote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        scrollArea->setWidget(scrollAreaWidgetContents);
        openButton_shownote = new QPushButton(shownote);
        openButton_shownote->setObjectName("openButton_shownote");
        openButton_shownote->setGeometry(QRect(640, 130, 100, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::WindowNew));
        openButton_shownote->setIcon(icon);
        backButton_shownote = new QPushButton(shownote);
        backButton_shownote->setObjectName("backButton_shownote");
        backButton_shownote->setGeometry(QRect(30, 550, 171, 31));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        backButton_shownote->setIcon(icon1);
        searchButton_shownote = new QPushButton(shownote);
        searchButton_shownote->setObjectName("searchButton_shownote");
        searchButton_shownote->setGeometry(QRect(640, 170, 100, 32));
        QIcon icon2(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        searchButton_shownote->setIcon(icon2);

        retranslateUi(shownote);

        QMetaObject::connectSlotsByName(shownote);
    } // setupUi

    void retranslateUi(QWidget *shownote)
    {
        shownote->setWindowTitle(QCoreApplication::translate("shownote", "Form", nullptr));
        label->setText(QCoreApplication::translate("shownote", "<html><head/><body><p><span style=\" font-size:14pt;\">Deine Notizen</span></p></body></html>", nullptr));
        openButton_shownote->setText(QCoreApplication::translate("shownote", "\303\226ffnen", nullptr));
        backButton_shownote->setText(QCoreApplication::translate("shownote", "Zur\303\274ck ins Hauptmen\303\274", nullptr));
        searchButton_shownote->setText(QCoreApplication::translate("shownote", "Suchen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class shownote: public Ui_shownote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWNOTE_H
