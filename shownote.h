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
    void on_backButton_shownote_clicked();
    void on_openButton_shownote_clicked();

private:
    Ui::shownote *ui;
};

#endif // SHOWNOTE_H
