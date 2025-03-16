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

private slots: // Change to slots
    void on_buttonBox_accepted(); // Ensure this is declared

private:
    Ui::SetPasswordDialog *ui;
    QString passwordHash;
};

#endif // SETPASSWORDDIALOG_H
