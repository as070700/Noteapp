/********************************************************************************
** Form generated from reading UI file 'editnote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITNOTE_H
#define UI_EDITNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_editnote
{
public:
    QLabel *label_editnote;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget_editnote;
    QPushButton *backButton_editnote;
    QPushButton *openButton_editnote;
    QLabel *errorLabel_editnote;

    void setupUi(QWidget *editnote)
    {
        if (editnote->objectName().isEmpty())
            editnote->setObjectName("editnote");
        editnote->resize(800, 600);
        label_editnote = new QLabel(editnote);
        label_editnote->setObjectName("label_editnote");
        label_editnote->setGeometry(QRect(40, 70, 271, 16));
        label_editnote->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollArea = new QScrollArea(editnote);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(30, 100, 621, 401));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 619, 399));
        listWidget_editnote = new QListWidget(scrollAreaWidgetContents);
        listWidget_editnote->setObjectName("listWidget_editnote");
        listWidget_editnote->setGeometry(QRect(0, 0, 621, 401));
        listWidget_editnote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        scrollArea->setWidget(scrollAreaWidgetContents);
        backButton_editnote = new QPushButton(editnote);
        backButton_editnote->setObjectName("backButton_editnote");
        backButton_editnote->setGeometry(QRect(30, 550, 191, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        backButton_editnote->setIcon(icon);
        backButton_editnote->setIconSize(QSize(18, 16));
        openButton_editnote = new QPushButton(editnote);
        openButton_editnote->setObjectName("openButton_editnote");
        openButton_editnote->setGeometry(QRect(670, 120, 100, 32));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::DocumentOpen));
        openButton_editnote->setIcon(icon1);
        openButton_editnote->setIconSize(QSize(18, 16));
        errorLabel_editnote = new QLabel(editnote);
        errorLabel_editnote->setObjectName("errorLabel_editnote");
        errorLabel_editnote->setGeometry(QRect(300, 510, 351, 31));

        retranslateUi(editnote);

        QMetaObject::connectSlotsByName(editnote);
    } // setupUi

    void retranslateUi(QWidget *editnote)
    {
        editnote->setWindowTitle(QCoreApplication::translate("editnote", "Dialog", nullptr));
        label_editnote->setText(QCoreApplication::translate("editnote", "Welche Notiz m\303\266chtest du \303\244ndern?", nullptr));
        backButton_editnote->setText(QCoreApplication::translate("editnote", "Zur\303\274ck zum Hauptmen\303\274", nullptr));
        openButton_editnote->setText(QCoreApplication::translate("editnote", "\303\226ffnen", nullptr));
        errorLabel_editnote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class editnote: public Ui_editnote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITNOTE_H
