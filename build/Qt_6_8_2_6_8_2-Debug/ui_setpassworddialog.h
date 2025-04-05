/********************************************************************************
** Form generated from reading UI file 'setpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETPASSWORDDIALOG_H
#define UI_SETPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SetPasswordDialog
{
public:
    QLineEdit *passwordLineEdit_setPasswordDialog;
    QLineEdit *confirmPasswordLineEdit_setPasswordDialog;
    QLabel *securityQuestionLabel_setPasswordDialog;
    QLineEdit *securityAnswerLineEdit_setPasswordDialog;
    QPushButton *okButton_setPasswordDialog;
    QPushButton *cancelButton_setPasswordDialog;

    void setupUi(QDialog *SetPasswordDialog)
    {
        if (SetPasswordDialog->objectName().isEmpty())
            SetPasswordDialog->setObjectName("SetPasswordDialog");
        SetPasswordDialog->resize(400, 300);
        passwordLineEdit_setPasswordDialog = new QLineEdit(SetPasswordDialog);
        passwordLineEdit_setPasswordDialog->setObjectName("passwordLineEdit_setPasswordDialog");
        passwordLineEdit_setPasswordDialog->setGeometry(QRect(50, 50, 300, 30));
        passwordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::EchoMode::Password);
        confirmPasswordLineEdit_setPasswordDialog = new QLineEdit(SetPasswordDialog);
        confirmPasswordLineEdit_setPasswordDialog->setObjectName("confirmPasswordLineEdit_setPasswordDialog");
        confirmPasswordLineEdit_setPasswordDialog->setGeometry(QRect(50, 90, 300, 30));
        confirmPasswordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::EchoMode::Password);
        securityQuestionLabel_setPasswordDialog = new QLabel(SetPasswordDialog);
        securityQuestionLabel_setPasswordDialog->setObjectName("securityQuestionLabel_setPasswordDialog");
        securityQuestionLabel_setPasswordDialog->setGeometry(QRect(50, 130, 300, 20));
        securityAnswerLineEdit_setPasswordDialog = new QLineEdit(SetPasswordDialog);
        securityAnswerLineEdit_setPasswordDialog->setObjectName("securityAnswerLineEdit_setPasswordDialog");
        securityAnswerLineEdit_setPasswordDialog->setGeometry(QRect(50, 150, 300, 30));
        okButton_setPasswordDialog = new QPushButton(SetPasswordDialog);
        okButton_setPasswordDialog->setObjectName("okButton_setPasswordDialog");
        okButton_setPasswordDialog->setGeometry(QRect(100, 200, 75, 30));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        okButton_setPasswordDialog->setIcon(icon);
        cancelButton_setPasswordDialog = new QPushButton(SetPasswordDialog);
        cancelButton_setPasswordDialog->setObjectName("cancelButton_setPasswordDialog");
        cancelButton_setPasswordDialog->setGeometry(QRect(200, 200, 111, 31));
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        cancelButton_setPasswordDialog->setIcon(icon1);

        retranslateUi(SetPasswordDialog);
        QObject::connect(okButton_setPasswordDialog, SIGNAL(clicked()), SetPasswordDialog, SLOT(on_okButton_setPasswordDialog_clicked()));
        QObject::connect(cancelButton_setPasswordDialog, SIGNAL(clicked()), SetPasswordDialog, SLOT(on_cancelButton_setPasswordDialog_clicked()));

        QMetaObject::connectSlotsByName(SetPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *SetPasswordDialog)
    {
        SetPasswordDialog->setWindowTitle(QCoreApplication::translate("SetPasswordDialog", "Passwort setzen", nullptr));
        securityQuestionLabel_setPasswordDialog->setText(QCoreApplication::translate("SetPasswordDialog", "Was ist der Name Ihres ersten Haustiers?", nullptr));
        okButton_setPasswordDialog->setText(QCoreApplication::translate("SetPasswordDialog", "Okay", nullptr));
        cancelButton_setPasswordDialog->setText(QCoreApplication::translate("SetPasswordDialog", "Abbrechen", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SetPasswordDialog: public Ui_SetPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETPASSWORDDIALOG_H
