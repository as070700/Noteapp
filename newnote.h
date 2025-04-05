#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QDialog>
#include <QTextCharFormat>
#include <QColorDialog>

namespace Ui {
class NewNote;
}

class NewNote : public QDialog
{
    Q_OBJECT

public:
    explicit NewNote(QWidget *parent = nullptr); // Konstruktor
    ~NewNote(); // Destruktor

    QString getTitle_newnote() const; // Gibt den Titel der Notiz zurück
    QString getContent_newnote() const; // Gibt den Inhalt der Notiz zurück
    void saveNote_newnote(); // Speichert die Notiz

signals:
    void noteSaved(); // Signal, das ausgelöst wird, wenn die Notiz gespeichert wurde

private slots:
    void setBold_newnote(); // Setzt den Text fett
    void setItalic_newnote(); // Setzt den Text kursiv
    void setUnderline_newnote(); // Unterstreicht den Text
    void setColor_newnote(); // Ändert die Textfarbe
    void setFontSize_newnote(int index); // Ändert die Schriftgröße

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format); // Wendet Formatierungen auf das aktuelle Wort oder die Auswahl an
    Ui::NewNote *ui; // Benutzeroberfläche
};

#endif // NEWNOTE_H