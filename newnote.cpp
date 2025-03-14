#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    connect(ui->pushButton_save, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->pushButton_back, &QPushButton::clicked, this, &QDialog::reject);
}

NewNote::~NewNote() {
    delete ui;
}

QString NewNote::getTitle() const {
    return ui->lineEdit_title->text();
}

QString NewNote::getContent() const {
    return ui->textEdit_content->toPlainText();
}
