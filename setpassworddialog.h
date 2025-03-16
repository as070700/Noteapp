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

private slots:
    void on_okButton_setPasswordDialog_clicked(); // Ensure this is declared
    void on_cancelButton_setPasswordDialog_clicked(); // Ensure this is declared

private:
    Ui::SetPasswordDialog *ui;
    QString passwordHash;
};

#endif // SETPASSWORDDIALOG_H
