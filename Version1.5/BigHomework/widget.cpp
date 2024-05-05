#include "hint.h"
#include "widget.h"
#include "ui_widget.h"
#include <ctime>
#include <random>
#include <algorithm>
using namespace std;

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->setWindowTitle("纳西妲巧破纳斯利亚堡的悬案");
    /*
    connect(ui->Minion0,&QPushButton::clicked,this,&Widget::on_Minion0_clicked);
    connect(ui->Minion1,&QPushButton::clicked,this,&Widget::on_Minion1_clicked);
    connect(ui->Minion2,&QPushButton::clicked,this,&Widget::on_Minion2_clicked);
    connect(ui->Minion3,&QPushButton::clicked,this,&Widget::on_Minion3_clicked);
    connect(ui->Minion4,&QPushButton::clicked,this,&Widget::on_Minion4_clicked);
    connect(ui->Minion5,&QPushButton::clicked,this,&Widget::on_Minion5_clicked);
    connect(ui->Minion6,&QPushButton::clicked,this,&Widget::on_Minion6_clicked);
    connect(ui->Minion7,&QPushButton::clicked,this,&Widget::on_Minion7_clicked);
    connect(ui->Minion8,&QPushButton::clicked,this,&Widget::on_Minion8_clicked);
    connect(ui->Minion9,&QPushButton::clicked,this,&Widget::on_Minion9_clicked);

    connect(ui->Location0,&QPushButton::clicked,this,&Widget::on_Location0_clicked);
    connect(ui->Location1,&QPushButton::clicked,this,&Widget::on_Location1_clicked);
    connect(ui->Location2,&QPushButton::clicked,this,&Widget::on_Location2_clicked);
    connect(ui->Location3,&QPushButton::clicked,this,&Widget::on_Location3_clicked);
    connect(ui->Location4,&QPushButton::clicked,this,&Widget::on_Location4_clicked);
    connect(ui->Location5,&QPushButton::clicked,this,&Widget::on_Location5_clicked);
    connect(ui->Location6,&QPushButton::clicked,this,&Widget::on_Location6_clicked);
    connect(ui->Location7,&QPushButton::clicked,this,&Widget::on_Location7_clicked);
    connect(ui->Location8,&QPushButton::clicked,this,&Widget::on_Location8_clicked);
    connect(ui->Location9,&QPushButton::clicked,this,&Widget::on_Location9_clicked);

    connect(ui->CheckMate,&QPushButton::clicked,this,&Widget::on_CheckMate_clicked);
    */
    LocationText[0] = "地上的泥渍";
    LocationText[1] = "灰色的毛发";
    LocationText[2] = "爪子的痕迹";
    LocationText[3] = "麝香气味";
    LocationText[4] = "灼烧的痕迹";
    LocationText[5] = "墨水渍";
    LocationText[6] = "心能残渣";
    LocationText[7] = "用过的手帕";
    LocationText[8] = "艳俗的耳环";
    LocationText[9] = "羽毛";
    LocationText[10] = "木刨花";
    LocationText[11] = "碎布片";
    LocationText[12] = "蜡油滴";
    LocationText[13] = "碎屑";
    LocationText[14] = "失踪的花镜";
    LocationText[15] = "白色薄片";
    LocationText[16] = "糖纸";
    LocationText[17] = "小巧的花瓣";
    LocationText[18] = "辣酱液滴";
    LocationText[19] = "小号的手套";

    MinionText[0] = "沾泥的靴子";
    MinionText[1] = "灰白的毛发";
    MinionText[2] = "尖利的爪子";
    MinionText[3] = "浓烈的香水";
    MinionText[4] = "烧焦的衣物";
    MinionText[5] = "铭文爱好";
    MinionText[6] = "切到了手";
    MinionText[7] = "频繁吸嗅";
    MinionText[8] = "失踪的耳环";
    MinionText[9] = "宠物鸟";
    MinionText[10] = "切削小刀";
    MinionText[11] = "破损的披风";
    MinionText[12] = "带着蜡烛";
    MinionText[13] = "吃着饼干";
    MinionText[14] = "催人泪下小说";
    MinionText[15] = "干燥的皮肤";
    MinionText[16] = "手指上巧克力";
    MinionText[17] = "头发里的花";
    MinionText[18] = "喜爱辣味食物";
    MinionText[19] = "娇小的手掌";

    LastClicked = -1;
    ReleaseCnt = 2;
    CheckposCnt = 1;


    //visible or not

    for(int i = 0;i < 10;++ i) LocationVis[i] = 1;
    for(int i = 10;i < 20;++ i) LocationVis[i] = 0;
    for(int i = 0;i < 20;++ i) MinionVis[i] = 1;
    for(int i = 20;i < 40;++ i) MinionVis[i] = 0;

    //text_init

    for(int i = 0;i < 20;++ i) locations[i] = i;
    mt19937 g(time(0));
    shuffle(locations,locations+20,g);

    uniform_int_distribution<> distrib(0, 1);

     // for(int i = 0;i < 40;++ i)
     //     minions[i] = 0;

    for(int i = 0;i < 10;++ i){
        minions[i] = locations[i];
        minions[i+10] = locations[i+10];
        minions[i+20] = locations[(i+13)%20];
        minions[i+30] = locations[(i+16)%20];
        for(int j = 0;j < 4;++ j)
            for(int k = j+1;k < 4;++ k)
                if(distrib(g))
                    swap(minions[i+j*10],minions[i+k*10]);
    }

    for(int i = 0;i < 10;++ i) minionID[i] = i;

    DisplayLocation();
    DisplayMinion();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::DisplayLocation()
{
    QString tmp;
    tmp = LocationText[locations[0]] + "\n";
    if(LocationVis[10]) tmp += LocationText[locations[10]];
    else tmp += "???";
    ui->Location0->setText(tmp);

    tmp = LocationText[locations[1]] + "\n";
    if(LocationVis[11]) tmp += LocationText[locations[11]];
    else tmp += "???";
    ui->Location1->setText(tmp);

    tmp = LocationText[locations[2]] + "\n";
    if(LocationVis[12]) tmp += LocationText[locations[12]];
    else tmp += "???";
    ui->Location2->setText(tmp);

    tmp = LocationText[locations[3]] + "\n";
    if(LocationVis[13]) tmp += LocationText[locations[13]];
    else tmp += "???";
    ui->Location3->setText(tmp);

    tmp = LocationText[locations[4]] + "\n";
    if(LocationVis[14]) tmp += LocationText[locations[14]];
    else tmp += "???";
    ui->Location4->setText(tmp);

    tmp = LocationText[locations[5]] + "\n";
    if(LocationVis[15]) tmp += LocationText[locations[15]];
    else tmp += "???";
    ui->Location5->setText(tmp);

    tmp = LocationText[locations[6]] + "\n";
    if(LocationVis[16]) tmp += LocationText[locations[16]];
    else tmp += "???";
    ui->Location6->setText(tmp);

    tmp = LocationText[locations[7]] + "\n";
    if(LocationVis[17]) tmp += LocationText[locations[17]];
    else tmp += "???";
    ui->Location7->setText(tmp);

    tmp = LocationText[locations[8]] + "\n";
    if(LocationVis[18]) tmp += LocationText[locations[18]];
    else tmp += "???";
    ui->Location8->setText(tmp);

    tmp = LocationText[locations[9]] + "\n";
    if(LocationVis[19]) tmp += LocationText[locations[19]];
    else tmp += "???";
    ui->Location9->setText(tmp);
}

void Widget::DisplayMinion()
{
    //debug
    /*
    for(int i = 0;i < 10;++ i)
        if(minionID[i] < 0 || minionID[i] > 9)
            ui->Minion0->setText(QString::number(i)),
            ui->Minion1->setText(QString::number(minionID[i]));
    if(ClickedMinion >= 0) return;
    int cnt = 0;
    for(int i = 0;i < 10;++ i)
        for(int j = 0;j < 4;++ j)
            if(minions[minionID[i]+j*10] < 0 || minions[minionID[i]+j*10] > 19){
                ui->Minion0->setText(QString::number(minions[minionID[i]+j*10]));
                ui->Minion1->setText(QString::number(minionID[i]+j*10));
                ui->Minion2->setText(QString::number(i));
                ui->Minion3->setText(QString::number(locations[i]));
                ui->Minion4->setText(QString::number(minions[i]));
                ++cnt;
                // return ;
            }*/
    //end
    QString tmp;
    tmp = MinionText[minions[minionID[0]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[0]+i]) tmp += MinionText[minions[minionID[0]+i]];
        else tmp += "???";
    }
    ui->Minion0->setText(tmp);

    tmp = MinionText[minions[minionID[1]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[1]+i]) tmp += MinionText[minions[minionID[1]+i]];
        else tmp += "???";
    }
    ui->Minion1->setText(tmp);

    tmp = MinionText[minions[minionID[2]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[2]+i]) tmp += MinionText[minions[minionID[2]+i]];
        else tmp += "???";
    }
    ui->Minion2->setText(tmp);

    tmp = MinionText[minions[minionID[3]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[3]+i]) tmp += MinionText[minions[minionID[3]+i]];
        else tmp += "???";
    }
    ui->Minion3->setText(tmp);

    tmp = MinionText[minions[minionID[4]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[4]+i]) tmp += MinionText[minions[minionID[4]+i]];
        else tmp += "???";
    }
    ui->Minion4->setText(tmp);

    tmp = MinionText[minions[minionID[5]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[5]+i]) tmp += MinionText[minions[minionID[5]+i]];
        else tmp += "???";
    }
    ui->Minion5->setText(tmp);

    tmp = MinionText[minions[minionID[6]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[6]+i]) tmp += MinionText[minions[minionID[6]+i]];
        else tmp += "???";
    }
    ui->Minion6->setText(tmp);

    tmp = MinionText[minions[minionID[7]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[7]+i]) tmp += MinionText[minions[minionID[7]+i]];
        else tmp += "???";
    }
    ui->Minion7->setText(tmp);

    tmp = MinionText[minions[minionID[8]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[8]+i]) tmp += MinionText[minions[minionID[8]+i]];
        else tmp += "???";
    }
    ui->Minion8->setText(tmp);

    tmp = MinionText[minions[minionID[9]]];
    for(int i = 10;i < 40;i += 10){
        tmp += "\n";
        if(MinionVis[minionID[9]+i]) tmp += MinionText[minions[minionID[9]+i]];
        else tmp += "???";
    }
    ui->Minion9->setText(tmp);
}

void Widget::on_Minion0_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[0] == 0){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[0]+20]) MinionVis[minionID[0]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[0]+30]) MinionVis[minionID[0]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 0;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[0]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion1_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[1] == 1){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[1]+20]) MinionVis[minionID[1]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[1]+30]) MinionVis[minionID[1]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 1;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        //swap(minionID[LastClicked],minionID[1]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion2_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[2] == 2){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[2]+20]) MinionVis[minionID[2]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[2]+30]) MinionVis[minionID[2]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 2;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[2]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion3_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[3] == 3){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[3]+20]) MinionVis[minionID[3]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[3]+30]) MinionVis[minionID[3]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 3;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[3]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion4_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[4] == 4){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[4]+20]) MinionVis[minionID[4]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[4]+30]) MinionVis[minionID[4]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 4;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[4]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion5_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[5] == 5){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[5]+20]) MinionVis[minionID[5]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[5]+30]) MinionVis[minionID[5]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 5;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[5]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion6_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[6] == 6){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[6]+20]) MinionVis[minionID[6]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[6]+30]) MinionVis[minionID[6]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 6;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[6]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion7_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[7] == 7){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[7]+20]) MinionVis[minionID[7]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[7]+30]) MinionVis[minionID[7]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 7;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[7]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion8_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[8] == 8){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[8]+20]) MinionVis[minionID[8]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[8]+30]) MinionVis[minionID[8]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 8;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[8]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Minion9_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[9] == 9){
            QMessageBox::warning(this, "提示", "位置正确");
        }
        else{
            QMessageBox::warning(this, "提示", "位置错误");
        }
        --CheckposCnt;
        LastClicked = -1;
    }
    if(LastClicked == -2){//Release
        if(!MinionVis[minionID[9]+20]) MinionVis[minionID[9]+20] = 1,--ReleaseCnt,LastClicked = -1;
        else if(!MinionVis[minionID[9]+30]) MinionVis[minionID[9]+30] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayMinion();
    }
    if(LastClicked == -1) {LastClicked = 9;return;}
    if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[9]);
        DisplayMinion();
        LastClicked = -1;
    }
}


void Widget::on_Location0_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[10]) LocationVis[10] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location1_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[11]) LocationVis[11] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location2_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[12]) LocationVis[12] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location3_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[13]) LocationVis[13] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location4_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[14]) LocationVis[14] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location5_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[15]) LocationVis[15] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location6_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[16]) LocationVis[16] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location7_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[17]) LocationVis[17] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location8_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[18]) LocationVis[18] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_Location9_clicked()
{
    if(LastClicked == -2){//Release
        if(!LocationVis[19]) LocationVis[19] = 1,--ReleaseCnt,LastClicked = -1;
        DisplayLocation();
    }
}


void Widget::on_CheckMate_clicked()
{

}


void Widget::on_Release_clicked()
{
    if(ReleaseCnt > 0) LastClicked = -2;
}


void Widget::on_Checkpos_clicked()
{
    if(CheckposCnt > 0) LastClicked = -3;

}


void Widget::on_Hint_clicked()
{
    // ht.show();
}

