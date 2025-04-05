/********************************************************************************
** Form generated from reading UI file 'detailshownote.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILSHOWNOTE_H
#define UI_DETAILSHOWNOTE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_detailShownote
{
public:
    QTextEdit *content_textEdit_detailshownote;
    QPushButton *backButton_detailshownote;
    QLabel *label_title_detailshownote;
    QCheckBox *passwordProtectionCheckBox_detailshownote;
    QLabel *errorLabel_detailshownote;

    void setupUi(QDialog *detailShownote)
    {
        if (detailShownote->objectName().isEmpty())
            detailShownote->setObjectName("detailShownote");
        detailShownote->resize(800, 600);
        content_textEdit_detailshownote = new QTextEdit(detailShownote);
        content_textEdit_detailshownote->setObjectName("content_textEdit_detailshownote");
        content_textEdit_detailshownote->setGeometry(QRect(30, 50, 731, 451));
        content_textEdit_detailshownote->viewport()->setProperty("cursor", QVariant(QCursor(Qt::CursorShape::PointingHandCursor)));
        content_textEdit_detailshownote->setStyleSheet(QString::fromUtf8("background: transparent"));
        content_textEdit_detailshownote->setReadOnly(true);
        backButton_detailshownote = new QPushButton(detailShownote);
        backButton_detailshownote->setObjectName("backButton_detailshownote");
        backButton_detailshownote->setGeometry(QRect(670, 550, 100, 32));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::MailReplied));
        backButton_detailshownote->setIcon(icon);
        backButton_detailshownote->setIconSize(QSize(18, 16));
        label_title_detailshownote = new QLabel(detailShownote);
        label_title_detailshownote->setObjectName("label_title_detailshownote");
        label_title_detailshownote->setGeometry(QRect(30, 20, 741, 20));
        passwordProtectionCheckBox_detailshownote = new QCheckBox(detailShownote);
        passwordProtectionCheckBox_detailshownote->setObjectName("passwordProtectionCheckBox_detailshownote");
        passwordProtectionCheckBox_detailshownote->setGeometry(QRect(646, 15, 131, 25));
        passwordProtectionCheckBox_detailshownote->setCheckable(false);
        errorLabel_detailshownote = new QLabel(detailShownote);
        errorLabel_detailshownote->setObjectName("errorLabel_detailshownote");
        errorLabel_detailshownote->setGeometry(QRect(410, 510, 351, 31));

        retranslateUi(detailShownote);

        QMetaObject::connectSlotsByName(detailShownote);
    } // setupUi

    void retranslateUi(QDialog *detailShownote)
    {
        detailShownote->setWindowTitle(QCoreApplication::translate("detailShownote", "Detail Show Note", nullptr));
        backButton_detailshownote->setText(QCoreApplication::translate("detailShownote", "Zur\303\274ck", nullptr));
        passwordProtectionCheckBox_detailshownote->setText(QCoreApplication::translate("detailShownote", "Notiz gesch\303\274tzt?", nullptr));
        errorLabel_detailshownote->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class detailShownote: public Ui_detailShownote {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILSHOWNOTE_H
