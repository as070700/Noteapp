// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "detaileditnote.h"
#include "ui_detaileditnote.h"
#include <QFile>
#include <QPushButton>
#include <QTextStream>
#include <QDebug>
#include <QTextCharFormat>
#include <QColorDialog>
#include <QSettings>
#include <QStandardPaths>
#include <QRegularExpression>

// Konstruktor: Initialisiert die Benutzeroberfläche und verbindet die Buttons mit den entsprechenden Slots
detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);

    // Verbindungen zwischen Buttons und Funktionen herstellen
    connect(ui->saveButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::on_saveButton_detaileditnote_clicked);
    connect(ui->backButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::on_backButton_detaileditnote_clicked);
    connect(ui->boldButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setBold_detaileditnote);
    connect(ui->italicButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setItalic_detaileditnote);
    connect(ui->underlineButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setUnderline_detaileditnote);
    connect(ui->colorButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setColor_detaileditnote);
    connect(ui->fontSizeComboBox_detaileditnote, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &detaileditnote::setFontSize_detaileditnote);
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
detaileditnote::~detaileditnote()
{
    delete ui;
}

// Setzt den Titel und den Inhalt der Notiz
void detaileditnote::setNoteContent_detaileditnote(const QString &title, const QString &content) {
    ui->title_textEdit_detaileditnote->setText(title);
    ui->title_textEdit_detaileditnote->setProperty("oldTitle", title);

    ui->content_textEdit_detaileditnote->setHtml(content); // Zeigt den Inhalt an
}

// Speichert den Titel und den Inhalt der Notiz
void detaileditnote::saveNoteContent_detaileditnote() {
    QString title = ui->title_textEdit_detaileditnote->toPlainText();
    QString content = ui->content_textEdit_detaileditnote->toHtml();

    if (title.isEmpty()) {
        ui->errorLabel_detaileditnote->setText("Fehler: Der Titel darf nicht leer sein.");
        ui->errorLabel_detaileditnote->setStyleSheet("color: red;");
        return;
    }

    QString filePath = "./temp/" + title + ".html"; // Speichern als HTML-Datei
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        ui->errorLabel_detaileditnote->setText("Fehler: Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream out(&file);

    out << content;
    file.close();
}

// Setzt den Text fett
void detaileditnote::setBold_detaileditnote() {
    QTextCharFormat format;
    format.setFontWeight(ui->content_textEdit_detaileditnote->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    mergeFormatOnWordOrSelection(format);
}

// Setzt den Text kursiv
void detaileditnote::setItalic_detaileditnote() {
    QTextCharFormat format;
    format.setFontItalic(!ui->content_textEdit_detaileditnote->fontItalic());
    mergeFormatOnWordOrSelection(format);
}

// Unterstreicht den Text
void detaileditnote::setUnderline_detaileditnote() {
    QTextCharFormat format;
    format.setFontUnderline(!ui->content_textEdit_detaileditnote->fontUnderline());
    mergeFormatOnWordOrSelection(format);
}

// Ändert die Textfarbe
void detaileditnote::setColor_detaileditnote() {
    QColor color = QColorDialog::getColor(ui->content_textEdit_detaileditnote->textColor(), this);
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        mergeFormatOnWordOrSelection(format);
    }
}

// Ändert die Schriftgröße
void detaileditnote::setFontSize_detaileditnote(int index) {
    int fontSize = ui->fontSizeComboBox_detaileditnote->itemText(index).toInt();
    if (fontSize > 0) {
        QTextCharFormat format;
        format.setFontPointSize(fontSize);
        mergeFormatOnWordOrSelection(format);
    }
}

// Wendet Formatierungen auf das aktuelle Wort oder die Auswahl an
void detaileditnote::mergeFormatOnWordOrSelection(const QTextCharFormat &format) {
    QTextCursor cursor = ui->content_textEdit_detaileditnote->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->content_textEdit_detaileditnote->mergeCurrentCharFormat(format);
}

QString detaileditnote::getNoteContent_detaileditnote() const {
    return ui->content_textEdit_detaileditnote->toHtml();
}

// Schließt den Dialog
void detaileditnote::on_backButton_detaileditnote_clicked() {
    this->reject();
}

// Speichert die Notiz
void detaileditnote::on_saveButton_detaileditnote_clicked() {
    saveNoteContent_detaileditnote();

    // Signal auslösen, wenn die Notiz erfolgreich gespeichert wurde
    emit noteSaved_detaileditnote();

    // Schließe den Dialog
    accept();
}
