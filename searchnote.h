#ifndef SEARCHNOTE_H
#define SEARCHNOTE_H

#include <QWidget>

namespace Ui {
class searchnote;
}

class searchnote : public QWidget
{
    Q_OBJECT

public:
    explicit searchnote(QWidget *parent = nullptr);
    ~searchnote();

private slots:
    void on_searchButton_clicked();

private:
    Ui::searchnote *ui;
    void searchNotes(const QString &query);
};

#endif // SEARCHNOTE_H
