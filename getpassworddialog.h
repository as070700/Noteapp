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

private:
    Ui::getPasswordDialog *ui;
};

#endif // GETPASSWORDDIALOG_H
