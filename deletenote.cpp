#include "deletenote.h"
#include "ui_deletenote.h"

deletenote::deletenote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::deletenote)
{
    ui->setupUi(this);
}

deletenote::~deletenote()
{
    delete ui;
}
