#ifndef SHOWNOTE_H
#define SHOWNOTE_H

#include <QWidget>
#include <QListWidgetItem>
#include <QLabel>
#include <QScrollArea>
#include <QPushButton>
#include <QListView>

namespace Ui {
class shownote;
}

class shownote : public QWidget
{
    Q_OBJECT

public:
    explicit shownote(QWidget *parent = nullptr);
    ~shownote();

    void loadNotePassword_shownote();

    // Getter-Methoden für die Buttons
    QLabel* getLabelShownote() const;
    QScrollArea* getScrollAreaShownote() const;
    QWidget* getScrollAreaWidgetContentsShownote() const;
    QListView* getListviewShownote() const;
    QPushButton* getOpenButtonShownote() const;
    QPushButton* getBackButtonShownote() const;
    QPushButton* getSearchButtonShownote() const;

private slots:
    void on_backButton_shownote_clicked();
    void on_openButton_shownote_clicked();
    void on_searchButton_shownote_clicked();

private:
    Ui::shownote *ui;
};

#endif // SHOWNOTE_H
