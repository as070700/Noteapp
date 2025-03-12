#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
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

void MainWindow::on_addNoteButton_clicked() {
    NewNote newNoteDialog(this);
    if (newNoteDialog.exec() == QDialog::Accepted) {
        Note note;
        note.title = newNoteDialog.getTitle().toStdString();
        note.content = newNoteDialog.getContent().toStdString();
        notebook.addNote(note);

        QString directoryPath = "./temp/";
        QDir directory(directoryPath);
        if (!directory.exists()) {
            qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath;
            if (!directory.mkpath(directoryPath)) {
                qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath;
                return;
            }
        }

        QString filename = directoryPath + QString::fromStdString(note.title) + ".txt";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << QString::fromStdString(note.content);
            file.close();
        } else {
            qDebug() << "Fehler beim Öffnen der Datei zum Schreiben:" << filename;
        }
    }
}

void MainWindow::on_displayNotesButton_clicked() {
    shownote *noteWidget = new shownote(this);
    noteWidget->show();

    // Beispiel für das Ausblenden eines Buttons
    if (noteWidget->isVisible()) {
        getAddNoteButton()->hide();
        getDisplayNotesButton()->hide();
        getEditNoteButton()->hide();
        getDeleteNoteButton()->hide();

        // Debugging: Überprüfen, ob die Buttons ausgeblendet wurden
        qDebug() << "Buttons ausgeblendet";
    }
}

void MainWindow::on_editNoteButton_clicked() {
    bool ok;
    int index = QInputDialog::getInt(this, tr("Notiz bearbeiten"), tr("Nummer der Notiz:"), 1, 1, notebook.getNotes().size(), 1, &ok);
    if (ok) {
        Note note = notebook.getNotes()[index - 1];
        QString title = QInputDialog::getText(this, tr("Neuer Titel"), tr("Titel:"), QLineEdit::Normal, QString::fromStdString(note.title), &ok);
        if (ok) {
            QString content = QInputDialog::getText(this, tr("Neuer Inhalt"), tr("Inhalt:"), QLineEdit::Normal, QString::fromStdString(note.content), &ok);
            if (ok) {
                note.title = title.toStdString();
                note.content = content.toStdString();
                if (notebook.editNote(index - 1, note)) {
                    QMessageBox::information(this, tr("Erfolg"), tr("Notiz bearbeitet."));
                } else {
                    QMessageBox::warning(this, tr("Fehler"), tr("Fehler beim Bearbeiten der Notiz."));
                }
            }
        }
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
