#include "menu.h"
#include "widget.h"
#include "ui_menu.h"

menu::menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::menu)
{
    ui->setupUi(this);
    this->setWindowTitle("纳西妲巧破纳斯利亚堡的悬案");

    // connect(ui->StartButton,&QPushButton::clicked,this,&menu::on_StartButton_clicked);
}

menu::~menu()
{
    delete ui;
}

void menu::on_StartButton_clicked()
{
    this->hide();
    w.show();
}


void menu::on_Rule_clicked()
{
    gamerule.show();
}

