#include "newnote.h"
#include "ui_newnote.h"
#include "setpassworddialog.h"
#include <QTextCharFormat>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>

NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    connect(ui->saveButton_newnote, &QPushButton::clicked, this, &NewNote::saveNote_newnote);
    connect(ui->backButton_newnote, &QPushButton::clicked, this, &QDialog::reject);
    connect(ui->boldButton_newnote, &QPushButton::clicked, this, &NewNote::setBold_newnote);
    connect(ui->italicButton_newnote, &QPushButton::clicked, this, &NewNote::setItalic_newnote);
    connect(ui->underlineButton_newnote, &QPushButton::clicked, this, &NewNote::setUnderline_newnote);
    connect(ui->colorButton_newnote, &QPushButton::clicked, this, &NewNote::setColor_newnote);
    connect(ui->fontSizeComboBox_newnote, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &NewNote::setFontSize_newnote);
}

NewNote::~NewNote() {
    delete ui;
}

QString NewNote::getTitle_newnote() const {
    return ui->title_lineEdit_newnote->text();
}

QString NewNote::getContent_newnote() const {
    return ui->content_lineEdit_newnote->toHtml();
}

void NewNote::saveNote_newnote() {
    // Load the password hash from settings
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    QString correctHash = settings.value("passwordHash").toString();

    SetPasswordDialog passwordDialog(this);
    if (passwordDialog.exec() == QDialog::Accepted) {
        QString passwordHash = passwordDialog.getPassword_setPasswordDialog();
        if (passwordHash != correctHash) {
            QMessageBox::warning(this, "Fehler", "Falsches Passwort.");
            return;
        }
    } else {
        return;
    }

    QString title = getTitle_newnote();
    QString content = getContent_newnote();

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Der Titel darf nicht leer sein.");
        return;
    }

    QString dirPath = "./temp/";
    QDir dir(dirPath);
    if (!dir.exists()) {
        if (!dir.mkpath(dirPath)) {
            QMessageBox::warning(this, "Fehler", "Konnte das Verzeichnis nicht erstellen: " + dirPath);
            return;
        }
    }

    QString filePath = dirPath + title + ".html";
    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();

    QMessageBox::information(this, "Erfolg", "Die Notiz wurde gespeichert.");
    accept();
}

void NewNote::setBold_newnote() {
    QTextCharFormat format;
    format.setFontWeight(ui->content_lineEdit_newnote->fontWeight() == QFont::Bold ? QFont::Normal : QFont::Bold);
    mergeFormatOnWordOrSelection(format);
}

void NewNote::setItalic_newnote() {
    QTextCharFormat format;
    format.setFontItalic(!ui->content_lineEdit_newnote->fontItalic());
    mergeFormatOnWordOrSelection(format);
}

void NewNote::setUnderline_newnote() {
    QTextCharFormat format;
    format.setFontUnderline(!ui->content_lineEdit_newnote->fontUnderline());
    mergeFormatOnWordOrSelection(format);
}

void NewNote::setColor_newnote() {
    QColor color = QColorDialog::getColor(ui->content_lineEdit_newnote->textColor(), this);
    if (color.isValid()) {
        QTextCharFormat format;
        format.setForeground(color);
        mergeFormatOnWordOrSelection(format);
    }
}

void NewNote::setFontSize_newnote(int index) {
    int fontSize = ui->fontSizeComboBox_newnote->itemText(index).toInt();
    if (fontSize > 0) {
        QTextCharFormat format;
        format.setFontPointSize(fontSize);
        mergeFormatOnWordOrSelection(format);
    }
}

void NewNote::mergeFormatOnWordOrSelection(const QTextCharFormat &format) {
    QTextCursor cursor = ui->content_lineEdit_newnote->textCursor();
    if (!cursor.hasSelection())
        cursor.select(QTextCursor::WordUnderCursor);
    cursor.mergeCharFormat(format);
    ui->content_lineEdit_newnote->mergeCurrentCharFormat(format);
}
