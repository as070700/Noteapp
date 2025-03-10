#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "notebook.h"
#include "newnote.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addNoteButton_clicked();
    void on_displayNotesButton_clicked();
    void on_editNoteButton_clicked();
    void on_deleteNoteButton_clicked();
    void on_actionNewNote_triggered();

private:
    Ui::MainWindow *ui;
    Notebook notebook;
};

#endif // MAINWINDOW_H
