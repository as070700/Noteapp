/* #ifndef SETPASSWORDDIALOG_H
#define SETPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class SetPasswordDialog;
}

class SetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPasswordDialog(QWidget *parent = nullptr); // Konstruktor
    ~SetPasswordDialog(); // Destruktor

    QString getPassword_setPasswordDialog() const; // Gibt den Passwort-Hash zurück

signals:
    void passwordSet_setPasswordDialog(); // Signal, das ausgelöst wird, wenn das Passwort gesetzt wurde

private slots:
    void on_okButton_setPasswordDialog_clicked(); // Slot für den OK-Button
    void on_cancelButton_setPasswordDialog_clicked(); // Slot für den Abbrechen-Button

private:
    Ui::SetPasswordDialog *ui; // Benutzeroberfläche
    QString passwordHash_setPasswordDialog; // Gespeicherter Passwort-Hash
};

#endif // SETPASSWORDDIALOG_H
 */