#include "getpassworddialog.h"
#include "ui_getpassworddialog.h"
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>

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

void getPasswordDialog::on_okButton_getpassworddialog_clicked()
{
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    QString correctHash = settings.value("passwordHash").toString();

    QString passwordHash = getPassword_getPasswordDialog();
    if (passwordHash == correctHash) {
        emit passwordCorrect_getpassworddialog(); // Signal emitten
        close(); // Dialog schließen
    } else {
        QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
    }
}

void getPasswordDialog::on_cancelButton_getpassworddialog_clicked()
{
    close();
}
