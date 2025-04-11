// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "editnote.h"
#include "ui_editnote.h"
#include "mainwindow.h"
#include "detaileditnote.h"
#include <QListWidgetItem>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Konstruktor: Initialisiert die Benutzeroberfläche und lädt die Notizen
editnote::editnote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editnote)
{
    ui->setupUi(this);

    // Verzeichnis mit den Notizdateien
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString directoryPath = appDirPath + "/temp/";
    QDir directory(directoryPath);

    // Überprüfen, ob das Verzeichnis existiert, und ggf. erstellen
    if (!directory.exists()) {
        if (!directory.mkpath(directoryPath)) {
            return; // Abbrechen, wenn das Verzeichnis nicht erstellt werden konnte
        }
    }

    // Liste aller .html-Dateien im Verzeichnis abrufen
    QStringList textFiles = directory.entryList(QStringList() << "*.html", QDir::Files);

    // Schleife durch alle HTML-Dateien und Hinzufügen der Notizen zur Liste
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            continue; // Überspringen, wenn die Datei nicht geöffnet werden kann
        }

        // Entfernen der .html-Erweiterung aus dem Dateinamen
        QString displayName = filename;
        if (displayName.endsWith(".html")) {
            displayName.chop(5); // Entfernt die letzten 5 Zeichen
        }

        // Dateiinhalt lesen und als Daten im Listeneintrag speichern
        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName); // Listeneintrag erstellen
        item->setData(Qt::UserRole, content); // Dateiinhalt als zusätzliche Daten speichern
        ui->listWidget_editnote->addItem(item); // Eintrag zur Liste hinzufügen
        file.close(); // Datei schließen
    }
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
editnote::~editnote()
{
    delete ui;
}

// Slot: Zurück-Button - Zurück zur Hauptansicht
void editnote::on_backButton_editnote_clicked() {
    ui->errorLabel_editnote->clear(); // Fehlerlabel leeren
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget());
    if (mainWindow) {
        mainWindow->show(); // Hauptfenster anzeigen
        mainWindow->getAddNoteButton()->show(); // Buttons im Hauptfenster anzeigen
        mainWindow->getDisplayNotesButton()->show();
        mainWindow->getEditNoteButton()->show();
        mainWindow->getDeleteNoteButton()->show();
        mainWindow->getExitButton()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}

// Slot: Öffnen-Button - Öffnet die ausgewählte Notiz im Bearbeitungsdialog
void editnote::on_openButton_editnote_clicked() {
    ui->errorLabel_editnote->clear(); // Fehlerlabel leeren
    QListWidgetItem *currentItem = ui->listWidget_editnote->currentItem(); // Aktuell ausgewählter Eintrag
    if (currentItem) {
        QString title = currentItem->text(); // Titel der Notiz
        QString content = currentItem->data(Qt::UserRole).toString(); // Inhalt der Notiz

        // Öffnet den Bearbeitungsdialog für die Notiz
        detaileditnote *detaileditDialog = new detaileditnote(this);

        // Verbindung herstellen: Wenn die Notiz gespeichert wird, setze den Text im Label
        connect(detaileditDialog, &detaileditnote::noteSaved, this, [this]() {
            ui->errorLabel_editnote->setText("Notiz erfolgreich gespeichert.");
            ui->errorLabel_editnote->setStyleSheet("color: green;");
        });

        detaileditDialog->setNoteContent_detaileditnote(title, content);
        detaileditDialog->exec(); // Dialog öffnen
    } else {
        ui->errorLabel_editnote->setText("Warnung: Bitte wählen Sie eine Notiz aus.");
        ui->errorLabel_editnote->setStyleSheet("color: orange;");
    }
}
