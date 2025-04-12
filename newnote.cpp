// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "newnote.h"
#include "ui_newnote.h"
#include <QTextCharFormat>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QDir>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Slots
NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);

    // Verbindungen zwischen Buttons und Funktionen herstellen
    connect(ui->saveButton_newnote, &QPushButton::clicked, this, &NewNote::saveNote_newnote);
    connect(ui->backButton_newnote, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->boldButton_newnote, &QPushButton::clicked, this, &NewNote::setBold_newnote);
    connect(ui->italicButton_newnote, &QPushButton::clicked, this, &NewNote::setItalic_newnote);
    connect(ui->underlineButton_newnote, &QPushButton::clicked, this, &NewNote::setUnderline_newnote);
    connect(ui->colorButton_newnote, &QPushButton::clicked, this, &NewNote::setColor_newnote);
    connect(ui->fontSizeComboBox_newnote, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &NewNote::setFontSize_newnote);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
NewNote::~NewNote() {
    delete ui;
}

// Gibt den Titel der Notiz zurück
QString NewNote::getTitle_newnote() const {
    return ui->title_lineEdit_newnote->text();
}

// Gibt den Inhalt der Notiz zurück
QString NewNote::getContent_newnote() const {
    return ui->content_lineEdit_newnote->toHtml();
}

// Speichert die Notiz
void NewNote::saveNote_newnote() {
    QString title = getTitle_newnote();
    QString content = getContent_newnote();

    // Überprüfen, ob der Titel leer ist
    if (title.isEmpty()) {
        ui->errorLabel_newnote->setText("Fehler: Der Titel darf nicht leer sein.");
        ui->errorLabel_newnote->setStyleSheet("color: red;");
        return;
    }

    // Verzeichnis für die Notizen
    QString dirPath = "./temp/";
    QDir dir(dirPath);
    if (!dir.exists() && !dir.mkpath(dirPath)) {
        ui->errorLabel_newnote->setText("Fehler: Konnte das Verzeichnis nicht erstellen: " + dirPath);
        return;
    }

    // Datei für die Notiz erstellen
    QString filePath = dirPath + title + ".html"; // Speichern als HTML-Datei
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->errorLabel_newnote->setText("Fehler: Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream out(&file);

    // Inhalt in die Datei schreiben
    out << content;

    file.close();

    // Signal auslösen, wenn die Notiz erfolgreich gespeichert wurde
    emit noteSaved_newnote();

    // Schließe den Dialog
    accept();
}

// Setzt den Text fett
void NewNote::setBold_newnote() {
    QTextCharFormat format;
    format.setFontWeight(ui->content_lineEdit_newnote->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    mergeFormatOnWordOrSelection(format);
}

// Setzt den Text kursiv
void NewNote::setItalic_newnote() {
    QTextCharFormat format;
    format.setFontItalic(!ui->content_lineEdit_newnote->fontItalic());
    mergeFormatOnWordOrSelection(format);
}

// Unterstreicht den Text
void NewNote::setUnderline_newnote() {
    QTextCharFormat format;
    format.setFontUnderline(!ui->content_lineEdit_newnote->fontUnderline());
    mergeFormatOnWordOrSelection(format);
}

// Ändert die Textfarbe
void NewNote::setColor_newnote() {
    QColor color = QColorDialog::getColor(ui->content_lineEdit_newnote->textColor(), this);
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        mergeFormatOnWordOrSelection(format);
    }
}

// Ändert die Schriftgröße
void NewNote::setFontSize_newnote(int index) {
    int fontSize = ui->fontSizeComboBox_newnote->itemText(index).toInt();
    if (fontSize > 0) {
        QTextCharFormat format;
        format.setFontPointSize(fontSize);
        mergeFormatOnWordOrSelection(format);
    }
}

// Wendet Formatierungen auf das aktuelle Wort oder die Auswahl an
void NewNote::mergeFormatOnWordOrSelection(const QTextCharFormat &format) {
    QTextCursor cursor = ui->content_lineEdit_newnote->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->content_lineEdit_newnote->mergeCurrentCharFormat(format);
}
