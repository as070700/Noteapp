#include "detaileditnote.h"
#include "ui_detaileditnote.h"

detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);

    connect(ui->backButton_detaileditnote, &QPushButton::clicked, this, &QDialog::reject);
}

detaileditnote::~detaileditnote()
{
    delete ui;
}

void detaileditnote::setNoteContent_edit(const QString &title, const QString &content) {
    ui->title_textEdit_detaileditnote->setText(title);
    ui->content_textEdit_detaileditnote->setText(content);
}
