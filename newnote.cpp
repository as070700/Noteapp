#include "newnote.h"
#include "ui_newnote.h"

NewNote::NewNote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NewNote)
{
    ui->setupUi(this);
    connect(ui->saveButton_newnote, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->backButton_newnote, &QPushButton::clicked, this, &QDialog::reject);
}

NewNote::~NewNote() {
    delete ui;
}

QString NewNote::getTitle() const {
    return ui->title_lineEdit_newnote->text();
}

QString NewNote::getContent() const {
    return ui->content_lineEdit_newnote->toPlainText();
}
