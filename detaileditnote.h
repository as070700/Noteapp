// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef DETAILEDITNOTE_H
#define DETAILEDITNOTE_H

#include <QDialog>
#include <QTextCharFormat>

namespace Ui {
class detaileditnote;
}

class detaileditnote : public QDialog
{
    Q_OBJECT

public:
    explicit detaileditnote(QWidget *parent = nullptr); // Konstruktor
    ~detaileditnote(); // Destruktor

    void setNoteContent_detaileditnote(const QString &title, const QString &content); // Setzt Titel und Inhalt der Notiz
    QString getNoteContent_detaileditnote() const;

signals:
    void noteSaved_detaileditnote(); // Signal, das ausgelöst wird, wenn die Notiz gespeichert wurde

private slots:
    void on_backButton_detaileditnote_clicked(); // Slot für den Zurück-Button
    void on_saveButton_detaileditnote_clicked(); // Slot für den Speichern-Button
    void setBold_detaileditnote(); // Setzt den Text fett
    void setItalic_detaileditnote(); // Setzt den Text kursiv
    void setUnderline_detaileditnote(); // Unterstreicht den Text
    void setColor_detaileditnote(); // Ändert die Textfarbe
    void setFontSize_detaileditnote(int index); // Ändert die Schriftgröße

private:
    Ui::detaileditnote *ui; // Benutzeroberfläche
    void saveNoteContent_detaileditnote(); // Speichert den Inhalt der Notiz
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format); // Wendet Formatierungen auf das aktuelle Wort oder die Auswahl an
};

#endif // DETAILEDITNOTE_H
