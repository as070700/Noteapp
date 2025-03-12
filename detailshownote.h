#ifndef DETAILSHOWNOTE_H
#define DETAILSHOWNOTE_H

#include <QDialog>

namespace Ui {
class detailShownote;
}

class detailShownote : public QDialog
{
    Q_OBJECT

public:
    explicit detailShownote(QWidget *parent = nullptr);
    ~detailShownote();

    void setNoteContent(const QString &title, const QString &content);

private:
    Ui::detailShownote *ui;
};

#endif // DETAILSHOWNOTE_H
