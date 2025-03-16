#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"
#include <QCryptographicHash>
#include <QMessageBox>

SetPasswordDialog::SetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPasswordDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit->setEchoMode(QLineEdit::Password);

    // Connect the accepted signal of buttonBox to the on_buttonBox_accepted slot
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &SetPasswordDialog::on_buttonBox_accepted);
}

SetPasswordDialog::~SetPasswordDialog()
{
    delete ui;
}

QString SetPasswordDialog::getPassword_setPasswordDialog() const
{
    return passwordHash;
}

void SetPasswordDialog::on_buttonBox_accepted()
{
    QString password = ui->passwordLineEdit->text();
    QString confirmPassword = ui->confirmPasswordLineEdit->text();

    if (password != confirmPassword) {
        QMessageBox::warning(this, "Fehler", "Die Passwörter stimmen nicht überein.");
        return;
    }

    QByteArray passwordBytes = password.toUtf8();
    passwordHash = QString(QCryptographicHash::hash(passwordBytes, QCryptographicHash::Sha256).toHex());
    accept();
}
