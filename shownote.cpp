#include "shownote.h"
#include "ui_shownote.h"
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

    try {
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

            QTextStream in(&file);
            QString content = in.readAll();
            QListWidgetItem *item = new QListWidgetItem(filename);
            item->setData(Qt::UserRole, content);
            ui->listview_shownote->addItem(item);
            file.close();
        }

        // Verbindung des Signals itemClicked mit dem Slot showNoteContent
        connect(ui->listview_shownote, &QListWidget::itemClicked, this, &shownote::showNoteContent);
    } catch (const std::exception& e) {
        qDebug() << "Exception caught: " << e.what();
        QMessageBox::critical(this, "Fehler", "Ein Fehler ist aufgetreten: " + QString::fromStdString(e.what()));
    }
}

shownote::~shownote()
{
    delete ui;
}

void shownote::showNoteContent(QListWidgetItem *item)
{
    try {
        QString content = item->data(Qt::UserRole).toString();
        QMessageBox::information(this, "Notizinhalt", content);
    } catch (const std::exception& e) {
        qDebug() << "Exception caught: " << e.what();
        QMessageBox::critical(this, "Fehler", "Ein Fehler ist aufgetreten: " + QString::fromStdString(e.what()));
    }
}
