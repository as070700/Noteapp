#include "shownote.h"
#include "ui_shownote.h"
#include "mainwindow.h"
#include "detailshownote.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <exception>

shownote::shownote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shownote)
{
    ui->setupUi(this);

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
        ui->listview_shownote->addItem(item);
        file.close();
    }

    // Verbindung des Signals itemClicked mit dem Slot showNoteContent
    // connect(ui->listview_shownote, &QListWidget::itemClicked, this, &shownote::showNoteContent);
}

shownote::~shownote()
{
    delete ui;
}

// void shownote::showNoteContent(QListWidgetItem *item)
// {
//     QString content = item->data(Qt::UserRole).toString();
//     QMessageBox::information(this, "Notizinhalt", content);
// }

void shownote::on_pushButton_back_clicked() {
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

void shownote::on_pushButton_open_clicked() {
    QListWidgetItem *currentItem = ui->listview_shownote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        detailShownote *detailDialog = new detailShownote(this);
        detailDialog->setNoteContent_show(title, content); // Methode zum Setzen des Inhalts im Dialog
        detailDialog->exec(); // Öffnet den Dialog
    } else {
        QMessageBox::warning(this, "Warnung", "Bitte wählen Sie eine Notiz aus.");
    }
}
