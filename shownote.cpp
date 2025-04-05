#include "shownote.h"
// #include "setpassworddialog.h" // Auskommentiert, da es mit dem Passwortsystem zusammenhängt
// #include "getpassworddialog.h" // Auskommentiert, da es mit dem Passwortsystem zusammenhängt
#include "ui_shownote.h"
#include "mainwindow.h"
#include "detailshownote.h"
#include "searchnote.h"
#include <QListWidgetItem>
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QListView>
#include <QSettings>
#include <QStandardPaths>
#include <QDebug>

// Konstruktor: Initialisiert die Benutzeroberfläche und lädt die Notizen
shownote::shownote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shownote)
{
    ui->setupUi(this);

    QString directoryPath = "./temp/";
    QDir directory(directoryPath);

    // Überprüfen, ob das Verzeichnis existiert, und ggf. erstellen
    if (!directory.exists()) {
        qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath;
        if (!directory.mkpath(directoryPath)) {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath;
            return;
        }
    }

    // Liste aller .html-Dateien im Verzeichnis abrufen
    QStringList htmlFiles = directory.entryList(QStringList() << "*.html", QDir::Files);
    if (htmlFiles.isEmpty()) {
        qDebug() << "Keine HTML-Dateien im Verzeichnis" << directoryPath;
    }

    // Notizen laden und in die Liste einfügen
    foreach(QString filename, htmlFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
            continue;
        }

        QString displayName = filename;
        if (displayName.endsWith(".html")) {
            displayName.chop(5); // Entfernt die letzten 5 Zeichen (".html")
        }

        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName); // Listeneintrag erstellen
        item->setData(Qt::UserRole, content); // Dateiinhalt als zusätzliche Daten speichern
        ui->listview_shownote->addItem(item); // Eintrag zur Liste hinzufügen
        file.close();
    }
}

// Destruktor: Gibt den Speicher der Benutzeroberfläche frei
shownote::~shownote()
{
    delete ui;
}

// Getter-Methoden für die Buttons und Widgets
QLabel* shownote::getLabelShownote() const {
    return ui->label;
}

QScrollArea* shownote::getScrollAreaShownote() const {
    return ui->scrollArea;
}

QWidget* shownote::getScrollAreaWidgetContentsShownote() const {
    return ui->scrollAreaWidgetContents;
}

QListView* shownote::getListviewShownote() const {
    return ui->listview_shownote;
}

QPushButton* shownote::getOpenButtonShownote() const {
    return ui->openButton_shownote;
}

QPushButton* shownote::getBackButtonShownote() const {
    return ui->backButton_shownote;
}

QPushButton* shownote::getSearchButtonShownote() const {
    return ui->searchButton_shownote;
}

/* // Lädt und überprüft das Passwort
void shownote::loadNotePassword_shownote() {
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

    // Überprüfen, ob ein Passwort existiert
    if (!settings.contains("passwordHash") || settings.value("passwordHash").toString().isEmpty()) {
        QMessageBox::information(this, "Passwort setzen", "Es wurde noch kein Passwort gesetzt. Bitte setzen Sie ein neues Passwort.");

        SetPasswordDialog setPasswordDialog(this);
        if (setPasswordDialog.exec() == QDialog::Accepted) {
            QString newPasswordHash = setPasswordDialog.getPassword_setPasswordDialog();
            settings.setValue("passwordHash", newPasswordHash);
            settings.sync(); // Speichern der Einstellungen
            QMessageBox::information(this, "Passwort gesetzt", "Das Passwort wurde erfolgreich gesetzt.");
        } else {
            QMessageBox::warning(this, "Abgebrochen", "Das Setzen eines Passworts wurde abgebrochen.");
            return;
        }
    } else {
        // Passwortabfrage
        getPasswordDialog passwordDialog(this);
        if (passwordDialog.exec() == QDialog::Accepted) {
            QString enteredPasswordHash = passwordDialog.getPassword_getPasswordDialog();
            QString correctPasswordHash = settings.value("passwordHash").toString();

            if (enteredPasswordHash != correctPasswordHash) {
                QMessageBox::warning(this, "Falsches Passwort", "Das eingegebene Passwort ist falsch.");
                return;
            }
        } else {
            return; // Abbrechen, wenn der Benutzer den Dialog schließt
        }
    }
} */

// Slot: Zurück-Button - Zurück zur Hauptansicht
void shownote::on_backButton_shownote_clicked() {
    MainWindow *mainWindow = qobject_cast<MainWindow*>(parentWidget());
    if (mainWindow) {
        mainWindow->show();
        mainWindow->getAddNoteButton()->show();
        mainWindow->getDisplayNotesButton()->show();
        mainWindow->getEditNoteButton()->show();
        mainWindow->getDeleteNoteButton()->show();
        mainWindow->getExitButton()->show();
    }
    this->hide(); // Versteckt das aktuelle Widget
}

// Slot: Öffnen-Button - Öffnet die ausgewählte Notiz im Detaildialog
void shownote::on_openButton_shownote_clicked() {
    QListWidgetItem *currentItem = ui->listview_shownote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        detailShownote *detailDialog = new detailShownote(this);
        detailDialog->loadNoteContent_detailshownote(title, content); // Methode zum Laden der Notiz
        detailDialog->exec(); // Öffnet den Dialog
    } else {
        QMessageBox::warning(this, "Warnung", "Bitte wählen Sie eine Notiz aus.");
    }
}

// Slot: Such-Button - Öffnet das Suchfenster
void shownote::on_searchButton_shownote_clicked() {
    searchnote *noteWidget_searchnote = new searchnote(this);
    noteWidget_searchnote->show();

    if (noteWidget_searchnote->isVisible()) {
        getLabelShownote()->hide();
        getScrollAreaShownote()->hide();
        getScrollAreaWidgetContentsShownote()->hide();
        getListviewShownote()->hide();
        getOpenButtonShownote()->hide();
        getBackButtonShownote()->hide();
        getSearchButtonShownote()->hide();
    }
}
