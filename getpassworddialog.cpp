#include "getpassworddialog.h"
#include "ui_getpassworddialog.h"
#include "utils.h"  // Hinzufügen dieser Zeile
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>
#include <QDebug>

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

QString getPasswordDialog::getPassword_getpassworddialog() const
{
    return ui->password_lineEdit_getpassworddialog->text();
}

void getPasswordDialog::on_okButton_getpassworddialog_clicked()
{
    QString sysDirPath_getpassworddialog = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath_getpassworddialog + "/settings.ini", QSettings::IniFormat);
    QString correctHash_getpassworddialog = settings.value("passwordHash").toString();

    QString enteredPassword_getpassworddialog = getPassword_getpassworddialog();
    QString enteredHash_getpassworddialog = hashPassword(enteredPassword_getpassworddialog);  // Nutzung der Funktion aus utils.h

    if (enteredHash_getpassworddialog == correctHash_getpassworddialog) {
        emit passwordCorrect_getpassworddialog(); // Signal emitten
        accept();  // Schließt den Dialog korrekt
    } else {
        emit passwortIncorrect_getpassworddialog(); // Neues Signal für Fehler
    }
}


void getPasswordDialog::on_cancelButton_getpassworddialog_clicked()
{
    reject();
}
