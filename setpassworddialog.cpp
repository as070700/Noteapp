#include "setpassworddialog.h"
#include "ui_setpassworddialog.h"
#include "utils.h" // Hilfsfunktionen wie hashPassword
#include <QCryptographicHash>
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QStandardPaths>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Slots
SetPasswordDialog::SetPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetPasswordDialog)
{
    ui->setupUi(this);

    // Setzt die Eingabefelder für das Passwort auf "versteckt"
    ui->passwordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit_setPasswordDialog->setEchoMode(QLineEdit::Password);

    // Verbindungen zwischen Buttons und Slots herstellen
    connect(ui->okButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_okButton_setPasswordDialog_clicked);
    connect(ui->cancelButton_setPasswordDialog, &QPushButton::clicked, this, &SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
SetPasswordDialog::~SetPasswordDialog()
{
    delete ui;
}

// Gibt den Passwort-Hash zurück
QString SetPasswordDialog::getPassword_setPasswordDialog() const
{
    return passwordHash_setPasswordDialog;
}

// Slot: Wird aufgerufen, wenn der OK-Button geklickt wird
void SetPasswordDialog::on_okButton_setPasswordDialog_clicked()
{
    qDebug() << "on_okButton_setPasswordDialog_clicked aufgerufen";

    // Passwort und Bestätigungspasswort aus den Eingabefeldern abrufen
    QString password_setPasswordDialog = ui->passwordLineEdit_setPasswordDialog->text();
    QString confirmPassword_setPasswordDialog = ui->confirmPasswordLineEdit_setPasswordDialog->text();

    // Überprüfen, ob die Passwörter übereinstimmen
    if (password_setPasswordDialog != confirmPassword_setPasswordDialog) {
        QMessageBox::warning(this, "Fehler", "Die Passwörter stimmen nicht überein.");
        return;
    }

    // Passwort hashen und speichern
    passwordHash_setPasswordDialog = hashPassword(password_setPasswordDialog);
    qDebug() << "Neues Passwort erstellt und gespeichert: " << passwordHash_setPasswordDialog;

    // Pfad zum Verzeichnis für Systemeinstellungen
    QString sysDirPath_setPasswordDialog = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath_setPasswordDialog + "/settings.ini", QSettings::IniFormat);

    // Speichern des Passwort-Hashes und der Sicherheitsantwort
    settings.setValue("passwordHash", passwordHash_setPasswordDialog);
    settings.setValue("securityAnswer", ui->securityAnswerLineEdit_setPasswordDialog->text());
    settings.sync(); // Sicherstellen, dass die Einstellungen geschrieben werden

    emit passwordSet_setPasswordDialog(); // Signal auslösen, dass das Passwort gesetzt wurde
    close(); // Dialog schließen
}

// Slot: Wird aufgerufen, wenn der Abbrechen-Button geklickt wird
void SetPasswordDialog::on_cancelButton_setPasswordDialog_clicked()
{
    qDebug() << "on_cancelButton_setPasswordDialog_clicked aufgerufen";
    close(); // Dialog schließen
}
