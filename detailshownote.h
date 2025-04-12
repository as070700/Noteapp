// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef DETAILSHOWNOTE_H
#define DETAILSHOWNOTE_H

#include <QDialog>

namespace Ui {
class detailShownote;
}

class detailShownote : public QDialog
{
    Q_OBJECT

public:
    explicit detailShownote(QWidget *parent = nullptr); // Konstruktor
    ~detailShownote(); // Destruktor

    void setNoteContent_show(const QString &title, const QString &content); // Setzt den Titel und den Inhalt der Notiz
    void loadNoteContent_detailshownote(const QString &noteTitle); // Lädt den Inhalt der Notiz

private:
    Ui::detailShownote *ui; // Benutzeroberfläche
};

#endif // DETAILSHOWNOTE_H
