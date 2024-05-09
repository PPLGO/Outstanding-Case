#include "rule.h"
#include "ui_rule.h"

rule::rule(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::rule)
{
    ui->setupUi(this);
    this->setWindowTitle("隐藏成就");
}

rule::~rule()
{
    delete ui;
}
