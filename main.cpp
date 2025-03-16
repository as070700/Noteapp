#include "setpassworddialog.h"
#include "newnote.h"
#include <QApplication>
#include <QMainWindow>
#include <QMenuBar>
#include <QAction>
#include <QSettings>
#include <QStandardPaths>
#include <QDir>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Set up QSettings to use a file in the sys folder
    QString sysDirPath = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) + "/sys";
    QDir sysDir(sysDirPath);
    if (!sysDir.exists()) {
        sysDir.mkpath(".");
    }
    QSettings settings(sysDirPath + "/settings.ini", QSettings::IniFormat);

    QMainWindow mainWindow;

    QMenu *menu = mainWindow.menuBar()->addMenu("Einstellungen");
    QAction *setPasswordAction = menu->addAction("Passwort setzen");

    QObject::connect(setPasswordAction, &QAction::triggered, [&]() {
        SetPasswordDialog dialog(&mainWindow);
        if (dialog.exec() == QDialog::Accepted) {
            QString passwordHash = dialog.getPassword_setPasswordDialog();
            settings.setValue("passwordHash", passwordHash);
        }
    });

    mainWindow.show();
    return app.exec();
}
