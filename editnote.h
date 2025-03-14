#ifndef EDITNOTE_H
#define EDITNOTE_H

#include <QWidget>
#include <QListWidgetItem>

namespace Ui {
class editnote;
}

class editnote : public QWidget
{
    Q_OBJECT

public:
    explicit editnote(QWidget *parent = nullptr);
    ~editnote();

private slots:
    void on_backButton_editnote_clicked();
    void on_openButton_editnote_clicked();

private:
    Ui::editnote *ui;
};

#endif // EDITNOTE_H
