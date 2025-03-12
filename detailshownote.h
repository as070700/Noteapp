#ifndef DETAILSHOWNOTE_H
#define DETAILSHOWNOTE_H

#include <QDialog>

namespace Ui {
class detailshownote;
}

class detailshownote : public QDialog
{
    Q_OBJECT

public:
    explicit detailshownote(QWidget *parent = nullptr);
    ~detailshownote();

    void setNoteContent(const QString &title, const QString &content); // Methode zum Setzen des Inhalts
    void on_pushButtons_back_clicked();

private:
    Ui::detailshownote *ui;
};

#endif // DETAILSHOWNOTE_H
