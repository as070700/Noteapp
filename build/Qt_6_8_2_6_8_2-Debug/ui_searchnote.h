/********************************************************************************
** Form generated from reading UI file 'searchnote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEARCHNOTE_H
#define UI_SEARCHNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_searchnote
{
public:
    QLabel *label_searchnote;
    QLineEdit *searchLineEdit_searchnote;
    QListWidget *searchResultsListWidget_searchnote;
    QPushButton *backButton_searchnote;
    QPushButton *searchButton_searchnote;

    void setupUi(QWidget *searchnote)
    {
        if (searchnote->objectName().isEmpty())
            searchnote->setObjectName("searchnote");
        searchnote->resize(800, 600);
        label_searchnote = new QLabel(searchnote);
        label_searchnote->setObjectName("label_searchnote");
        label_searchnote->setGeometry(QRect(30, 40, 300, 20));
        label_searchnote->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        searchLineEdit_searchnote = new QLineEdit(searchnote);
        searchLineEdit_searchnote->setObjectName("searchLineEdit_searchnote");
        searchLineEdit_searchnote->setGeometry(QRect(30, 70, 551, 30));
        searchResultsListWidget_searchnote = new QListWidget(searchnote);
        searchResultsListWidget_searchnote->setObjectName("searchResultsListWidget_searchnote");
        searchResultsListWidget_searchnote->setGeometry(QRect(30, 110, 671, 381));
        searchResultsListWidget_searchnote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        backButton_searchnote = new QPushButton(searchnote);
        backButton_searchnote->setObjectName("backButton_searchnote");
        backButton_searchnote->setGeometry(QRect(40, 540, 100, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailReplySender));
        backButton_searchnote->setIcon(icon);
        searchButton_searchnote = new QPushButton(searchnote);
        searchButton_searchnote->setObjectName("searchButton_searchnote");
        searchButton_searchnote->setGeometry(QRect(600, 70, 100, 32));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditFind));
        searchButton_searchnote->setIcon(icon1);

        retranslateUi(searchnote);

        QMetaObject::connectSlotsByName(searchnote);
    } // setupUi

    void retranslateUi(QWidget *searchnote)
    {
        searchnote->setWindowTitle(QCoreApplication::translate("searchnote", "Suche Notizen", nullptr));
        label_searchnote->setText(QCoreApplication::translate("searchnote", "Geben Sie ein Suchwort ein:", nullptr));
        backButton_searchnote->setText(QCoreApplication::translate("searchnote", "Zur\303\274ck", nullptr));
        searchButton_searchnote->setText(QCoreApplication::translate("searchnote", "Suchen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class searchnote: public Ui_searchnote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEARCHNOTE_H
