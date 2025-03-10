#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
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

void NewNote::on_saveButton_clicked() {
    accept();
}

void NewNote::on_cancelButton_clicked() {
    reject();
}
