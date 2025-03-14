#include "searchnote.h"
#include "ui_searchnote.h"
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QDebug>

searchnote::searchnote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::searchnote)
{
    ui->setupUi(this);
}

searchnote::~searchnote()
{
    delete ui;
}

void searchnote::on_searchButton_clicked()
{
    QString query = ui->searchLineEdit_searchnote->text();
    searchNotes(query);
}

void searchnote::searchNotes(const QString &query)
{
    ui->searchResultsListWidget_searchnote->clear();

    QString directoryPath = "./temp/";
    QDir directory(directoryPath);
    if (!directory.exists()) {
        qDebug() << "Verzeichnis existiert nicht:" << directoryPath;
        return;
    }

    QStringList textFiles = directory.entryList(QStringList() << "*.txt", QDir::Files);
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
            continue;
        }

        QTextStream in(&file);
        QString content = in.readAll();
        file.close();

        QString title = filename;
        if (title.endsWith(".txt")) {
            title.chop(4); // Entfernt die letzten 4 Zeichen
        }

        if (title.contains(query, Qt::CaseInsensitive) || content.contains(query, Qt::CaseInsensitive)) {
            QListWidgetItem *item = new QListWidgetItem(title);
            item->setData(Qt::UserRole, content);
            ui->searchResultsListWidget_searchnote->addItem(item);
        }
    }
}
