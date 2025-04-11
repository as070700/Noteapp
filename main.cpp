// Created by Angelika Schill.
// Projectwork for the course "Anwendungsprogrammierung" at the University of Applied Sciences "Diploma" in Bad Sooden-Allendorf.
// This file is part of the Noteapp project.

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Initialisiert die QApplication, die für jede Qt-Anwendung erforderlich ist
    QApplication app(argc, argv);

    // Erstellt das Hauptfenster der Anwendung
    MainWindow mainWindow;

    // Zeigt das Hauptfenster an
    mainWindow.show();

    // Startet die Ereignisschleife der Anwendung
    return app.exec();
}
