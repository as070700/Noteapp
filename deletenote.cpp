#include "deletenote.h"
#include "ui_deletenote.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Konstruktor der Klasse deletenote
deletenote::deletenote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletenote)
{
    ui->setupUi(this); // Initialisiert die Benutzeroberfläche
    loadNotes(); // Lädt die Notizen aus dem Verzeichnis
    ui->listWidget_deleteNote->setSelectionMode(QAbstractItemView::MultiSelection); // Ermöglicht Mehrfachauswahl
}

// Destruktor der Klasse deletenote
deletenote::~deletenote()
{
    delete ui; // Gibt den Speicher der Benutzeroberfläche frei
}

// Lädt die Notizen aus dem Verzeichnis und fügt sie zur Liste hinzu
void deletenote::loadNotes()
{
    QString directoryPath = "./temp/"; // Verzeichnis mit den Notizdateien
    QDir directory(directoryPath);

    // Überprüfen, ob das Verzeichnis existiert, und ggf. erstellen
    if (!directory.exists()) {
        qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath;
        if (!directory.mkpath(directoryPath)) {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath;
            return;
        }
    }

    // Liste aller .txt-Dateien im Verzeichnis abrufen
    QStringList textFiles = directory.entryList(QStringList() << "*.html", QDir::Files);
    if (textFiles.isEmpty()) {
        qDebug() << "Keine Textdateien im Verzeichnis" << directoryPath;
    }

    // Schleife durch alle Textdateien und Hinzufügen der Notizen zur Liste
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
            continue;
        }

        // Entfernen der .txt-Erweiterung aus dem Dateinamen
        QString displayName = filename;
        if (displayName.endsWith(".html")) {
            displayName.chop(5); // Entfernt die letzten 4 Zeichen
        }

        // Dateiinhalt lesen und als Daten im Listeneintrag speichern
        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName); // Listeneintrag erstellen
        item->setData(Qt::UserRole, content); // Dateiinhalt als zusätzliche Daten speichern
        ui->listWidget_deleteNote->addItem(item); // Eintrag zur Liste hinzufügen
        file.close(); // Datei schließen
    }
}

// Löscht die ausgewählten Notizen
void deletenote::on_deleteButton_deleteNote_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->listWidget_deleteNote->selectedItems(); // Ausgewählte Einträge abrufen
    if (!selectedItems.isEmpty()) {
        bool allDeleted = true; // Flag, um zu prüfen, ob alle Dateien gelöscht wurden

        // Schleife durch alle ausgewählten Einträge
        foreach(QListWidgetItem *item, selectedItems) {
            QString displayName = item->text(); // Name des Eintrags
            QString filePath = "./temp/" + displayName + ".html"; // Dateipfad erstellen

            // Datei löschen
            if (QFile::remove(filePath)) {
                // Entfernen des Eintrags aus der Liste
                delete ui->listWidget_deleteNote->takeItem(ui->listWidget_deleteNote->row(item));
            } else {
                allDeleted = false; // Fehler beim Löschen
            }
        }

        // Rückmeldung an den Benutzer über das Label
        if (allDeleted) {
            ui->errorLabel_deletnote->setText("Alle ausgewählten Notizen wurden gelöscht.");
            ui->errorLabel_deletnote->setStyleSheet("color: green;"); // Erfolgsnachricht in Grün
        } else {
            ui->errorLabel_deletnote->setText("Fehler: Einige Notizdateien konnten nicht gelöscht werden.");
            ui->errorLabel_deletnote->setStyleSheet("color: red;"); // Fehlermeldung in Rot
        }
    } else {
        // Warnung, wenn keine Notiz ausgewählt wurde
        ui->errorLabel_deletnote->setText("Warnung: Bitte wählen Sie mindestens eine Notiz aus, die gelöscht werden soll.");
        ui->errorLabel_deletnote->setStyleSheet("color: orange;"); // Warnung in Orange
    }
}

// Zurück zur Hauptansicht
void deletenote::on_backButton_deleteNote_clicked()
{
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget()); // Hauptfenster abrufen
    if (mainWindow) {
        mainWindow->show(); // Hauptfenster anzeigen
        mainWindow->getAddNoteButton()->show(); // Buttons im Hauptfenster anzeigen
        mainWindow->getDisplayNotesButton()->show();
        mainWindow->getEditNoteButton()->show();
        mainWindow->getDeleteNoteButton()->show();
        mainWindow->getExitButton()->show();
    }
    this->hide(); // Aktuelles Widget ausblenden
}
