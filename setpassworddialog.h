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
    void passwordSet(); // Signal deklarieren

private slots:
    void on_okButton_setPasswordDialog_clicked();
    void on_cancelButton_setPasswordDialog_clicked();

private:
    Ui::SetPasswordDialog *ui;
    QString passwordHash;
};

#endif // SETPASSWORDDIALOG_H
