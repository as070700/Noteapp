#include "newnote.h"
#include "ui_newnote.h"
#include "setpassworddialog.h"
#include "getpassworddialog.h"
#include "utils.h" // Hilfsfunktionen (falls benötigt)
#include <QTextCharFormat>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>

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

// Speichert die Notiz mit Passwortschutz (falls aktiviert)
void NewNote::saveNote_password_NewNote()
{
    getPasswordDialog passwordDialog(this);
    connect(&passwordDialog, &getPasswordDialog::passwordCorrect_getpassworddialog, this, &NewNote::saveNote_newnote); // Verbindung herstellen
    passwordDialog.exec();
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

    // Passwortschutz-Information als Kommentar im <head>-Tag speichern
    bool isProtected = ui->passwordProtectionCheckBox_newnote->isChecked();
    qDebug() << "isProtected: " << isProtected;

    // Kommentar für Passwortschutz hinzufügen
    QString protectedComment = QString("<!-- protected: %1 -->\n").arg(isProtected ? "true" : "false");
    content.replace("<head>", QString("<head>\n%1").arg(protectedComment));

    // Inhalt in die Datei schreiben
    out << content;
    qDebug() << "content: " << content;
    file.close();

    ui->errorLabel_newnote->setText("Erfolg: Die Notiz wurde gespeichert.");
    ui->errorLabel_newnote->setStyleSheet("color: green;");
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
