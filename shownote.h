#ifndef SHOWNOTE_H
#define SHOWNOTE_H

#include <QWidget>

namespace Ui {
class shownote;
}

class shownote : public QWidget
{
    Q_OBJECT

public:
    explicit shownote(QWidget *parent = nullptr);
    ~shownote();

private:
    Ui::shownote *ui;
};

#endif // SHOWNOTE_H
