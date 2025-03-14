#ifndef NEWNOTE_H
#define NEWNOTE_H

#include <QDialog>
#include <QTextCharFormat>

namespace Ui {
class NewNote;
}

class NewNote : public QDialog {
    Q_OBJECT

public:
    explicit NewNote(QWidget *parent = nullptr);
    ~NewNote();

    QString getTitle_newnote() const;
    QString getContent_newnote() const;

private slots:
    void setBold_newnote();
    void setItalic_newnote();
    void setUnderline_newnote();
    void setColor_newnote();
    void setFontSize_newnote(int index);

private:
    Ui::NewNote *ui;
    void mergeFormatOnWordOrSelection(const QTextCharFormat &format);
};

#endif // NEWNOTE_H
