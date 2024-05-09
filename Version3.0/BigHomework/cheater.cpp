#include "cheater.h"
#include "ui_cheater.h"

cheater::cheater(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::cheater)
{
    ui->setupUi(this);
    this->setWindowTitle("隐藏成就");
}

cheater::~cheater()
{
    delete ui;
}
