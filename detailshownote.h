#ifndef DETAILSHOWNOTE_H
#define DETAILSHOWNOTE_H

#include <QWidget>

namespace Ui {
class detailShownote;
}

class detailShownote : public QWidget
{
    Q_OBJECT

public:
    explicit detailShownote(QWidget *parent = nullptr);
    ~detailShownote();

private:
    Ui::detailShownote *ui;
};

#endif // DETAILSHOWNOTE_H
