/********************************************************************************
** Form generated from reading UI file 'securityquestiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SECURITYQUESTIONDIALOG_H
#define UI_SECURITYQUESTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SecurityQuestionDialog
{
public:
    QLineEdit *passwordLineEdit_securityquestiondialog;
    QLineEdit *confirmPasswordLineEdit_securityquestiondialog;
    QLabel *securityQuestionLabel_securityquestiondialog;
    QLineEdit *securityAnswerLineEdit_securityquestiondialog;
    QPushButton *okButton_securityquestiondialog;
    QPushButton *cancelButton_securityquestiondialog;

    void setupUi(QDialog *SecurityQuestionDialog)
    {
        if (SecurityQuestionDialog->objectName().isEmpty())
            SecurityQuestionDialog->setObjectName("SecurityQuestionDialog");
        SecurityQuestionDialog->resize(400, 300);
        passwordLineEdit_securityquestiondialog = new QLineEdit(SecurityQuestionDialog);
        passwordLineEdit_securityquestiondialog->setObjectName("passwordLineEdit_securityquestiondialog");
        passwordLineEdit_securityquestiondialog->setGeometry(QRect(50, 50, 300, 30));
        passwordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::EchoMode::Password);
        confirmPasswordLineEdit_securityquestiondialog = new QLineEdit(SecurityQuestionDialog);
        confirmPasswordLineEdit_securityquestiondialog->setObjectName("confirmPasswordLineEdit_securityquestiondialog");
        confirmPasswordLineEdit_securityquestiondialog->setGeometry(QRect(50, 90, 300, 30));
        confirmPasswordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::EchoMode::Password);
        securityQuestionLabel_securityquestiondialog = new QLabel(SecurityQuestionDialog);
        securityQuestionLabel_securityquestiondialog->setObjectName("securityQuestionLabel_securityquestiondialog");
        securityQuestionLabel_securityquestiondialog->setGeometry(QRect(50, 130, 300, 20));
        securityAnswerLineEdit_securityquestiondialog = new QLineEdit(SecurityQuestionDialog);
        securityAnswerLineEdit_securityquestiondialog->setObjectName("securityAnswerLineEdit_securityquestiondialog");
        securityAnswerLineEdit_securityquestiondialog->setGeometry(QRect(50, 150, 300, 30));
        okButton_securityquestiondialog = new QPushButton(SecurityQuestionDialog);
        okButton_securityquestiondialog->setObjectName("okButton_securityquestiondialog");
        okButton_securityquestiondialog->setGeometry(QRect(100, 200, 75, 30));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        okButton_securityquestiondialog->setIcon(icon);
        cancelButton_securityquestiondialog = new QPushButton(SecurityQuestionDialog);
        cancelButton_securityquestiondialog->setObjectName("cancelButton_securityquestiondialog");
        cancelButton_securityquestiondialog->setGeometry(QRect(200, 200, 101, 31));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        cancelButton_securityquestiondialog->setIcon(icon1);

        retranslateUi(SecurityQuestionDialog);
        QObject::connect(okButton_securityquestiondialog, SIGNAL(clicked()), SecurityQuestionDialog, SLOT(on_okButton_securityquestiondialog_clicked()));
        QObject::connect(cancelButton_securityquestiondialog, SIGNAL(clicked()), SecurityQuestionDialog, SLOT(on_cancelButton_securityquestiondialog_clicked()));

        QMetaObject::connectSlotsByName(SecurityQuestionDialog);
    } // setupUi

    void retranslateUi(QDialog *SecurityQuestionDialog)
    {
        SecurityQuestionDialog->setWindowTitle(QCoreApplication::translate("SecurityQuestionDialog", "Passwort setzen", nullptr));
        securityQuestionLabel_securityquestiondialog->setText(QCoreApplication::translate("SecurityQuestionDialog", "Was ist der Name Ihres ersten Haustiers?", nullptr));
        okButton_securityquestiondialog->setText(QCoreApplication::translate("SecurityQuestionDialog", "Okay", nullptr));
        cancelButton_securityquestiondialog->setText(QCoreApplication::translate("SecurityQuestionDialog", "Abbrechen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SecurityQuestionDialog: public Ui_SecurityQuestionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SECURITYQUESTIONDIALOG_H
