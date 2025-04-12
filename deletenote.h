// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef DELETENOTE_H
#define DELETENOTE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class deletenote;
}

class deletenote : public QWidget
{
    Q_OBJECT

public:
    explicit deletenote(QWidget *parent = nullptr); // Konstruktor
    ~deletenote(); // Destruktor

private slots:
    void on_deleteButton_deleteNote_clicked(); // Slot für den Lösch-Button
    void on_backButton_deleteNote_clicked(); // Slot für den Zurück-Button

private:
    Ui::deletenote *ui; // Benutzeroberfläche
    void loadNotes_deletenote(); // Funktion zum Laden der Notizen
};

#endif // DELETENOTE_H
