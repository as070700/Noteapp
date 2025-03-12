#include "detailshownote.h"
#include "ui_detailshownote.h"

detailShownote::detailShownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailShownote)
{
    ui->setupUi(this);

    connect(ui->pushButton_back, &QPushButton::clicked, this, &QDialog::reject);
}

detailShownote::~detailShownote()
{
    delete ui;
}

void detailShownote::setNoteContent(const QString &title, const QString &content) {
    ui->label_title->setText(title);
    ui->textBrowser_content->setText(content);
}

