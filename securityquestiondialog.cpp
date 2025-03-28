#include "securityquestiondialog.h"
#include "ui_securityquestiondialog.h"
#include "utils.h"
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QStandardPaths>

SecurityQuestionDialog::SecurityQuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecurityQuestionDialog)
{
    ui->setupUi(this);
    ui->passwordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::Password);

    // Connect the buttons to their respective slots
    connect(ui->okButton_securityquestiondialog, &QPushButton::clicked, this, &::SecurityQuestionDialog::on_okButton_securityquestiondialog_clicked);
    connect(ui->cancelButton_securityquestiondialog, &QPushButton::clicked, this, &SecurityQuestionDialog::on_cancelButton_securityquestiondialog_clicked);
}

SecurityQuestionDialog::~SecurityQuestionDialog()
{
    delete ui;
}

QString SecurityQuestionDialog::getAnswer_securityquestiondialog() const
{
    return ui->securityAnswerLineEdit_securityquestiondialog->text();
}

void SecurityQuestionDialog::on_okButton_securityquestiondialog_clicked()
{
    QString sysDirPath_securityquestiondialog = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath_securityquestiondialog + "/settings.ini", QSettings::IniFormat);
    QString correctAnswer_securityquestiondialog = settings.value("securityAnswer").toString();

    QString enteredAnswer_securityquestiondialog = getAnswer_securityquestiondialog();
    if (enteredAnswer_securityquestiondialog == correctAnswer_securityquestiondialog) {
        emit answerCorrect_securityquestiondialog(); // Signal emitten
        close(); // Dialog schließen
    } else {
        QMessageBox::warning(this, "Fehler", "Falsche Antwort.");
    }
}

void SecurityQuestionDialog::on_cancelButton_securityquestiondialog_clicked()
{
    close();
}
