#include "getpassworddialog.h"
#include "ui_getpassworddialog.h" // Korrekte Einbindung der generierten Header-Datei

getPasswordDialog::getPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPasswordDialog)
{
    ui->setupUi(this);
}

getPasswordDialog::~getPasswordDialog()
{
    delete ui;
}

QString getPasswordDialog::getPassword_getPasswordDialog() const
{
    return ui->password_lineEdit_getpassworddialog->text();
}
