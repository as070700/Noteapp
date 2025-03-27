#include "getpassworddialog.h"
#include "detaileditnote.h"
#include "ui_detaileditnote.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>
#include <QTextCharFormat>
#include <QColorDialog>
#include <QSettings>
#include <QStandardPaths>

detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);

    connect(ui->backButton_detaileditnote, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->saveButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::saveNote_detaileditnote);
    connect(ui->boldButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setBold_detaileditnote);
    connect(ui->italicButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setItalic_detaileditnote);
    connect(ui->underlineButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setUnderline_detaileditnote);
    connect(ui->colorButton_detaileditnote, &QPushButton::clicked, this, &detaileditnote::setColor_detaileditnote);
    connect(ui->fontSizeComboBox_detaileditnote, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &detaileditnote::setFontSize_detaileditnote);
}

detaileditnote::~detaileditnote()
{
    delete ui;
}

void detaileditnote::setNoteContent_detaileditnote(const QString &title, const QString &content) {
    ui->title_textEdit_detaileditnote->setText(title);
    ui->title_textEdit_detaileditnote->setProperty("oldTitle", title);
    ui->content_textEdit_detaileditnote->setText(content);
}

void detaileditnote::saveNote_detaileditnote()
{
    // Passwortabfrage durchführen
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    QString correctHash = settings.value("passwordHash").toString();

    getPasswordDialog passwordDialog(this);
    if (passwordDialog.exec() == QDialog::Accepted) {
        QString passwordHash = passwordDialog.getPassword_getPasswordDialog();
        if (passwordHash != correctHash) {
            QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
            return;
        }
    } else {
        return;
    }

    QString title = ui->title_textEdit_detaileditnote->toPlainText();
    QString content = ui->content_textEdit_detaileditnote->toHtml(); // Save as HTML

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Der Titel darf nicht leer sein.");
        return;
    }

    QString filePath = "./temp/" + title + ".html"; // Change extension to .html
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    QString oldTitle = ui->title_textEdit_detaileditnote->property("oldTitle").toString();
    if (!oldTitle.isEmpty() && oldTitle != title) {
        QFile::remove("./temp/" + oldTitle + ".html"); // Change extension to .html
    }

    QMessageBox::information(this, "Erfolg", "Die Notiz wurde gespeichert.");
    accept();
}

void detaileditnote::setBold_detaileditnote() {
    QTextCharFormat format;
    format.setFontWeight(ui->content_textEdit_detaileditnote->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    mergeFormatOnWordOrSelection(format);
}

void detaileditnote::setItalic_detaileditnote() {
    QTextCharFormat format;
    format.setFontItalic(!ui->content_textEdit_detaileditnote->fontItalic());
    mergeFormatOnWordOrSelection(format);
}

void detaileditnote::setUnderline_detaileditnote() {
    QTextCharFormat format;
    format.setFontUnderline(!ui->content_textEdit_detaileditnote->fontUnderline());
    mergeFormatOnWordOrSelection(format);
}

void detaileditnote::setColor_detaileditnote() {
    QColor color = QColorDialog::getColor(ui->content_textEdit_detaileditnote->textColor(), this);
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        mergeFormatOnWordOrSelection(format);
    }
}

void detaileditnote::setFontSize_detaileditnote(int index) {
    int fontSize = ui->fontSizeComboBox_detaileditnote->itemText(index).toInt();
    if (fontSize > 0) {
        QTextCharFormat format;
        format.setFontPointSize(fontSize);
        mergeFormatOnWordOrSelection(format);
    }
}

void detaileditnote::mergeFormatOnWordOrSelection(const QTextCharFormat &format) {
    QTextCursor cursor = ui->content_textEdit_detaileditnote->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->content_textEdit_detaileditnote->mergeCurrentCharFormat(format);
}
