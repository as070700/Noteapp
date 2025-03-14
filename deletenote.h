#ifndef DELETENOTE_H
#define DELETENOTE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class deletenote;
}

class deletenote : public QWidget
{
    Q_OBJECT

public:
    explicit deletenote(QWidget *parent = nullptr);
    ~deletenote();

private slots:
    void on_deleteButton_deleteNote_clicked();
    void on_backButton_deleteNote_clicked();

private:
    Ui::deletenote *ui;
    void loadNotes();
};

#endif // DELETENOTE_H
