// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "detailshownote.h"
#include "ui_detailshownote.h"
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
void detailShownote::setNoteContent_detailshownote(const QString &title, const QString &content) {
    ui->label_title_detailshownote->setText(title); // Setzt den Titel der Notiz
    ui->content_textEdit_detailshownote->setHtml(content); // Zeigt den Inhalt an
}

// Lädt den Inhalt der Notiz aus einer Datei
void detailShownote::loadNoteContent_detailshownote(const QString &noteTitle) {
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

    // Setzt den Titel und den Inhalt der Notiz
    setNoteContent_detailshownote(noteTitle, content);
}

