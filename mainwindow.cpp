#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "deletenote.h"
#include "ui_mainwindow.h"
#include "note.h"
#include "notebook.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>

// Instanz von Notebook deklarieren
Notebook notebook;

// Konstruktor: Initialisiert die Benutzeroberfläche und prüft/verarbeitet Verzeichnisse
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Verzeichnisse für temporäre Dateien
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString tempDirPath = appDirPath + "/temp/";

    // Überprüfen und Erstellen des temp-Verzeichnisses
    if (!QDir(tempDirPath).exists()) {
        if (!QDir().mkpath(tempDirPath)) {
            QMessageBox::warning(this, "Fehler", "Das Verzeichnis 'temp' konnte nicht erstellt werden.");
        }
    }
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
MainWindow::~MainWindow() {
    delete ui;
}

// Getter-Methoden für die Buttons
QPushButton* MainWindow::getAddNoteButton() const { return ui->addNoteButton; }
QPushButton* MainWindow::getDisplayNotesButton() const { return ui->displayNotesButton; }
QPushButton* MainWindow::getEditNoteButton() const { return ui->editNoteButton; }
QPushButton* MainWindow::getDeleteNoteButton() const { return ui->deleteNoteButton; }
QPushButton* MainWindow::getExitButton() const { return ui->exitButton; }

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
