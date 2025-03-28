#include "newnote.h"
#include "ui_newnote.h"
#include "setpassworddialog.h"
#include "getpassworddialog.h"
#include "utils.h"  // Hinzufügen dieser Zeile
#include <QTextCharFormat>
#include <QColorDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
#include <QStandardPaths>
#include <QDebug>
#include <QLabel>
#include <QVBoxLayout>
#include <QPushButton>

NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    connect(ui->saveButton_newnote, &QPushButton::clicked, this, &NewNote::saveNote_password_NewNote);
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

void NewNote::saveNote_password_NewNote()
{
    qDebug() << "Entering saveNote_password_NewNote";
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    QString correctHash = settings.value("passwordHash").toString();
    qDebug() << "Loaded password hash from settings:" << correctHash;

    if (correctHash.isEmpty()) {
        qDebug() << "No password hash found, prompting to set a new password";
        SetPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString newPassword = passwordDialog.getPassword_setPasswordDialog();
            QString newHash = hashPassword(newPassword);
            settings.setValue("passwordHash", newHash);
            qDebug() << "New password hash set:" << newHash;
        } else {
            qDebug() << "Password setting canceled";
            return;
        }
    } else {
        qDebug() << "Password hash found, prompting for password";

        getPasswordDialog *passwordDialog = new getPasswordDialog(this);  // Dynamische Erstellung

        connect(passwordDialog, &getPasswordDialog::passwordCorrect_getpassworddialog, this, [this, passwordDialog]() {
            passwordDialog->deleteLater();  // Dialog sicher löschen
            saveNote_newnote();  // Speichern der Notiz
        });

        connect(passwordDialog, &getPasswordDialog::passwortIncorrect_getpassworddialog, this, [passwordDialog]() {
            QMessageBox::warning(passwordDialog, "Fehler", "Falsches Passwort.");
        });

        passwordDialog->exec();  // Startet den Dialog
    }
    qDebug() << "Exiting saveNote_password_NewNote";
}


void NewNote::saveNote_newnote() {
    qDebug() << "Entering saveNote_newnote";
    QString title = getTitle_newnote();
    QString content = getContent_newnote();
    qDebug() << "Title:" << title;
    qDebug() << "Content:" << content;

    if (title.isEmpty()) {
        QMessageBox::warning(this, "Fehler", "Der Titel darf nicht leer sein.");
        qDebug() << "Title is empty, exiting saveNote_newnote";
        return;
    }

    QString dirPath = "./temp/";
    QDir dir(dirPath);
    qDebug() << "Directory path:" << dirPath;

    if (!dir.exists()) {
        qDebug() << "Directory does not exist, creating directory";
        if (!dir.mkpath(dirPath)) {
            QMessageBox::warning(this, "Fehler", "Konnte das Verzeichnis nicht erstellen: " + dirPath);
            qDebug() << "Failed to create directory:" << dirPath;
            return;
        }
    }

    QString filePath = dirPath + title + ".html";
    QFile file(filePath);
    qDebug() << "File path:" << filePath;

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht öffnen: " + filePath);
        qDebug() << "Failed to open file:" << filePath;
        return;
    }

    QTextStream out(&file);
    out << content;
    file.close();
    qDebug() << "File written and closed successfully";

    qDebug() << "Before alternative notification";
    QDialog* successDialog = new QDialog(this);
    successDialog->setWindowTitle("Erfolg");
    QVBoxLayout* layout = new QVBoxLayout(successDialog);
    QLabel* successLabel = new QLabel("Die Notiz wurde gespeichert.");
    layout->addWidget(successLabel);
    QPushButton* okButton = new QPushButton("OK");
    layout->addWidget(okButton);
    connect(okButton, &QPushButton::clicked, successDialog, &QDialog::accept);
    connect(successDialog, &QDialog::accepted, successDialog, &QDialog::deleteLater);
    successDialog->setLayout(layout);
    successDialog->exec(); // Modal anzeigen
    qDebug() << "After alternative notification";

    qDebug() << "Before accept()";
    accept();
    qDebug() << "After accept()";
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
