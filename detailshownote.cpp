#include "detailshownote.h"
#include "detailshownote.h"

detailshownote::detailshownote(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::detailshownote)
{
    ui->setupUi(this);
}

detailshownote::~detailshownote()
{
    delete ui;
}

void detailshownote::setNoteContent(const QString &title, const QString &content) {
    ui->label_title->setText(title);
    ui->textBrowser_content->setText(content);
}

void detailshownote::on_pushButtons_back_clicked() {
    this->close(); // Schließt das aktuelle Fenster und kehrt zum Hauptfenster zurück
}
