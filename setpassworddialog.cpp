#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"
#include "utils.h"
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QStandardPaths>

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
    return passwordHash_setPasswordDialog;
}

void SetPasswordDialog::on_okButton_setPasswordDialog_clicked()
{
    qDebug() << "on_okButton_setPasswordDialog_clicked called";

    QString password_setPasswordDialog = ui->passwordLineEdit_setPasswordDialog->text();
    QString confirmPassword_setPasswordDialog = ui->confirmPasswordLineEdit_setPasswordDialog->text();

    if (password_setPasswordDialog != confirmPassword_setPasswordDialog) {
        QMessageBox::warning(this, "Fehler", "Die Passwörter stimmen nicht überein.");
        return;
    }

    passwordHash_setPasswordDialog = hashPassword(password_setPasswordDialog);

    qDebug() << "Neues Passwort erstellt und gespeichert: " << passwordHash_setPasswordDialog;

    // Speichern des Passwort-Hashes und der Sicherheitsfrage/-antwort in den Einstellungen
    QString sysDirPath_setPasswordDialog = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath_setPasswordDialog + "/settings.ini", QSettings::IniFormat);
    settings.setValue("passwordHash", passwordHash_setPasswordDialog);
    settings.setValue("securityAnswer", ui->securityAnswerLineEdit_setPasswordDialog->text());
    settings.sync();  // Sicherstellen, dass die Einstellungen geschrieben werden

    emit passwordSet_setPasswordDialog(); // Signal emitten
    close(); // Dialog schließen
}

void SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked()
{
    qDebug() << "on_cancelButton_setPasswordDialog_clicked called";
    close(); // Dialog schließen
}
