#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}

// Getter-Methoden für die Buttons
QPushButton* MainWindow::getAddNoteButton() const {
    return ui->addNoteButton;
}

QPushButton* MainWindow::getDisplayNotesButton() const {
    return ui->displayNotesButton;
}

QPushButton* MainWindow::getEditNoteButton() const {
    return ui->editNoteButton;
}

QPushButton* MainWindow::getDeleteNoteButton() const {
    return ui->deleteNoteButton;
}

QPushButton* MainWindow::getExitButton() const {
    return ui->exitButton;
}

void MainWindow::on_addNoteButton_clicked() {
    NewNote newNoteDialog(this);
    if (newNoteDialog.exec() == QDialog::Accepted) {
        Note note;
        note.title = newNoteDialog.getTitle().toStdString();
        note.content = newNoteDialog.getContent().toStdString();
        notebook.addNote(note);

        QString appDirPath = QCoreApplication::applicationDirPath();
        QString directoryPath_temp = appDirPath + "/temp/";
        QDir directory_temp(directoryPath_temp);
        if (!directory_temp.exists()) {
            qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath_temp;
            if (!directory_temp.mkpath(directoryPath_temp)) {
                qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath_temp;
                return;
            }
        }

        QString directoryPath_sys = appDirPath + "/sys/";
        QDir directory_sys(directoryPath_sys);
        if (!directory_sys.exists()) {
            qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath_sys;
            if (!directory_sys.mkpath(directoryPath_sys)) {
                qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath_sys;
                return;
            }
        }

        QString filename = directoryPath_temp + QString::fromStdString(note.title) + ".txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << QString::fromStdString(note.content);
            file.close();
        } else {
            qDebug() << "Fehler beim Öffnen der Datei zum Schreiben:" << filename;
        }

        // Zusammenfassung in notes.txt speichern
        QString summaryFilePath = directoryPath_sys + "notes.txt";
        QFile summaryFile(summaryFilePath);
        if (summaryFile.open(QIODevice::Append | QIODevice::Text)) {
            QTextStream out(&summaryFile);
            out << QString::fromStdString(note.title) << ": " << QString::fromStdString(note.content) << "\n";
            summaryFile.close();
        } else {
            qDebug() << "Fehler beim Öffnen der Datei zum Schreiben der Zusammenfassung:" << summaryFilePath;
        }
    }
}

void MainWindow::on_displayNotesButton_clicked() {
    shownote *noteWidget_show = new shownote(this);
    noteWidget_show->show();

    // Das Ausblenden eines Buttons
    if (noteWidget_show->isVisible()) {
        getAddNoteButton()->hide();
        getDisplayNotesButton()->hide();
        getEditNoteButton()->hide();
        getDeleteNoteButton()->hide();
        getExitButton()->hide();

        // Debugging: Überprüfen, ob die Buttons ausgeblendet wurden
        qDebug() << "Buttons ausgeblendet";
    }
}

void MainWindow::on_editNoteButton_clicked() {
    editnote *noteWidget_edit = new editnote(this);
    noteWidget_edit->show();

    // Das Ausblenden eines Buttons
    if (noteWidget_edit->isVisible()) {
        getAddNoteButton()->hide();
        getDisplayNotesButton()->hide();
        getEditNoteButton()->hide();
        getDeleteNoteButton()->hide();
        getExitButton()->hide();

        // Debugging: Überprüfen, ob die Buttons ausgeblendet wurden
        qDebug() << "Buttons ausgeblendet";
    }
}

void MainWindow::on_deleteNoteButton_clicked() {
    bool ok;
    int index = QInputDialog::getInt(this, tr("Notiz löschen"), tr("Nummer der Notiz:"), 1, 1, notebook.getNotes().size(), 1, &ok);
    if (ok) {
        if (notebook.deleteNote(index - 1)) {
            QMessageBox::information(this, tr("Erfolg"), tr("Notiz gelöscht."));
        } else {
            QMessageBox::warning(this, tr("Fehler"), tr("Fehler beim Löschen der Notiz."));
        }
    }
}
