#include "shownote.h"
#include "ui_shownote.h"

shownote::shownote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::shownote)
{
    ui->setupUi(this);
}

shownote::~shownote()
{
    delete ui;
}
