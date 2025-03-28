#ifndef SECURITYQUESTIONDIALOG_H
#define SECURITYQUESTIONDIALOG_H

#include <QDialog>

namespace Ui {
class SecurityQuestionDialog;
}

class SecurityQuestionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SecurityQuestionDialog(QWidget *parent = nullptr);
    ~SecurityQuestionDialog();

    QString getAnswer_securityquestiondialog() const;

signals:
    void answerCorrect_securityquestiondialog(); // Signal hinzufügen

private slots:
    void on_okButton_securityquestiondialog_clicked();
    void on_cancelButton_securityquestiondialog_clicked();

private:
    Ui::SecurityQuestionDialog *ui;
};

#endif // SECURITYQUESTIONDIALOG_H
