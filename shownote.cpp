#include "shownote.h"
#include "setpassworddialog.h"
#include "getpassworddialog.h"
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

shownote::shownote(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shownote)
{
    ui->setupUi(this);

    QString directoryPath = "./temp/";
    QDir directory(directoryPath);
    if (!directory.exists()) {
        qDebug() << "Verzeichnis existiert nicht. Erstelle Verzeichnis:" << directoryPath;
        if (!directory.mkpath(directoryPath)) {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses:" << directoryPath;
            return;
        }
    }

    QStringList htmlFiles = directory.entryList(QStringList() << "*.html", QDir::Files); // Change to .html
    if (htmlFiles.isEmpty()) {
        qDebug() << "Keine HTML-Dateien im Verzeichnis" << directoryPath;
    }

    foreach(QString filename, htmlFiles) {
        QFile file(directory.filePath(filename));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Konnte Datei nicht öffnen:" << filename;
            continue;
        }

        QString displayName = filename;
        if (displayName.endsWith(".html")) {
            displayName.chop(5); // Entfernt die letzten 5 Zeichen
        }

        QTextStream in(&file);
        QString content = in.readAll();
        QListWidgetItem *item = new QListWidgetItem(displayName);
        item->setData(Qt::UserRole, content);
        ui->listview_shownote->addItem(item);
        file.close();
    }
}

shownote::~shownote()
{
    delete ui;
}

//Getter-Methoden für die Buttons & Felder
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
    }

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

void shownote::on_openButton_shownote_clicked() {
    QListWidgetItem *currentItem = ui->listview_shownote->currentItem();
    if (currentItem) {
        QString title = currentItem->text();
        QString content = currentItem->data(Qt::UserRole).toString();

        detailShownote *detailDialog = new detailShownote(this);
        detailDialog->loadNoteContent_detailshownote(title, content); // Methode zum Laden der Notiz mit Passwortprüfung
        detailDialog->exec(); // Öffnet den Dialog
    } else {
        QMessageBox::warning(this, "Warnung", "Bitte wählen Sie eine Notiz aus.");
    }
}

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
