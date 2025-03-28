#ifndef SETPASSWORDDIALOG_H
#define SETPASSWORDDIALOG_H

#include <QDialog>

namespace Ui {
class SetPasswordDialog;
}

class SetPasswordDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SetPasswordDialog(QWidget *parent = nullptr);
    ~SetPasswordDialog();

    QString getPassword_setPasswordDialog() const;

signals:
    void passwordSet_setPasswordDialog(); // Signal deklarieren

private slots:
    void on_okButton_setPasswordDialog_clicked(); // Methode deklarieren
    void on_cancelButton_setPasswordDialog_clicked(); // Methode deklarieren

private:
    Ui::SetPasswordDialog *ui;
    QString passwordHash_setPasswordDialog;
};

#endif // SETPASSWORDDIALOG_H
