/********************************************************************************
** Form generated from reading UI file 'deletenote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DELETENOTE_H
#define UI_DELETENOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_deletenote
{
public:
    QLabel *label;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QListWidget *listWidget_deleteNote;
    QPushButton *backButton_deleteNote;
    QPushButton *deleteButton_deleteNote;
    QLabel *errorLabel_deletnote;

    void setupUi(QWidget *deletenote)
    {
        if (deletenote->objectName().isEmpty())
            deletenote->setObjectName("deletenote");
        deletenote->resize(800, 600);
        label = new QLabel(deletenote);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 60, 301, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        scrollArea = new QScrollArea(deletenote);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(50, 90, 601, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 599, 409));
        listWidget_deleteNote = new QListWidget(scrollAreaWidgetContents);
        listWidget_deleteNote->setObjectName("listWidget_deleteNote");
        listWidget_deleteNote->setGeometry(QRect(0, 0, 641, 421));
        listWidget_deleteNote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        scrollArea->setWidget(scrollAreaWidgetContents);
        backButton_deleteNote = new QPushButton(deletenote);
        backButton_deleteNote->setObjectName("backButton_deleteNote");
        backButton_deleteNote->setGeometry(QRect(20, 550, 201, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::GoHome));
        backButton_deleteNote->setIcon(icon);
        backButton_deleteNote->setIconSize(QSize(19, 20));
        deleteButton_deleteNote = new QPushButton(deletenote);
        deleteButton_deleteNote->setObjectName("deleteButton_deleteNote");
        deleteButton_deleteNote->setGeometry(QRect(680, 100, 100, 32));
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("user-trash")));
        deleteButton_deleteNote->setIcon(icon1);
        deleteButton_deleteNote->setIconSize(QSize(20, 20));
        errorLabel_deletnote = new QLabel(deletenote);
        errorLabel_deletnote->setObjectName("errorLabel_deletnote");
        errorLabel_deletnote->setGeometry(QRect(370, 510, 281, 31));

        retranslateUi(deletenote);

        QMetaObject::connectSlotsByName(deletenote);
    } // setupUi

    void retranslateUi(QWidget *deletenote)
    {
        deletenote->setWindowTitle(QCoreApplication::translate("deletenote", "Form", nullptr));
        label->setText(QCoreApplication::translate("deletenote", "Welche Notiz m\303\266chtest du l\303\266schen?", nullptr));
        backButton_deleteNote->setText(QCoreApplication::translate("deletenote", "Zur\303\274ck zum Hauptmen\303\274", nullptr));
        deleteButton_deleteNote->setText(QCoreApplication::translate("deletenote", "L\303\266schen", nullptr));
        errorLabel_deletnote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class deletenote: public Ui_deletenote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DELETENOTE_H
