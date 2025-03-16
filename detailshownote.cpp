#include "detailshownote.h"
#include "ui_detailshownote.h"

detailShownote::detailShownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailShownote)
{
    ui->setupUi(this);

    connect(ui->backButton_detailshownote, &QPushButton::clicked, this, &QDialog::reject);

    // Set the background of content_textEdit_detailshownote to transparent
    ui->content_textEdit_detailshownote->setStyleSheet("background: transparent");
}

detailShownote::~detailShownote()
{
    delete ui;
}

void detailShownote::setNoteContent_show(const QString &title, const QString &content) {
    ui->label_title_detailshownote->setText(title);
    ui->content_textEdit_detailshownote->setHtml(content); // Load as HTML
}

