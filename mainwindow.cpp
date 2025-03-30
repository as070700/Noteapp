#include "mainwindow.h"
#include "newnote.h"
#include "shownote.h"
#include "editnote.h"
#include "deletenote.h"
#include "setpassworddialog.h"
#include "getpassworddialog.h"
#include "securityquestiondialog.h" // Hinzufügen dieser Zeile
#include "ui_mainwindow.h"
#include "note.h" // Inkludieren der Header-Datei für Note
#include "notebook.h" // Inkludieren der Header-Datei für Notebook
#include <QInputDialog>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStandardPaths>
#include <QSettings>

// Instanz von Notebook deklarieren
Notebook notebook;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qDebug() << "MainWindow initialized";

    // Define the paths for the sys and temp directories
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QString tempDirPath = appDirPath + "/temp/";

    // Check and create sys directory if it does not exist
    if (!QDir(sysDirPath).exists()) {
        if (QDir().mkpath(sysDirPath)) {
            qDebug() << "Created sys directory:" << sysDirPath;
        } else {
            qDebug() << "Failed to create sys directory:" << sysDirPath;
        }
    }

    // Check and create temp directory if it does not exist
    if (!QDir(tempDirPath).exists()) {
        if (QDir().mkpath(tempDirPath)) {
            qDebug() << "Created temp directory:" << tempDirPath;
        } else {
            qDebug() << "Failed to create temp directory:" << tempDirPath;
        }
    }

    // Setup QSettings
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    qDebug() << "QSettings path: " << settings.fileName();

    // Check if settings file is writable
    QFile settingsFile(settings.fileName());
    if (!settingsFile.open(QIODevice::ReadWrite)) {
        qDebug() << "Failed to open settings file for writing:" << settings.fileName();
    } else {
        qDebug() << "Settings file is writable";
        settingsFile.close();
    }

    // Connect the password setting action
    connect(ui->setPasswordAction, &QAction::triggered, this, &MainWindow::setPassword);

    // Connect the password reset action
    connect(ui->resetPasswordAction, &QAction::triggered, this, &MainWindow::resetPassword);

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
        qDebug() << "centralwidget is not initialized";
    } else {
        qDebug() << "centralwidget initialized";
    }
}

MainWindow::~MainWindow() {
    qDebug() << "MainWindow destroyed";
    delete ui;
}

// Setter-Methoden für das Passwort
void MainWindow::setPassword() {
    qDebug() << "SetPasswordAction triggered";
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

    if (settings.contains("passwordHash")) {
        qDebug() << "Password already set. Requesting current password.";
        getPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString enteredPasswordHash = passwordDialog.getPassword_getPasswordDialog();
            QString correctPasswordHash = settings.value("passwordHash").toString();
            if (enteredPasswordHash != correctPasswordHash) {
                QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
                return;
            }
        } else {
            qDebug() << "Password dialog canceled.";
            return;
        }
    }

    SetPasswordDialog setPasswordDialog(this);
    if (setPasswordDialog.exec() == QDialog::Accepted) {
        QString newPasswordHash = setPasswordDialog.getPassword_setPasswordDialog();
        qDebug() << "New password hash obtained: " << newPasswordHash;
        settings.setValue("passwordHash", newPasswordHash);
        settings.sync();  // Sicherstellen, dass die Einstellungen geschrieben werden
        qDebug() << "New password set in QSettings.";
    } else {
        qDebug() << "Set password dialog canceled.";
    }
}

// Methode zum Zurücksetzen des Passworts
void MainWindow::resetPassword() {
    qDebug() << "ResetPasswordAction triggered";
    SecurityQuestionDialog securityDialog(this);
    if (securityDialog.exec() == QDialog::Accepted) {
        qDebug() << "Security question answered correctly. Setting new password.";
        SetPasswordDialog setPasswordDialog(this);
        if (setPasswordDialog.exec() == QDialog::Accepted) {
            QString newPasswordHash = setPasswordDialog.getPassword_setPasswordDialog();
            qDebug() << "New password hash obtained: " << newPasswordHash;
            QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
            QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
            settings.setValue("passwordHash", newPasswordHash);
            settings.sync();  // Sicherstellen, dass die Einstellungen geschrieben werden
            qDebug() << "New password set in QSettings.";
        } else {
            qDebug() << "Set password dialog canceled.";
        }
    } else {
        qDebug() << "Security question dialog canceled.";
    }
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

QAction* MainWindow::getSetPasswordAction() const {
    return ui->setPasswordAction;
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

        // Speichern der Notiz als HTML-Datei
        QString filename = directoryPath_temp + QString::fromStdString(note.title) + ".html";
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << QString::fromStdString(note.content);
            file.close();
        } else {
            qDebug() << "Fehler beim Öffnen der Datei zum Schreiben:" << filename;
        }

        // Optional: Zusammenfassung in notes.txt speichern
        QString directoryPath_sys = appDirPath + "/sys/";
        QDir directory_sys(directoryPath_sys);
        if (!directory_sys.exists()) {
            qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath_sys;
            if (!directory_sys.mkpath(directoryPath_sys)) {
                qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath_sys;
                return;
            }
        }

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

void MainWindow::showMainMenu() {
    this->show();
    getAddNoteButton()->show();
    getDisplayNotesButton()->show();
    getEditNoteButton()->show();
    getDeleteNoteButton()->show();
    getExitButton()->show();
}
