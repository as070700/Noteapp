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
    explicit SecurityQuestionDialog(QWidget *parent = nullptr); // Konstruktor
    ~SecurityQuestionDialog(); // Destruktor

    QString getAnswer_securityquestiondialog() const; // Gibt die eingegebene Antwort zurück

signals:
    void answerCorrect_securityquestiondialog(); // Signal, das bei korrekter Antwort ausgelöst wird

private slots:
    void on_okButton_securityquestiondialog_clicked(); // Slot für den OK-Button
    void on_cancelButton_securityquestiondialog_clicked(); // Slot für den Abbrechen-Button

private:
    Ui::SecurityQuestionDialog *ui; // Benutzeroberfläche
};

#endif // SECURITYQUESTIONDIALOG_H
