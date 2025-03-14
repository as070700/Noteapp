#include "searchnote.h"
#include "shownote.h"
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

    connect(ui->searchButton_searchnote, &QPushButton::clicked, this, &searchnote::on_searchButton_searchnote_clicked);
}

searchnote::~searchnote()
{
    delete ui;
}

void searchnote::on_searchButton_searchnote_clicked()
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

void searchnote::on_backButton_searchnote_clicked(){
    shownote *showNote = qobject_cast<shownote*>(parentWidget());
    if (showNote) {
        showNote->show();
        showNote->getLabelShownote()->show();
        showNote->getScrollAreaShownote()->show();
        showNote->getScrollAreaWidgetContentsShownote()->show();
        showNote->getListviewShownote()->show();
        showNote->getOpenButtonShownote()->show();
        showNote->getBackButtonShownote()->show();
        showNote->getSearchButtonShownote()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}
