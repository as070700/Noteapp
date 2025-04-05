/*
#include "getpassworddialog.h"
#include "ui_getpassworddialog.h"
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Slots
getPasswordDialog::getPasswordDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getPasswordDialog)
{
    ui->setupUi(this);

    // Verbindungen zwischen Buttons und Funktionen herstellen
    connect(ui->okButton_getpassworddialog, &QPushButton::clicked, this, &getPasswordDialog::on_okButton_getpassworddialog_clicked);
    connect(ui->cancelButton_getpassworddialog, &QPushButton::clicked, this, &getPasswordDialog::on_cancelButton_getpassworddialog_clicked);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
getPasswordDialog::~getPasswordDialog()
{
    delete ui;
}

// Gibt das eingegebene Passwort zurück
QString getPasswordDialog::getPassword_getPasswordDialog() const
{
    return ui->password_lineEdit_getpassworddialog->text(); // Passwort aus dem Eingabefeld abrufen
}

// Slot: OK-Button - Überprüft das eingegebene Passwort
void getPasswordDialog::on_okButton_getpassworddialog_clicked()
{
    // Pfad zum Verzeichnis mit den Einstellungen
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

    // Den gespeicherten Passwort-Hash abrufen
    QString correctHash = settings.value("passwordHash").toString();

    // Passwort aus dem Eingabefeld abrufen
    QString passwordHash = getPassword_getPasswordDialog();

    // Überprüfen, ob der eingegebene Hash mit dem gespeicherten Hash übereinstimmt
    if (passwordHash == correctHash) {
        emit passwordCorrect_getpassworddialog(); // Signal auslösen, wenn das Passwort korrekt ist
        close(); // Dialog schließen
    } else {
        // Warnung anzeigen, wenn das Passwort falsch ist
        QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
    }
}

// Slot: Abbrechen-Button - Schließt den Dialog
void getPasswordDialog::on_cancelButton_getpassworddialog_clicked()
{
    close(); // Dialog schließen
}
*/
