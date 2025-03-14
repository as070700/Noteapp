#include "detaileditnote.h"
#include "ui_detaileditnote.h"

detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);

    connect(ui->pushButton_back, &QPushButton::clicked, this, &QDialog::reject);
}

detaileditnote::~detaileditnote()
{
    delete ui;
}

void detaileditnote::setNoteContent_edit(const QString &title, const QString &content) {
    ui->textEdit_title->setText(title);
    ui->textEdit_content->setText(content);
}
