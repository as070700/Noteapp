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

    QString getPassword_getPasswordDialog() const;

signals:
    void passwordCorrect(); // Signal hinzufügen

private slots:
    void on_okButton_getpassworddialog_clicked(); // Slot deklarieren
    void on_cancelButton_getpassworddialog_clicked(); // Slot deklarieren

private:
    Ui::getPasswordDialog *ui;
};

#endif // GETPASSWORDDIALOG_H
