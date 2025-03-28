#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QPushButton>
#include <QAction>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QPushButton* getAddNoteButton() const;
    QPushButton* getDisplayNotesButton() const;
    QPushButton* getEditNoteButton() const;
    QPushButton* getDeleteNoteButton() const;
    QPushButton* getExitButton() const;
    QAction* getSetPasswordAction() const;

private slots:
    void on_addNoteButton_clicked();
    void on_displayNotesButton_clicked();
    void on_editNoteButton_clicked();
    void on_deleteNoteButton_clicked();
    void setPassword(); // Neue Methode für die Passwortaktion
    void resetPassword(); // Neue Methode für das Zurücksetzen des Passworts

private:
    void showMainMenu();
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
