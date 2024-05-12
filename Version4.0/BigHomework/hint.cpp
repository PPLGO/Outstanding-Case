#include "hint.h"
#include "ui_hint.h"

hint::hint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hint)
{
    ui->setupUi(this);
    this->setWindowTitle("提示");
}

hint::~hint()
{
    delete ui;
}
