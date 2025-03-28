#include "getpassworddialog.h"
#include "setpassworddialog.h"
#include "ui_getpassworddialog.h"
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>
#include <QInputDialog>
#include <QDebug>
#include <QCryptographicHash>

getPasswordDialog::getPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPasswordDialog)
{
    ui->setupUi(this);
    connect(ui->okButton_getpassworddialog, &QPushButton::clicked, this, &getPasswordDialog::on_okButton_getpassworddialog_clicked);
    connect(ui->cancelButton_getpassworddialog, &QPushButton::clicked, this, &getPasswordDialog::on_cancelButton_getpassworddialog_clicked);
}

getPasswordDialog::~getPasswordDialog()
{
    delete ui;
}

QString getPasswordDialog::getPassword_getPasswordDialog() const
{
    return ui->password_lineEdit_getpassworddialog->text();
}

QString hashPassword(const QString &password) {
    return QString(QCryptographicHash::hash(password.toUtf8(), QCryptographicHash::Sha256).toHex());
}

void getPasswordDialog::on_okButton_getpassworddialog_clicked()
{
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    qDebug() << "System Directory Path: " << sysDirPath;

    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    if (!settings.contains("passwordHash")) {
        SetPasswordDialog setPasswordDialog(this);
        if (setPasswordDialog.exec() == QDialog::Accepted) {
            QString hashedPassword = setPasswordDialog.getPassword_setPasswordDialog();
            settings.setValue("passwordHash", hashedPassword);
            qDebug() << "Neues Passwort erstellt und gespeichert: " << hashedPassword;
            QMessageBox::information(this, "Erfolg", "Neues Passwort wurde erstellt und gespeichert.");
            emit passwordCorrect(); // Signal emitten
            accept(); // Dialog schließen
        } else {
            QMessageBox::warning(this, "Fehler", "Kein Passwort eingegeben. Vorgang abgebrochen.");
        }
        return;
    }

    QString correctHash = settings.value("passwordHash").toString();
    qDebug() << "Correct Hash: " << correctHash;

    QString enteredPassword = getPassword_getPasswordDialog();
    QString enteredHash = hashPassword(enteredPassword);
    qDebug() << "Entered Password Hash: " << enteredHash;

    if (enteredHash == correctHash) {
        emit passwordCorrect(); // Signal emitten
        accept(); // Dialog schließen
    } else {
        QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
    }
}

void getPasswordDialog::on_cancelButton_getpassworddialog_clicked()
{
    reject();
}
