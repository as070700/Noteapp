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
    QApplication app(argc, argv);
    qDebug() << "Application started";

    // Set up QSettings to use a file in the sys folder
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QDir sysDir(sysDirPath);
    if (!sysDir.exists()) {
        sysDir.mkpath(".");
        qDebug() << "Created sys directory:" << sysDirPath;
    }
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);
    qDebug() << "QSettings initialized";

    MainWindow mainWindow;
    qDebug() << "MainWindow created";

    mainWindow.show();
    qDebug() << "MainWindow shown";
    return app.exec();
}
