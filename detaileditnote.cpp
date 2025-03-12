#include "detaileditnote.h"
#include "ui_detaileditnote.h"

detaileditnote::detaileditnote(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::detaileditnote)
{
    ui->setupUi(this);
}

detaileditnote::~detaileditnote()
{
    delete ui;
}
