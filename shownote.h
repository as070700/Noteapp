#ifndef SHOWNOTE_H
#define SHOWNOTE_H

#include <QWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QListView>

namespace Ui {
class shownote;
}

class shownote : public QWidget
{
    Q_OBJECT

public:
    explicit shownote(QWidget *parent = nullptr); // Konstruktor
    ~shownote(); // Destruktor

    // void loadNotePassword_shownote(); // Auskommentiert: Lädt und überprüft das Passwort

    // Getter-Methoden für die Buttons und Widgets
    QLabel* getLabelShownote() const;
    QScrollArea* getScrollAreaShownote() const;
    QWidget* getScrollAreaWidgetContentsShownote() const;
    QListView* getListviewShownote() const;
    QPushButton* getOpenButtonShownote() const;
    QPushButton* getBackButtonShownote() const;
    QPushButton* getSearchButtonShownote() const;

private slots:
    void on_backButton_shownote_clicked(); // Slot für den Zurück-Button
    void on_openButton_shownote_clicked(); // Slot für den Öffnen-Button
    void on_searchButton_shownote_clicked(); // Slot für den Such-Button

private:
    Ui::shownote *ui; // Benutzeroberfläche
};

#endif // SHOWNOTE_H
