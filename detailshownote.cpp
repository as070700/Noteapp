#include "detailshownote.h"
#include "getpassworddialog.h"
#include "ui_detailshownote.h"
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet den Zurück-Button mit der Schließen-Funktion
detailShownote::detailShownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailShownote)
{
    ui->setupUi(this);

    // Verbindung des Zurück-Buttons mit der Schließen-Funktion
    connect(ui->backButton_detailshownote, &QPushButton::clicked, this, &QDialog::reject);

    // Setzt den Hintergrund des Textfelds auf transparent
    ui->content_textEdit_detailshownote->setStyleSheet("background: transparent");
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
detailShownote::~detailShownote()
{
    delete ui;
}

// Setzt den Titel und den Inhalt der Notiz
void detailShownote::setNoteContent_show(const QString &title, const QString &content) {
    ui->label_title_detailshownote->setText(title); // Setzt den Titel der Notiz

    // Überprüfen, ob die Notiz passwortgeschützt ist
    QRegularExpression protectedRegex("<!--\\s*protected:\\s*(true|false)\\s*-->");
    QRegularExpressionMatch match = protectedRegex.match(content);
    bool isProtected = match.hasMatch() && match.captured(1) == "true";
    ui->passwordProtectionCheckBox_detailshownote->setChecked(isProtected);

    qDebug() << "HTML-Inhalt:" << content;
    qDebug() << "Passwortschutz erkannt:" << isProtected;

    // Entfernt den Passwortschutz-Kommentar aus dem angezeigten Inhalt
    QString cleanedContent = content;
    cleanedContent.remove(protectedRegex);
    ui->content_textEdit_detailshownote->setHtml(cleanedContent);

    // Deaktiviert die Checkbox, damit der Benutzer sie nicht ändern kann
    ui->passwordProtectionCheckBox_detailshownote->setEnabled(false);
}

// Lädt den Inhalt der Notiz aus einer Datei
void detailShownote::loadNoteContent_detailshownote(const QString &noteTitle, const QString &noteContent) {
    QString filePath = "./temp/" + noteTitle + ".html"; // Pfad zur HTML-Datei
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->errorLabel_detailshownote->setText("Fehler: Konnte Datei nicht öffnen: " + filePath);
        ui->errorLabel_detailshownote->setStyleSheet("color: red;"); // Fehler in Rot anzeigen
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Überprüfen, ob die Notiz passwortgeschützt ist
    QRegularExpression protectedRegex("<!--\\s*protected:\\s*true\\s*-->");
    bool isProtected = protectedRegex.match(content).hasMatch();

    if (isProtected) {
        // Passwortabfrage, wenn die Notiz geschützt ist
        QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
        QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

        // Passwortabfrage-Dialog
        getPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString enteredPasswordHash = passwordDialog.getPassword_getPasswordDialog();
            QString correctPasswordHash = settings.value("passwordHash").toString();

            if (enteredPasswordHash != correctPasswordHash) {
                ui->errorLabel_detailshownote->setText("Fehler: Falsches Passwort.");
                return; // Abbrechen, wenn der Benutzer den Dialog schließt
            }
        } else {
            ui->errorLabel_detailshownote->setText("Fehler: Passwortabfrage abgebrochen.");
            return; // Abbrechen, wenn der Benutzer den Dialog schließt
        }
    }

// Setzt den Titel und den Inhalt der Notiz
    setNoteContent_show(noteTitle, content);
}

// Überprüft, ob die Notiz passwortgeschützt ist
bool detailShownote::isNotePasswordProtected_detailshownote(const QString &noteTitle) {
    // Beispielhafte Logik: Passwortgeschützte Notizen haben ein bestimmtes Präfix
    return noteTitle.startsWith("[Protected]");
}

