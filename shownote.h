// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#ifndef SHOWNOTE_H
#define SHOWNOTE_H

#include "searchnote.h"
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

    // Getter-Methoden für die Buttons und Widgets
    QLabel* getLabel_Shownote() const;
    //QLabel* errorLabel_shownote; // Fehlerlabel
    QScrollArea* getScrollArea_Shownote() const;
    QWidget* getScrollAreaWidgetContents_Shownote() const;
    QListView* getListview_Shownote() const;
    QPushButton* getOpenButton_Shownote() const;
    QPushButton* getBackButton_Shownote() const;
    QPushButton* getSearchButton_Shownote() const;

private slots:
    void on_backButton_shownote_clicked(); // Slot für den Zurück-Button
    void on_openButton_shownote_clicked(); // Slot für den Öffnen-Button
    void on_searchButton_shownote_clicked(); // Slot für den Such-Button

private:
    Ui::shownote *ui; // Benutzeroberfläche

    searchnote *searchNote = nullptr; // Zeiger auf das searchnote-Objekt
};

#endif // SHOWNOTE_H
