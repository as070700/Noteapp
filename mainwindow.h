#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QAction>
#include <QLabel>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr); // Konstruktor
    ~MainWindow(); // Destruktor

    // Getter-Methoden für die Buttons und Aktionen
    QPushButton* getAddNoteButton() const;
    QPushButton* getDisplayNotesButton() const;
    QPushButton* getEditNoteButton() const;
    QPushButton* getDeleteNoteButton() const;
    QPushButton* getExitButton() const;
    // QAction* getSetPasswordAction() const; // Auskommentiert, da es mit dem Passwortsystem zusammenhängt

private slots:
    void on_addNoteButton_clicked(); // Slot für den "Notiz hinzufügen"-Button
    void on_displayNotesButton_clicked(); // Slot für den "Notizen anzeigen"-Button
    void on_editNoteButton_clicked(); // Slot für den "Notiz bearbeiten"-Button
    void on_deleteNoteButton_clicked(); // Slot für den "Notiz löschen"-Button
    // void setPassword(); // Auskommentiert: Methode zum Setzen eines Passworts
    // void resetPassword(); // Auskommentiert: Methode zum Zurücksetzen des Passworts

private:
    void showMainMenu(); // Zeigt das Hauptmenü an
    Ui::MainWindow *ui; // Benutzeroberfläche
};

#endif // MAINWINDOW_H
