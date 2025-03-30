#include "setpassworddialog.h"
#include "newnote.h"
#include "mainwindow.h"
#include <QApplication>
#include <QDebug>
#include <QSettings>
#include <QStandardPaths>
#include <QDir>

int main(int argc, char *argv[])
{
    // Initialisiert die QApplication, die für jede Qt-Anwendung erforderlich ist
    QApplication app(argc, argv);
    qDebug() << "Application gestartet";

    // Pfad zum Verzeichnis für Systemeinstellungen (z. B. Passwortspeicherung)
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QDir sysDir(sysDirPath);

    // Überprüfen, ob das Verzeichnis existiert, und ggf. erstellen
    if (!sysDir.exists()) {
        if (sysDir.mkpath(".")) {
            qDebug() << "Verzeichnis 'sys' erstellt:" << sysDirPath;
        } else {
            qDebug() << "Fehler beim Erstellen des Verzeichnisses 'sys':" << sysDirPath;
            return -1; // Beendet die Anwendung, wenn das Verzeichnis nicht erstellt werden kann
        }
    }

    // Initialisiert QSettings, um Einstellungen in einer INI-Datei zu speichern
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    qDebug() << "QSettings initialisiert";

    // Erstellt das Hauptfenster der Anwendung
    MainWindow mainWindow;
    qDebug() << "MainWindow erstellt";

    // Zeigt das Hauptfenster an
    mainWindow.show();
    qDebug() << "MainWindow angezeigt";

    // Startet die Ereignisschleife der Anwendung
    return app.exec();
}
