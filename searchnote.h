// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef SEARCHNOTE_H
#define SEARCHNOTE_H

#include <QWidget>
#include <QLabel>

namespace Ui {
class searchnote;
}

class searchnote : public QWidget
{
    Q_OBJECT

public:
    explicit searchnote(QWidget *parent = nullptr); // Konstruktor
    ~searchnote(); // Destruktor

    //QLabel* errorLabel_searchnote; // Fehlerlabel

private slots:
    void on_searchButton_searchnote_clicked(); // Slot für den Such-Button
    void on_backButton_searchnote_clicked(); // Slot für den Zurück-Button
    void on_openButton_searchnote_clicked(); // Slot für den Öffnen-Button
    void on_editButton_searchnote_clicked(); // Slot für den Bearbeiten-Button

private:
    Ui::searchnote *ui; // Benutzeroberfläche
    void searchNotes(const QString &query); // Funktion zum Suchen von Notizen
};

#endif // SEARCHNOTE_H
