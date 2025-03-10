#include "shownote.h"
#include "ui_shownote.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>

shownote::shownote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shownote)
{
    ui->setupUi(this);

    // Verzeichnis mit den Notizdateien
    QDir directory("./temp/");
    QStringList textFiles = directory.entryList(QStringList() << "*.txt", QDir::Files);

    // Schleife durch alle Textdateien und Hinzufügen der Notizen zur Liste
    foreach(QString filename, textFiles) {
        QFile file(directory.filePath(filename));
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QString content = in.readAll();
            QListWidgetItem *item = new QListWidgetItem(filename);
            item->setData(Qt::UserRole, content);
            ui->listview_shownote->addItem(item);
            file.close();
        }
    }

    // Verbindung des Signals itemClicked mit dem Slot showNoteContent
    connect(ui->listview_shownote, &QListWidget::itemClicked, this, &shownote::showNoteContent);
}

shownote::~shownote()
{
    delete ui;
}

void shownote::showNoteContent(QListWidgetItem *item)
{
    QString content = item->data(Qt::UserRole).toString();
    QMessageBox::information(this, "Notizinhalt", content);
}
