/********************************************************************************
** Form generated from reading UI file 'getpassworddialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETPASSWORDDIALOG_H
#define UI_GETPASSWORDDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_getPasswordDialog
{
public:
    QLineEdit *password_lineEdit_getpassworddialog;
    QPushButton *okButton_getpassworddialog;
    QPushButton *cancelButton_getpassworddialog;
    QLabel *label;

    void setupUi(QDialog *getPasswordDialog)
    {
        if (getPasswordDialog->objectName().isEmpty())
            getPasswordDialog->setObjectName("getPasswordDialog");
        getPasswordDialog->resize(400, 200);
        password_lineEdit_getpassworddialog = new QLineEdit(getPasswordDialog);
        password_lineEdit_getpassworddialog->setObjectName("password_lineEdit_getpassworddialog");
        password_lineEdit_getpassworddialog->setGeometry(QRect(50, 50, 300, 30));
        password_lineEdit_getpassworddialog->setEchoMode(QLineEdit::EchoMode::Password);
        okButton_getpassworddialog = new QPushButton(getPasswordDialog);
        okButton_getpassworddialog->setObjectName("okButton_getpassworddialog");
        okButton_getpassworddialog->setGeometry(QRect(100, 150, 75, 30));
        QIcon icon(QIcon::fromTheme(QIcon::ThemeIcon::SyncSynchronizing));
        okButton_getpassworddialog->setIcon(icon);
        cancelButton_getpassworddialog = new QPushButton(getPasswordDialog);
        cancelButton_getpassworddialog->setObjectName("cancelButton_getpassworddialog");
        cancelButton_getpassworddialog->setGeometry(QRect(199, 150, 101, 30));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(cancelButton_getpassworddialog->sizePolicy().hasHeightForWidth());
        cancelButton_getpassworddialog->setSizePolicy(sizePolicy);
        cancelButton_getpassworddialog->setTabletTracking(false);
        cancelButton_getpassworddialog->setAcceptDrops(false);
        cancelButton_getpassworddialog->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        QIcon icon1(QIcon::fromTheme(QIcon::ThemeIcon::EditUndo));
        cancelButton_getpassworddialog->setIcon(icon1);
        cancelButton_getpassworddialog->setAutoDefault(true);
        cancelButton_getpassworddialog->setFlat(false);
        label = new QLabel(getPasswordDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 20, 211, 16));

        retranslateUi(getPasswordDialog);
        QObject::connect(okButton_getpassworddialog, SIGNAL(clicked()), getPasswordDialog, SLOT(on_okButton_getPasswordDialog_clicked()));
        QObject::connect(cancelButton_getpassworddialog, SIGNAL(clicked()), getPasswordDialog, SLOT(on_cancelButton_getPasswordDialog_clicked()));

        cancelButton_getpassworddialog->setDefault(false);


        QMetaObject::connectSlotsByName(getPasswordDialog);
    } // setupUi

    void retranslateUi(QDialog *getPasswordDialog)
    {
        getPasswordDialog->setWindowTitle(QCoreApplication::translate("getPasswordDialog", "Passwort eingeben", nullptr));
        okButton_getpassworddialog->setText(QCoreApplication::translate("getPasswordDialog", "Okay", nullptr));
        cancelButton_getpassworddialog->setText(QCoreApplication::translate("getPasswordDialog", "Abbrechen", nullptr));
        label->setText(QCoreApplication::translate("getPasswordDialog", "Passwort bitte angeben: ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class getPasswordDialog: public Ui_getPasswordDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETPASSWORDDIALOG_H
