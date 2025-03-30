#ifndef EDITNOTE_H
#define EDITNOTE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class editnote;
}

class editnote : public QWidget
{
    Q_OBJECT

public:
    explicit editnote(QWidget *parent = nullptr); // Konstruktor // Konstruktor
    ~editnote(); // Destruktor // Destruktor

private slots:
    void on_backButton_editnote_clicked(); // Slot für den Zurück-Button // Slot für den Zurück-Button
    void on_openButton_editnote_clicked(); // Slot für den Öffnen-Button // Slot für den Öffnen-Button

private:
    Ui::editnote *ui; // Benutzeroberfläche // Benutzeroberfläche
};

#endif // EDITNOTE_H
