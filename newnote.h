#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QDialog>
#include <QTextCharFormat>
#include <QColorDialog>

namespace Ui {
class NewNote;
}

class NewNote : public QDialog
{
    Q_OBJECT

public:
    explicit NewNote(QWidget *parent = nullptr);
    ~NewNote();

    QString getTitle_newnote() const;
    QString getContent_newnote() const;
    void saveNote_newnote();

private slots:
    void saveNote_password_NewNote();
    void setBold_newnote();
    void setItalic_newnote();
    void setUnderline_newnote();
    void setColor_newnote();
    void setFontSize_newnote(int index);

private:
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
    Ui::NewNote *ui;
};

#endif // NEWNOTE_H
