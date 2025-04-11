// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef EDITNOTE_H
#define EDITNOTE_H

#include <QWidget>
#include <QListWidgetItem>
#include <QLabel>

namespace Ui {
class editnote;
}

class editnote : public QWidget
{
    Q_OBJECT

public:
    explicit editnote(QWidget *parent = nullptr); // Konstruktor
    ~editnote(); // Destruktor

    QLabel* errorLabel_editnote; // Fehlerlabel

private slots:
    void on_backButton_editnote_clicked(); // Slot für den Zurück-Button
    void on_openButton_editnote_clicked(); // Slot für den Öffnen-Button

private:
    Ui::editnote *ui; // Benutzeroberfläche
};

#endif // EDITNOTE_H
