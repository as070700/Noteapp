#include "searchnote.h"
#include "shownote.h"
#include "ui_searchnote.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet den Such-Button mit der entsprechenden Funktion
searchnote::searchnote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchnote)
{
    ui->setupUi(this);

    // Verbindung des Such-Buttons mit der Suchfunktion
    connect(ui->searchButton_searchnote, &QPushButton::clicked, this, &searchnote::on_searchButton_searchnote_clicked);
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
        qDebug() << "Verzeichnis existiert nicht:" << directoryPath;
        return;
    }

    // Liste aller .html-Dateien im Verzeichnis abrufen
    QStringList textFiles = directory.entryList(QStringList() << "*.html", QDir::Files);
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
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
        }
    }
}

// Slot: Wird aufgerufen, wenn der Zurück-Button geklickt wird
void searchnote::on_backButton_searchnote_clicked()
{
    shownote *showNote = qobject_cast<shownote*>(parentWidget()); // Hauptfenster abrufen
    if (showNote) {
        // Zeigt die Elemente des Hauptfensters wieder an
        showNote->show();
        showNote->getLabelShownote()->show();
        showNote->getScrollAreaShownote()->show();
        showNote->getScrollAreaWidgetContentsShownote()->show();
        showNote->getListviewShownote()->show();
        showNote->getOpenButtonShownote()->show();
        showNote->getBackButtonShownote()->show();
        showNote->getSearchButtonShownote()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}
