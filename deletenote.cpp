#include "deletenote.h"
#include "ui_deletenote.h"
#include "mainwindow.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

deletenote::deletenote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletenote)
{
    ui->setupUi(this);
    loadNotes();
    ui->listWidget_deleteNote->setSelectionMode(QAbstractItemView::MultiSelection); // Ermöglicht Mehrfachauswahl
}

deletenote::~deletenote()
{
    delete ui;
}

void deletenote::loadNotes()
{
    // Verzeichnis mit den Notizdateien
    QString directoryPath = "./temp/";
    QDir directory(directoryPath);
    if (!directory.exists()) {
        qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath;
        if (!directory.mkpath(directoryPath)) {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath;
            return;
        }
    }

    QStringList textFiles = directory.entryList(QStringList() << "*.txt", QDir::Files);
    if (textFiles.isEmpty()) {
        qDebug() << "Keine Textdateien im Verzeichnis" << directoryPath;
    }

    // Schleife durch alle Textdateien und Hinzufügen der Notizen zur Liste
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
            continue;
        }

        // Entfernen der .txt Erweiterung aus dem Dateinamen
        QString displayName = filename;
        if (displayName.endsWith(".txt")) {
            displayName.chop(4); // Entfernt die letzten 4 Zeichen
        }

        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName);
        item->setData(Qt::UserRole, content);
        ui->listWidget_deleteNote->addItem(item);
        file.close();
    }
}

void deletenote::on_deleteButton_deleteNote_clicked()
{
    QList<QListWidgetItem *> selectedItems = ui->listWidget_deleteNote->selectedItems();
    if (!selectedItems.isEmpty()) {
        bool allDeleted = true;
        foreach(QListWidgetItem *item, selectedItems) {
            QString displayName = item->text();
            QString filePath = "./temp/" + displayName + ".txt";

            if (QFile::remove(filePath)) {
                delete item;  // Entfernt das selektierte Item
            } else {
                allDeleted = false;
            }
        }

        if (allDeleted) {
            QMessageBox::information(this, "Notizen gelöscht", "Alle ausgewählten Notizen wurden gelöscht.");
        } else {
            QMessageBox::warning(this, "Fehler", "Einige Notizdateien konnten nicht gelöscht werden.");
        }
    } else {
        QMessageBox::warning(this, "Keine Auswahl", "Bitte wählen Sie mindestens eine Notiz aus, die gelöscht werden soll.");
    }
}

void deletenote::on_backButton_deleteNote_clicked() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget());
    if (mainWindow) {
        mainWindow->show();
        mainWindow->getAddNoteButton()->show();
        mainWindow->getDisplayNotesButton()->show();
        mainWindow->getEditNoteButton()->show();
        mainWindow->getDeleteNoteButton()->show();
        mainWindow->getExitButton()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}
