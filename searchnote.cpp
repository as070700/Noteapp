// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "searchnote.h"
#include "shownote.h"
#include "detaileditnote.h"
#include "detailshownote.h"
#include "ui_searchnote.h"
#include <QLabel>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QPointer>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Funktionen
searchnote::searchnote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchnote)
{
    ui->setupUi(this);

    // Verbindung des Such-Buttons mit der Suchfunktion
    connect(ui->searchButton_searchnote, &QPushButton::clicked, this, &searchnote::on_searchButton_searchnote_clicked);

    // Verbindung des Öffnen-Buttons mit der Öffnen-Funktion
    connect(ui->openButton_searchnote, &QPushButton::clicked, this, &searchnote::on_openButton_searchnote_clicked);

    // Verbindung des Bearbeiten-Buttons mit der Bearbeiten-Funktion
    connect(ui->editButton_searchnote, &QPushButton::clicked, this, &searchnote::on_editButton_searchnote_clicked);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
searchnote::~searchnote()
{
    delete ui;
}

// Slot: Wird aufgerufen, wenn der Such-Button geklickt wird
void searchnote::on_searchButton_searchnote_clicked()
{
    QString query = ui->searchLineEdit_searchnote->text(); // Suchbegriff aus dem Eingabefeld abrufen
    searchNotes(query); // Suchfunktion aufrufen
}

// Funktion: Sucht nach Notizen, die den Suchbegriff im Titel oder Inhalt enthalten
void searchnote::searchNotes(const QString &query)
{
    ui->searchResultsListWidget_searchnote->clear(); // Suchergebnisse zurücksetzen

    QString directoryPath = "./temp/"; // Verzeichnis mit den Notizdateien
    QDir directory(directoryPath);
    if (!directory.exists()) {
        ui->errorLabel_searchnote->setText("Fehler: Das Verzeichnis 'temp' existiert nicht.");
        ui->errorLabel_searchnote->setStyleSheet("color: red;");
        return; // Abbrechen, wenn das Verzeichnis nicht existiert
    }

    // Liste aller .html-Dateien im Verzeichnis abrufen
    QStringList textFiles = directory.entryList(QStringList() << "*.html", QDir::Files);
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            continue;
        }

        QTextStream in(&file);
        QString content = in.readAll(); // Dateiinhalt lesen
        file.close();

        QString title = filename;
        if (title.endsWith(".html")) {
            title.chop(5); // Entfernt die letzten 5 Zeichen (".html")
        }

        // Überprüfen, ob der Titel oder der Inhalt den Suchbegriff enthält
        if (title.contains(query, Qt::CaseInsensitive) || content.contains(query, Qt::CaseInsensitive)) {
            QListWidgetItem *item = new QListWidgetItem(title); // Suchergebnis erstellen
            item->setData(Qt::UserRole, content); // Dateiinhalt als zusätzliche Daten speichern
            ui->searchResultsListWidget_searchnote->addItem(item); // Suchergebnis zur Liste hinzufügen
            ui->errorLabel_searchnote->clear(); // Fehlerlabel leeren
            ui->errorLabel_searchnote->setText("Erfolgreich: Es wurde der Suchbegriff im Titel oder im Text gefunden.");
            ui->errorLabel_searchnote->setStyleSheet("color: green;"); // Erfolgreiche Suche in grün anzeigen
        }
        else
        {
            ui->errorLabel_searchnote->setText("Fehler: Der Suchbegriff wurde nicht gefunden.");
            ui->errorLabel_searchnote->setStyleSheet("color: red;"); // Fehlgeschlagene Suche in rot anzeigen
        }
    }
}

// Slot: Wird aufgerufen, wenn der Öffnen-Button geklickt wird
void searchnote::on_openButton_searchnote_clicked()
{
    static QPointer<detailShownote> detailDialog = nullptr;

    if (!detailDialog) {
        detailDialog = new detailShownote(this);
        connect(detailDialog, &QDialog::finished, detailDialog, &QObject::deleteLater);
    }

    QListWidgetItem *currentItem = ui->searchResultsListWidget_searchnote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        detailDialog->setNoteContent_detailshownote(title, content);
        detailDialog->exec(); // Dialog öffnen
    }
}

// Slot: Wird aufgerufen, wenn der Bearbeiten-Button geklickt wird
void searchnote::on_editButton_searchnote_clicked()
{
    static QPointer<detaileditnote> editDialog = nullptr;

    if (!editDialog) {
        editDialog = new detaileditnote(this);
        connect(editDialog, &QDialog::finished, editDialog, &QObject::deleteLater);
    }

    QListWidgetItem *currentItem = ui->searchResultsListWidget_searchnote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        editDialog->setNoteContent_detaileditnote(title, content);
        editDialog->exec(); // Dialog öffnen
    }
}

// Slot: Wird aufgerufen, wenn der Zurück-Button geklickt wird
void searchnote::on_backButton_searchnote_clicked()
{
    ui->errorLabel_searchnote->clear(); // Fehlerlabel leeren
    ui->searchLineEdit_searchnote->clear(); // Suchfeld leeren
    ui->searchResultsListWidget_searchnote->clear(); // Suchergebnisse zurücksetzen
    shownote *showNote = qobject_cast<shownote*>(parentWidget()); // Hauptfenster abrufen
    if (showNote) {
        // Zeigt die Elemente des Hauptfensters wieder an
        showNote->show();
        showNote->getLabel_Shownote()->show();
        showNote->getScrollArea_Shownote()->show();
        showNote->getScrollAreaWidgetContents_Shownote()->show();
        showNote->getListview_Shownote()->show();
        showNote->getOpenButton_Shownote()->show();
        showNote->getBackButton_Shownote()->show();
        showNote->getSearchButton_Shownote()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}
