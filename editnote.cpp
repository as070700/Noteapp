#include "editnote.h"
#include "ui_editnote.h"
#include "mainwindow.h"
#include "detaileditnote.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <exception>

editnote::editnote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editnote)
{
    ui->setupUi(this);

    // Verzeichnis mit den Notizdateien
    QString appDirPath = QCoreApplication::applicationDirPath();
    QString directoryPath = appDirPath + "/temp/";
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
        ui->listWidget_editnote->addItem(item);
        file.close();
    }
}

editnote::~editnote()
{
    delete ui;
}

void editnote::on_pushButton_back_clicked() {
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

void editnote::on_pushButton_open_clicked() {
    QListWidgetItem *currentItem = ui->listWidget_editnote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        detaileditnote *detaileditDialog = new detaileditnote(this);
        detaileditDialog->setNoteContent_edit(title, content); // Methode zum Setzen des Inhalts im Dialog
        detaileditDialog->exec(); // Öffnet den Dialog
    } else {
        QMessageBox::warning(this, "Warnung", "Bitte wählen Sie eine Notiz aus.");
    }
}
