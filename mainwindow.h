#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include "notebook.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    // Getter-Methoden für die Buttons
    QPushButton* getAddNoteButton() const;
    QPushButton* getDisplayNotesButton() const;
    QPushButton* getEditNoteButton() const;
    QPushButton* getDeleteNoteButton() const;

private slots:
    void on_addNoteButton_clicked();
    void on_displayNotesButton_clicked();
    void on_editNoteButton_clicked();
    void on_deleteNoteButton_clicked();

private:
    Ui::MainWindow *ui;
    Notebook notebook;
};

#endif // MAINWINDOW_H
