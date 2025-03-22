#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "deletenote.h"
#include "setpassworddialog.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QSettings>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "MainWindow initialized";

    // Setup QSettings
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    if (!QDir(sysDirPath).exists()) {
        QDir().mkpath(sysDirPath);
    }
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    qDebug() << "QSettings path: " << settings.fileName();

    // Connect the password setting action
    connect(ui->setPasswordAction, &QAction::triggered, this, [&]() {
        qDebug() << "SetPasswordAction triggered";
        SetPasswordDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            QString passwordHash = dialog.getPassword_setPasswordDialog();
            settings.setValue("passwordHash", passwordHash);
            qDebug() << "Password set";
        } else {
            qDebug() << "Password dialog canceled";
        }
    });

    // Debugging: Überprüfen Sie, ob die Widgets korrekt initialisiert sind
    if (!ui->addNoteButton) {
        qDebug() << "addNoteButton is not initialized";
    } else {
        qDebug() << "addNoteButton initialized";
    }

    if (!ui->displayNotesButton) {
        qDebug() << "displayNotesButton is not initialized";
    } else {
        qDebug() << "displayNotesButton initialized";
    }

    if (!ui->editNoteButton) {
        qDebug() << "editNoteButton is not initialized";
    } else {
        qDebug() << "editNoteButton initialized";
    }

    if (!ui->deleteNoteButton) {
        qDebug() << "deleteNoteButton is not initialized";
    } else {
        qDebug() << "deleteNoteButton initialized";
    }

    if (!ui->exitButton) {
        qDebug() << "exitButton is not initialized";
    } else {
        qDebug() << "exitButton initialized";
    }

    // Debugging: Überprüfen Sie, ob der Widget-Container korrekt initialisiert ist
    if (!ui->centralwidget) {
        qDebug() << "centralWidget is not initialized";
    } else {
        qDebug() << "centralWidget initialized";
    }
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow destroyed";
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
    qDebug() << "Add Note Button clicked";
    NewNote newNoteDialog(this);
    if (newNoteDialog.exec() == QDialog::Accepted) {
        Note note;
        note.title = newNoteDialog.getTitle_newnote().toStdString();
        note.content = newNoteDialog.getContent_newnote().toStdString();
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
    qDebug() << "Display Notes Button clicked";
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
    qDebug() << "Edit Note Button clicked";
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
    qDebug() << "Delete Note Button clicked";
    deletenote *noteWidget_delete = new deletenote(this);
    noteWidget_delete->show();

    // Das Ausblenden eines Buttons
    if (noteWidget_delete->isVisible()) {
        getAddNoteButton()->hide();
        getDisplayNotesButton()->hide();
        getEditNoteButton()->hide();
        getDeleteNoteButton()->hide();
        getExitButton()->hide();

        // Debugging: Überprüfen, ob die Buttons ausgeblendet wurden
        qDebug() << "Buttons ausgeblendet";
    }
}
