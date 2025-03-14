#ifndef DELETENOTE_H
#define DELETENOTE_H

#include <QWidget>

namespace Ui {
class deletenote;
}

class deletenote : public QWidget
{
    Q_OBJECT

public:
    explicit deletenote(QWidget *parent = nullptr);
    ~deletenote();

private:
    Ui::deletenote *ui;
};

#endif // DELETENOTE_H
