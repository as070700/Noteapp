#ifndef GETPASSWORDDIALOG_H
#define GETPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class getPasswordDialog;
}

class getPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getPasswordDialog(QWidget *parent = nullptr); // Konstruktor
    ~getPasswordDialog(); // Destruktor

    QString getPassword_getPasswordDialog() const; // Gibt das eingegebene Passwort zurück

signals:
    void passwordCorrect_getpassworddialog(); // Signal, das bei korrektem Passwort ausgelöst wird

private slots:
    void on_okButton_getpassworddialog_clicked(); // Slot für den OK-Button
    void on_cancelButton_getpassworddialog_clicked(); // Slot für den Abbrechen-Button

private:
    Ui::getPasswordDialog *ui; // Benutzeroberfläche
};

#endif // GETPASSWORDDIALOG_H
