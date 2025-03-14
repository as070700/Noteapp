#ifndef DETAILEDITNOTE_H
#define DETAILEDITNOTE_H

#include <QDialog>

namespace Ui {
class detaileditnote;
}

class detaileditnote : public QDialog
{
    Q_OBJECT

public:
    explicit detaileditnote(QWidget *parent = nullptr);
    ~detaileditnote();

    void setNoteContent_edit(const QString &title, const QString &content);

private:
    Ui::detaileditnote *ui;
};

#endif // DETAILEDITNOTE_H
