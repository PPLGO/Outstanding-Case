#include "reverse.h"
#include "ui_reverse.h"

reverse::reverse(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::reverse)
{
    ui->setupUi(this);
    this->setWindowTitle("隐藏成就");
}

reverse::~reverse()
{
    delete ui;
}
