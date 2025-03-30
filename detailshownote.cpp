#include "detailshownote.h"
#include "getpassworddialog.h"
#include "ui_detailshownote.h"
#include "getpassworddialog.h"
#include <QSettings>
#include <QStandardPaths>
#include <QMessageBox>
#include <QRegularExpression>
#include <QFile>
#include <QTextStream>

detailShownote::detailShownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailShownote)
{
    ui->setupUi(this);

    connect(ui->backButton_detailshownote, &QPushButton::clicked, this, &QDialog::reject);

    // Set the background of content_textEdit_detailshownote to transparent
    ui->content_textEdit_detailshownote->setStyleSheet("background: transparent");
}

detailShownote::~detailShownote()
{
    delete ui;
}

void detailShownote::setNoteContent_show(const QString &title, const QString &content) {
    ui->label_title_detailshownote->setText(title);

    // Überprüfen, ob die Notiz passwortgeschützt ist
    QRegularExpression protectedRegex("<!--\\s*protected:\\s*true\\s*-->");
    bool isProtected = protectedRegex.match(content).hasMatch();
    ui->passwordProtectionCheckBox_detailshownote->setChecked(isProtected);

    qDebug() << "HTML-Inhalt:" << content;
    qDebug() << "Passwortschutz erkannt:" << isProtected;

    // Entfernen des Passwortschutz-Kommentars aus dem angezeigten Inhalt
    QString cleanedContent = content;
    cleanedContent.remove(protectedRegex);
    ui->content_textEdit_detailshownote->setHtml(cleanedContent);

    // Checkbox deaktivieren, damit der Benutzer sie nicht ändern kann
    ui->passwordProtectionCheckBox_detailshownote->setEnabled(false);
}

void detailShownote::loadNoteContent_detailshownote(const QString &noteTitle, const QString &noteContent) {
    QString filePath = "./temp/" + noteTitle + ".html"; // Nur HTML-Datei laden
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Fehler", "Konnte Datei nicht öffnen: " + filePath);
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();
    file.close();

    // Überprüfen, ob die Notiz passwortgeschützt ist
    QRegularExpression protectedRegex("<!--\\s*protected:\\s*true\\s*-->");
    bool isProtected = protectedRegex.match(content).hasMatch();
    ui->passwordProtectionCheckBox_detailshownote->setChecked(isProtected);

    if (isProtected) {
        getPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString enteredPasswordHash = passwordDialog.getPassword_getPasswordDialog();
            QString correctPasswordHash = "hashed_password"; // Ersetzen Sie dies durch die tatsächliche Logik

            if (enteredPasswordHash != correctPasswordHash) {
                QMessageBox::warning(this, "Falsches Passwort", "Das eingegebene Passwort ist falsch.");
                return;
            }
        } else {
            return; // Abbrechen, wenn der Benutzer den Dialog schließt
        }
    }

    // Notizinhalt laden
    setNoteContent_show(noteTitle, content);
}

bool detailShownote::isNotePasswordProtected_detailshownote(const QString &noteTitle) {
    // Hier können Sie die Logik implementieren, um zu überprüfen, ob die Notiz passwortgeschützt ist.
    // Zum Beispiel könnten Sie eine spezielle Datei oder Metadaten verwenden, um dies zu speichern.
    // Für dieses Beispiel nehmen wir an, dass passwortgeschützte Notizen ein bestimmtes Präfix haben.
    return noteTitle.startsWith("[Protected]");
}

