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
    void loadNoteContent_detailshownote(const QString &noteTitle, const QString &noteContent); // Lädt den Inhalt der Notiz

private:
    Ui::detailShownote *ui; // Benutzeroberfläche
    // bool isNotePasswordProtected_detailshownote(const QString &noteTitle); // Auskommentiert: Überprüft, ob die Notiz passwortgeschützt ist
};

#endif // DETAILSHOWNOTE_H
