#ifndef DETAILEDITNOTE_H
#define DETAILEDITNOTE_H

#include <QDialog>
#include <QTextCharFormat>

namespace Ui {
class detaileditnote;
}

class detaileditnote : public QDialog
{
    Q_OBJECT

public:
    explicit detaileditnote(QWidget *parent = nullptr);
    ~detaileditnote();

    void setNoteContent_detaileditnote(const QString &title, const QString &content);

private slots:
    void saveNote_detaileditnote();
    void setBold_detaileditnote();
    void setItalic_detaileditnote();
    void setUnderline_detaileditnote();
    void setColor_detaileditnote();
    void setFontSize_detaileditnote(int index);

private:
    Ui::detaileditnote *ui;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
};

#endif // DETAILEDITNOTE_H
