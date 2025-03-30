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

    void setNoteContent_show(const QString &title, const QString &content);
    void loadNoteContent_detailshownote(const QString &noteTitle, const QString &noteContent);

private:
    Ui::detailShownote *ui;
    bool isNotePasswordProtected_detailshownote(const QString &noteTitle);
};

#endif // DETAILSHOWNOTE_H
