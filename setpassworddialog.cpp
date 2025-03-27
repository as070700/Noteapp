#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>

SetPasswordDialog::SetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPasswordDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::Password);

    // Connect the buttons to their respective slots
    connect(ui->okButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_okButton_setPasswordDialog_clicked);
    connect(ui->cancelButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked);
}

SetPasswordDialog::~SetPasswordDialog()
{
    delete ui;
}

QString SetPasswordDialog::getPassword_setPasswordDialog() const
{
    return passwordHash;
}

void SetPasswordDialog::on_okButton_setPasswordDialog_clicked()
{
    qDebug() << "on_okButton_setPasswordDialog_clicked called";

    QString password = ui->passwordLineEdit_setPasswordDialog->text();
    QString confirmPassword = ui->confirmPasswordLineEdit_setPasswordDialog->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Fehler", "Die Passwörter stimmen nicht überein.");
        return;
    }

    QByteArray passwordBytes = password.toUtf8();
    passwordHash = QString(QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256).toHex());
    emit passwordSet(); // Signal emitten
    close(); // Dialog schließen
}

void SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked()
{
    qDebug() << "on_cancelButton_setPasswordDialog_clicked called";
    close(); // Dialog schließen
}
