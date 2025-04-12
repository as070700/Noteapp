// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "shownote.h"
#include "ui_shownote.h"
#include "mainwindow.h"
#include "detailshownote.h"
#include "searchnote.h"
#include <QListWidgetItem>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QListView>
#include <QSettings>
#include <QStandardPaths>
#include <QDebug>

// Konstruktor: Initialisiert die Benutzeroberfläche und lädt die Notizen
shownote::shownote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shownote)
{
    ui->setupUi(this);

    QString directoryPath = "./temp/";
    QDir directory(directoryPath);

    // Überprüfen, ob das Verzeichnis existiert, und ggf. erstellen
    if (!directory.exists()) {
        if (!directory.mkpath(directoryPath)) {
            ui->errorLabel_shownote->setText("Fehler: Das Verzeichnis 'temp' konnte nicht erstellt werden.");
            ui->errorLabel_shownote->setStyleSheet("color: red;");
            return;
        }
    }

    // Liste aller .html-Dateien im Verzeichnis abrufen
    QStringList htmlFiles = directory.entryList(QStringList() << "*.html", QDir::Files);

    // Notizen laden und in die Liste einfügen
    foreach(QString filename, htmlFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            ui->errorLabel_shownote->setText("Fehler: Konnte Datei nicht öffnen: " + filename);
            ui->errorLabel_shownote->setStyleSheet("color: red;");
            continue;
        }

        QString displayName = filename;
        if (displayName.endsWith(".html")) {
            displayName.chop(5); // Entfernt die letzten 5 Zeichen (".html")
        }

        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName); // Listeneintrag erstellen
        item->setData(Qt::UserRole, content); // Dateiinhalt als zusätzliche Daten speichern
        ui->listview_shownote->addItem(item); // Eintrag zur Liste hinzufügen
        file.close();
    }
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
shownote::~shownote()
{
    delete ui;
}

// Getter-Methoden für die Buttons und Widgets
QLabel* shownote::getLabel_Shownote() const {
    return ui->label;
}

QScrollArea* shownote::getScrollArea_Shownote() const {
    return ui->scrollArea;
}

QWidget* shownote::getScrollAreaWidgetContents_Shownote() const {
    return ui->scrollAreaWidgetContents;
}

QListView* shownote::getListview_Shownote() const {
    return ui->listview_shownote;
}

QPushButton* shownote::getOpenButton_Shownote() const {
    return ui->openButton_shownote;
}

QPushButton* shownote::getBackButton_Shownote() const {
    return ui->backButton_shownote;
}

QPushButton* shownote::getSearchButton_Shownote() const {
    return ui->searchButton_shownote;
}

// Slot: Zurück-Button - Zurück zur Hauptansicht
void shownote::on_backButton_shownote_clicked() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget());
    if (mainWindow) {
        mainWindow->show();
        mainWindow->showMainMenu(); // Zeigt das Hauptmenü an
    }
    this->hide(); // Versteckt das aktuelle Widget
}

// Slot: Öffnen-Button - Öffnet die ausgewählte Notiz im Detaildialog
void shownote::on_openButton_shownote_clicked() {
    QListWidgetItem *currentItem = ui->listview_shownote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();

        detailShownote *detailDialog = new detailShownote(this);
        detailDialog->loadNoteContent_detailshownote(title); // Methode zum Laden der Notiz
        detailDialog->exec(); // Öffnet den Dialog
    } else {
        ui->errorLabel_shownote->setText("Warnung: Bitte wählen Sie eine Notiz aus.");
        ui->errorLabel_shownote->setStyleSheet("color: orange;");
    }
}

// Slot: Such-Button - Öffnet das Suchfenster
void shownote::on_searchButton_shownote_clicked() {
    static searchnote *noteWidget_searchnote = nullptr; // Statisches Objekt, um sicherzustellen, dass es nur einmal erstellt wird

    if (!noteWidget_searchnote) {
        noteWidget_searchnote = new searchnote(this); // Erstellt das searchnote-Widget nur einmal
        noteWidget_searchnote->show();
    } else {
        noteWidget_searchnote->show(); // Zeigt das Widget an, falls es bereits existiert
    }

    if (noteWidget_searchnote->isVisible()) {
        // Versteckt die Elemente des aktuellen Widgets
        getLabel_Shownote()->hide();
        getScrollArea_Shownote()->hide();
        getScrollAreaWidgetContents_Shownote()->hide();
        getListview_Shownote()->hide();
        getOpenButton_Shownote()->hide();
        getBackButton_Shownote()->hide();
        getSearchButton_Shownote()->hide();
    }
}
