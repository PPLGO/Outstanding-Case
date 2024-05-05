#include "hint.h"
#include "ui_hint.h"

hint::hint(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::hint)
{
    ui->setupUi(this);
    this->setWindowTitle("纳西妲巧破纳斯利亚堡的悬案");
}

hint::~hint()
{
    delete ui;
}
