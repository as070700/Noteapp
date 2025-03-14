#include "detailshownote.h"
#include "ui_detailshownote.h"

detailShownote::detailShownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailShownote)
{
    ui->setupUi(this);

    connect(ui->backButton_detailshownote, &QPushButton::clicked, this, &QDialog::reject);
}

detailShownote::~detailShownote()
{
    delete ui;
}

void detailShownote::setNoteContent_show(const QString &title, const QString &content) {
    ui->label_title_detailshownote->setText(title);
    ui->label_content_detailshownote->setText(content);
}

