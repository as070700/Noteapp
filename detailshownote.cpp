#include "detailshownote.h"
#include "ui_detailshownote.h"

detailShownote::detailShownote(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::detailShownote)
{
    ui->setupUi(this);
}

detailShownote::~detailShownote()
{
    delete ui;
}
