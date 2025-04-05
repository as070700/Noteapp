/* #include "securityquestiondialog.h"
#include "ui_securityquestiondialog.h"
#include "utils.h"
#include <QMessageBox>
#include <QDebug>
#include <QSettings>
#include <QStandardPaths>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Slots
SecurityQuestionDialog::SecurityQuestionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecurityQuestionDialog)
{
    ui->setupUi(this);

    // Setzt die Eingabefelder für das Passwort auf "versteckt"
    ui->passwordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::Password);
    ui->confirmPasswordLineEdit_securityquestiondialog->setEchoMode(QLineEdit::Password);

    // Verbindungen zwischen Buttons und Slots herstellen
    connect(ui->okButton_securityquestiondialog, &QPushButton::clicked, this, &SecurityQuestionDialog::on_okButton_securityquestiondialog_clicked);
    connect(ui->cancelButton_securityquestiondialog, &QPushButton::clicked, this, &SecurityQuestionDialog::on_cancelButton_securityquestiondialog_clicked);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
SecurityQuestionDialog::~SecurityQuestionDialog()
{
    delete ui;
}

// Gibt die eingegebene Antwort auf die Sicherheitsfrage zurück
QString SecurityQuestionDialog::getAnswer_securityquestiondialog() const
{
    return ui->securityAnswerLineEdit_securityquestiondialog->text();
}

// Slot: Wird aufgerufen, wenn der OK-Button geklickt wird
void SecurityQuestionDialog::on_okButton_securityquestiondialog_clicked()
{
    // Pfad zum Verzeichnis mit den Systemeinstellungen
    QString sysDirPath_securityquestiondialog = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath_securityquestiondialog + "/settings.ini", QSettings::IniFormat);

    // Die korrekte Antwort aus den Einstellungen abrufen
    QString correctAnswer_securityquestiondialog = settings.value("securityAnswer").toString();

    // Die vom Benutzer eingegebene Antwort abrufen
    QString enteredAnswer_securityquestiondialog = getAnswer_securityquestiondialog();

    // Überprüfen, ob die eingegebene Antwort korrekt ist
    if (enteredAnswer_securityquestiondialog == correctAnswer_securityquestiondialog) {
        emit answerCorrect_securityquestiondialog(); // Signal auslösen, wenn die Antwort korrekt ist
        close(); // Dialog schließen
    } else {
        // Warnung anzeigen, wenn die Antwort falsch ist
        QMessageBox::warning(this, "Fehler", "Falsche Antwort.");
    }
}

// Slot: Wird aufgerufen, wenn der Abbrechen-Button geklickt wird
void SecurityQuestionDialog::on_cancelButton_securityquestiondialog_clicked()
{
    close(); // Dialog schließen
}
 */