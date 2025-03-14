#include "detaileditnote.h"
#include "ui_detaileditnote.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);

    connect(ui->backButton_detaileditnote, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->saveButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::saveNote); // Verbindung zum Speichern
}

detaileditnote::~detaileditnote()
{
    delete ui;
}

void detaileditnote::setNoteContent_edit(const QString &title, const QString &content) {
    ui->title_textEdit_detaileditnote->setText(title);
    ui->title_textEdit_detaileditnote->setProperty("oldTitle", title); // Speichere den alten Titel
    ui->content_textEdit_detaileditnote->setText(content);
}

void detaileditnote::saveNote()
{
    QString title = ui->title_textEdit_detaileditnote->toPlainText();
    QString content = ui->content_textEdit_detaileditnote->toPlainText();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Der Titel darf nicht leer sein.");
        return;
    }

    QString filePath = "./temp/" + title + ".txt";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    // Überprüfe, ob es eine alte Datei mit einem anderen Namen gibt und lösche sie
    QString oldTitle = ui->title_textEdit_detaileditnote->property("oldTitle").toString();
    if (!oldTitle.isEmpty() && oldTitle != title) {
        QFile::remove("./temp/" + oldTitle + ".txt");
    }

    QMessageBox::information(this, "Erfolg", "Die Notiz wurde gespeichert.");
    accept(); // Schließt den Dialog nach dem Speichern
}
