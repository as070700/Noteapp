#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"
#include <QCryptographicHash>
#include <QDebug>

SetPasswordDialog::SetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPasswordDialog)
{
    ui->setupUi(this);

    // Connect the buttons to their respective slots
    connect(ui->okButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_okButton_setPasswordDialog_clicked);
    connect(ui->cancelButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked);
}

SetPasswordDialog::~SetPasswordDialog() {
    delete ui;
}

QString SetPasswordDialog::getPassword_setPasswordDialog() const {
    return passwordHash;
}

void SetPasswordDialog::on_okButton_setPasswordDialog_clicked() {
    QString password = ui->passwordLineEdit_setPasswordDialog->text();
    passwordHash = QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
    qDebug() << "Password hash set:" << passwordHash;
    accept();
}

void SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked() {
    reject();
}
