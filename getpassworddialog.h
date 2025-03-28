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
    explicit getPasswordDialog(QWidget *parent = nullptr);
    ~getPasswordDialog();

    QString getPassword_getpassworddialog() const;

signals:
    void passwordCorrect_getpassworddialog();
    void passwortIncorrect_getpassworddialog();

private slots:
    void on_okButton_getpassworddialog_clicked();
    void on_cancelButton_getpassworddialog_clicked();

private:
    Ui::getPasswordDialog *ui;
};

#endif // GETPASSWORDDIALOG_H
