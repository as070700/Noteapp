#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "deletenote.h"
// #include "setpassworddialog.h" // Auskommentiert, da es mit dem Passwortsystem zusammenhängt
// #include "getpassworddialog.h" // Auskommentiert, da es mit dem Passwortsystem zusammenhängt
// #include "securityquestiondialog.h" // Auskommentiert, da es mit dem Passwortsystem zusammenhängt
#include "ui_mainwindow.h"
#include "note.h"
#include "notebook.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QSettings>

// Instanz von Notebook deklarieren
Notebook notebook;

// Konstruktor: Initialisiert die Benutzeroberfläche und prüft/verarbeitet Verzeichnisse und Einstellungen
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "MainWindow initialisiert";

    // Verzeichnisse für Einstellungen und temporäre Dateien
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QString tempDirPath = appDirPath + "/temp/";

    // Überprüfen und Erstellen des sys-Verzeichnisses
    if (!QDir(sysDirPath).exists()) {
        if (QDir().mkpath(sysDirPath)) {
            qDebug() << "Verzeichnis 'sys' erstellt:" << sysDirPath;
        } else {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses 'sys':" << sysDirPath;
        }
    }

    // Überprüfen und Erstellen des temp-Verzeichnisses
    if (!QDir(tempDirPath).exists()) {
        if (QDir().mkpath(tempDirPath)) {
            qDebug() << "Verzeichnis 'temp' erstellt:" << tempDirPath;
        } else {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses 'temp':" << tempDirPath;
        }
    }

    // Initialisieren von QSettings
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    qDebug() << "QSettings Pfad: " << settings.fileName();

    // Überprüfen, ob die Einstellungsdatei beschreibbar ist
    QFile settingsFile(settings.fileName());
    if (!settingsFile.open(QIODevice::ReadWrite)) {
        qDebug() << "Fehler beim Öffnen der Einstellungsdatei zum Schreiben:" << settings.fileName();
    } else {
        qDebug() << "Einstellungsdatei ist beschreibbar";
        settingsFile.close();
    }

    // Verbindungen für Passwortaktionen
    /*
    connect(ui->setPasswordAction, &QAction::triggered, this, &MainWindow::setPassword);
    connect(ui->resetPasswordAction, &QAction::triggered, this, &MainWindow::resetPassword);
    */
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
MainWindow::~MainWindow() {
    qDebug() << "MainWindow zerstört";
    delete ui;
}

// Methode zum Setzen eines Passworts
/*
void MainWindow::setPassword() {
    qDebug() << "SetPasswordAction ausgelöst";
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

    // Überprüfen, ob ein Passwort bereits gesetzt ist
    if (settings.contains("passwordHash")) {
        getPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString enteredPasswordHash = passwordDialog.getPassword_getPasswordDialog();
            QString correctPasswordHash = settings.value("passwordHash").toString();
            if (enteredPasswordHash != correctPasswordHash) {
                QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
                return;
            }
        } else {
            return;
        }
    }

    // Neues Passwort setzen
    SetPasswordDialog setPasswordDialog(this);
    if (setPasswordDialog.exec() == QDialog::Accepted) {
        QString newPasswordHash = setPasswordDialog.getPassword_setPasswordDialog();
        settings.setValue("passwordHash", newPasswordHash);
        settings.sync();
        qDebug() << "Neues Passwort gesetzt.";
    }
}
*/

// Methode zum Zurücksetzen des Passworts
/*
void MainWindow::resetPassword() {
    qDebug() << "ResetPasswordAction ausgelöst";
    SecurityQuestionDialog securityDialog(this);
    if (securityDialog.exec() == QDialog::Accepted) {
        SetPasswordDialog setPasswordDialog(this);
        if (setPasswordDialog.exec() == QDialog::Accepted) {
            QString newPasswordHash = setPasswordDialog.getPassword_setPasswordDialog();
            QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
            QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
            settings.setValue("passwordHash", newPasswordHash);
            settings.sync();
            qDebug() << "Passwort zurückgesetzt.";
        }
    }
}
*/

// Getter-Methoden für die Buttons
QPushButton* MainWindow::getAddNoteButton() const { return ui->addNoteButton; }
QPushButton* MainWindow::getDisplayNotesButton() const { return ui->displayNotesButton; }
QPushButton* MainWindow::getEditNoteButton() const { return ui->editNoteButton; }
QPushButton* MainWindow::getDeleteNoteButton() const { return ui->deleteNoteButton; }
QPushButton* MainWindow::getExitButton() const { return ui->exitButton; }
// QAction* MainWindow::getSetPasswordAction() const { return ui->setPasswordAction; } // Auskommentiert, da es mit dem Passwortsystem zusammenhängt

// Slot: "Notiz hinzufügen"-Button
void MainWindow::on_addNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    NewNote *newNoteDialog = new NewNote(this);

    // Verbindung herstellen: Wenn die Notiz gespeichert wird, setze den Text im Label
    connect(newNoteDialog, &NewNote::noteSaved, this, [this]() {
        ui->errorLabel_mainwindow->setText("Erfolg: Die Notiz wurde gespeichert.");
        ui->errorLabel_mainwindow->setStyleSheet("color: green;");
    });

    newNoteDialog->exec(); // Dialog öffnen
}

// Slot: "Notizen anzeigen"-Button
void MainWindow::on_displayNotesButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    shownote *noteWidget_show = new shownote(this);
    noteWidget_show->show();
    getAddNoteButton()->hide();
    getDisplayNotesButton()->hide();
    getEditNoteButton()->hide();
    getDeleteNoteButton()->hide();
    getExitButton()->hide();
}

// Slot: "Notiz bearbeiten"-Button
void MainWindow::on_editNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    editnote *noteWidget_edit = new editnote(this);
    noteWidget_edit->show();
    getAddNoteButton()->hide();
    getDisplayNotesButton()->hide();
    getEditNoteButton()->hide();
    getDeleteNoteButton()->hide();
    getExitButton()->hide();
}

// Slot: "Notiz löschen"-Button
void MainWindow::on_deleteNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    deletenote *noteWidget_delete = new deletenote(this);
    noteWidget_delete->show();
    getAddNoteButton()->hide();
    getDisplayNotesButton()->hide();
    getEditNoteButton()->hide();
    getDeleteNoteButton()->hide();
    getExitButton()->hide();
}

// Zeigt das Hauptmenü an
void MainWindow::showMainMenu() {
    this->show();
    getAddNoteButton()->show();
    getDisplayNotesButton()->show();
    getEditNoteButton()->show();
    getDeleteNoteButton()->show();
    getExitButton()->show();
}
