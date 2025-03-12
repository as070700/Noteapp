// shownote.h
#ifndef SHOWNOTE_H
#define SHOWNOTE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class shownote;
}

class shownote : public QWidget
{
    Q_OBJECT

public:
    explicit shownote(QWidget *parent = nullptr);
    ~shownote();

private slots:
    void showNoteContent(QListWidgetItem *item);
    void on_pushButtons_back_clicked(); // Hinzugefügt für Navigation zur MainWindow
    void on_pushButton_open_clicked(); // Hinzugefügt für Öffnen des detailshownote Dialogs

private:
    Ui::shownote *ui;
};

#endif // SHOWNOTE_H
