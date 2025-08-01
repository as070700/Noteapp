// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "deletenote.h"
#include "ui_mainwindow.h"
// #include "old_notebook.h"
#include <QInputDialog>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QStandardPaths>

// Instanz von Notebook deklarieren
// Diese Instanz wird nicht mehr benötigt, da die Methoden in neuen Klassen verarbeitet werden.
// Notebook notebook;

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
            ui->errorLabel_mainwindow->setText("Fehler: Das Verzeichnis 'temp' konnte nicht erstellt werden.");
            ui->errorLabel_mainwindow->setStyleSheet("color: red;");
        }
    }
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
MainWindow::~MainWindow() {
    delete ui;
}

// Getter-Methoden für die Buttons
QPushButton* MainWindow::getAddNoteButton_MainWindow() const { return ui->addNoteButton; }
QPushButton* MainWindow::getDisplayNotesButton_MainWindow() const { return ui->displayNotesButton; }
QPushButton* MainWindow::getEditNoteButton_MainWindow() const { return ui->editNoteButton; }
QPushButton* MainWindow::getDeleteNoteButton_MainWindow() const { return ui->deleteNoteButton; }
QPushButton* MainWindow::getExitButton_MainWindow() const { return ui->exitButton; }

// Slot: "Notiz hinzufügen"-Button
void MainWindow::on_addNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    NewNote *newNoteDialog = new NewNote(this);

    // Verbindung herstellen: Wenn die Notiz gespeichert wird, setze den Text im Label
    connect(newNoteDialog, &NewNote::noteSaved_newnote, this, [this]() {
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
    getAddNoteButton_MainWindow()->hide();
    getDisplayNotesButton_MainWindow()->hide();
    getEditNoteButton_MainWindow()->hide();
    getDeleteNoteButton_MainWindow()->hide();
    getExitButton_MainWindow()->hide();
}

// Slot: "Notiz bearbeiten"-Button
void MainWindow::on_editNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    editnote *noteWidget_edit = new editnote(this);
    noteWidget_edit->show();
    getAddNoteButton_MainWindow()->hide();
    getDisplayNotesButton_MainWindow()->hide();
    getEditNoteButton_MainWindow()->hide();
    getDeleteNoteButton_MainWindow()->hide();
    getExitButton_MainWindow()->hide();
}

// Slot: "Notiz löschen"-Button
void MainWindow::on_deleteNoteButton_clicked() {
    ui->errorLabel_mainwindow->clear(); // Fehlerlabel leeren
    deletenote *noteWidget_delete = new deletenote(this);
    noteWidget_delete->show();
    getAddNoteButton_MainWindow()->hide();
    getDisplayNotesButton_MainWindow()->hide();
    getEditNoteButton_MainWindow()->hide();
    getDeleteNoteButton_MainWindow()->hide();
    getExitButton_MainWindow()->hide();
}

// Zeigt das Hauptmenü an
void MainWindow::showMainMenu() {
    this->show();
    getAddNoteButton_MainWindow()->show();
    getDisplayNotesButton_MainWindow()->show();
    getEditNoteButton_MainWindow()->show();
    getDeleteNoteButton_MainWindow()->show();
    getExitButton_MainWindow()->show();
}
