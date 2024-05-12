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

    // this->setAutoFillBackground(true);
    // this->setStyleSheet("background-image: url(:/photo/Castle1.png);");

    // ui->Background->stackUnder(this);

    MusicPlayer.setAudioOutput(new QAudioOutput());
    MusicPlayer.setSource(QUrl::fromLocalFile("qrc:/video/NahidaE.mp3"));

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

    firstcheat = 1;
    LastClicked = -1;
    DetectCnt = 2;
    CheckposCnt = 1;
    hp = 10;
    ui->HP->setText(QString::number(hp));

    //mark
    for(int i = 0;i < 10;++ i) mark[i] = 0;
    con[0].addFile(":/photo/Blank.png");
    con[1].addFile(":/photo/Correct.png");
    con[2].addFile(":/photo/Wrong.png");
    con[3].addFile(":/photo/Unknown.png");

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
    shuffle(minionID,minionID+10,g);

    DisplayLocation();
    DisplayMinion();
    DisplayButton();
    DisplayMark();
    ClearColor();

}

Widget::~Widget()
{
    delete ui;
}

void Widget::DisplayButton()
{
    ui->Detect->setText("Detect\n"+QString::number(DetectCnt));
    ui->Checkpos->setText("Checkpos\n"+QString::number(CheckposCnt));
}

void Widget::DisplayLocation()
{
    QString tmp;
    tmp = QString::number(0) + "\n" + LocationText[locations[0]] + "\n";
    if(LocationVis[10]) tmp += LocationText[locations[10]];
    else tmp += "???";
    ui->Location0->setText(tmp);

    tmp = QString::number(1) + "\n" + LocationText[locations[1]] + "\n";
    if(LocationVis[11]) tmp += LocationText[locations[11]];
    else tmp += "???";
    ui->Location1->setText(tmp);

    tmp = QString::number(2) + "\n" + LocationText[locations[2]] + "\n";
    if(LocationVis[12]) tmp += LocationText[locations[12]];
    else tmp += "???";
    ui->Location2->setText(tmp);

    tmp = QString::number(3) + "\n" + LocationText[locations[3]] + "\n";
    if(LocationVis[13]) tmp += LocationText[locations[13]];
    else tmp += "???";
    ui->Location3->setText(tmp);

    tmp = QString::number(4) + "\n" + LocationText[locations[4]] + "\n";
    if(LocationVis[14]) tmp += LocationText[locations[14]];
    else tmp += "???";
    ui->Location4->setText(tmp);

    tmp = QString::number(5) + "\n" + LocationText[locations[5]] + "\n";
    if(LocationVis[15]) tmp += LocationText[locations[15]];
    else tmp += "???";
    ui->Location5->setText(tmp);

    tmp = QString::number(6) + "\n" + LocationText[locations[6]] + "\n";
    if(LocationVis[16]) tmp += LocationText[locations[16]];
    else tmp += "???";
    ui->Location6->setText(tmp);

    tmp = QString::number(7) + "\n" + LocationText[locations[7]] + "\n";
    if(LocationVis[17]) tmp += LocationText[locations[17]];
    else tmp += "???";
    ui->Location7->setText(tmp);

    tmp = QString::number(8) + "\n" + LocationText[locations[8]] + "\n";
    if(LocationVis[18]) tmp += LocationText[locations[18]];
    else tmp += "???";
    ui->Location8->setText(tmp);

    tmp = QString::number(9) + "\n" + LocationText[locations[9]] + "\n";
    if(LocationVis[19]) tmp += LocationText[locations[19]];
    else tmp += "???";
    ui->Location9->setText(tmp);
}

void Widget::DisplayMinion()
{
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

void Widget::ClearColor()
{
    ui->Minion0->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion1->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion2->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion3->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion4->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion5->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion6->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion7->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion8->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
    ui->Minion9->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); }");
}

void Widget::DisplayMark()
{
    ui->Mark0->setIcon(con[mark[0]]);
    ui->Mark1->setIcon(con[mark[1]]);
    ui->Mark2->setIcon(con[mark[2]]);
    ui->Mark3->setIcon(con[mark[3]]);
    ui->Mark4->setIcon(con[mark[4]]);
    ui->Mark5->setIcon(con[mark[5]]);
    ui->Mark6->setIcon(con[mark[6]]);
    ui->Mark7->setIcon(con[mark[7]]);
    ui->Mark8->setIcon(con[mark[8]]);
    ui->Mark9->setIcon(con[mark[9]]);
}

void Widget::on_Minion0_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[0] == 0){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[0]+20]) MinionVis[minionID[0]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[0]+30]) MinionVis[minionID[0]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 0;
        ui->Minion0->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[0]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion1_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[1] == 1){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[1]+20]) MinionVis[minionID[1]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[1]+30]) MinionVis[minionID[1]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 1;
        ui->Minion1->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[1]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion2_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[2] == 2){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[2]+20]) MinionVis[minionID[2]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[2]+30]) MinionVis[minionID[2]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 2;
        ui->Minion2->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[2]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion3_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[3] == 3){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[3]+20]) MinionVis[minionID[3]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[3]+30]) MinionVis[minionID[3]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 3;
        ui->Minion3->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[3]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion4_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[4] == 4){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[4]+20]) MinionVis[minionID[4]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[4]+30]) MinionVis[minionID[4]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 4;
        ui->Minion4->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[4]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion5_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[5] == 5){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[5]+20]) MinionVis[minionID[5]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[5]+30]) MinionVis[minionID[5]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 5;
        ui->Minion5->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[5]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion6_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[6] == 6){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[6]+20]) MinionVis[minionID[6]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[6]+30]) MinionVis[minionID[6]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 6;
        ui->Minion6->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[6]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion7_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[7] == 7){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[7]+20]) MinionVis[minionID[7]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[7]+30]) MinionVis[minionID[7]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 7;
        ui->Minion7->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[7]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion8_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[8] == 8){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[8]+20]) MinionVis[minionID[8]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[8]+30]) MinionVis[minionID[8]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 8;
        ui->Minion8->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[8]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Minion9_clicked()
{
    if(LastClicked == -3){//Checkpos
        if(minionID[9] == 9){
            QMessageBox::information(this, "提示", "位置正确");
        }
        else{
            QMessageBox::information(this, "提示", "位置错误");
        }
        --CheckposCnt;
        DisplayButton();
        LastClicked = -1;
    }
    else if(LastClicked == -2){//Detect
        if(!MinionVis[minionID[9]+20]) MinionVis[minionID[9]+20] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        else if(!MinionVis[minionID[9]+30]) MinionVis[minionID[9]+30] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayButton();
        DisplayMinion();
    }
    else if(LastClicked == -1) {
        LastClicked = 9;
        ui->Minion9->setStyleSheet("QPushButton { background-color: rgb(185, 224, 158); }");
        return;
    }
    else if(LastClicked >= 0 && LastClicked < 10){
        swap(minionID[LastClicked],minionID[9]);
        DisplayMinion();
        LastClicked = -1;
        ClearColor();
    }
}


void Widget::on_Location0_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[10]) LocationVis[10] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location1_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[11]) LocationVis[11] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location2_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[12]) LocationVis[12] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location3_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[13]) LocationVis[13] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location4_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[14]) LocationVis[14] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location5_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[15]) LocationVis[15] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location6_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[16]) LocationVis[16] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location7_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[17]) LocationVis[17] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location8_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[18]) LocationVis[18] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_Location9_clicked()
{
    if(LastClicked == -2){//Detect
        if(!LocationVis[19]) LocationVis[19] = 1,--DetectCnt,LastClicked = -1,MusicPlayer.play();
        DisplayLocation();
        DisplayButton();
    }
}


void Widget::on_CheckMate_clicked()
{
    int cnt = 0;
    for(int i = 0;i < 10;++ i)
        if(minionID[i] == i) ++cnt;
    if(cnt == 10){
        this->close();
        if(hp > 1) QMessageBox::information(this, "纳西妲巧破纳斯利亚堡的悬案", "恭喜你成功侦破悬案！");
        else rev.show();
    }
    else if(hp > 1){
        DetectCnt = 2;
        CheckposCnt = 1;
        LastClicked = -1;
        --hp;
        ui->HP->setText(QString::number(hp));
        QMessageBox::information(this, "提示", "位置正确数:"+QString::number(cnt));
        DisplayButton();
    }
    else{
        this->close();
        QMessageBox::information(this, "纳西妲巧破纳斯利亚堡的悬案", "很可惜，你没有在规定时间内侦破悬案qwq");
    }
}


void Widget::on_Detect_clicked()
{
    LastClicked = -1; ClearColor();
    if(DetectCnt > 0) LastClicked = -2;
}


void Widget::on_Checkpos_clicked()
{
    LastClicked = -1; ClearColor();
    if(CheckposCnt > 0) LastClicked = -3;
}


void Widget::on_Hint_clicked()
{
    ht.show();
}


void Widget::on_HP_returnPressed()
{
    hp = ui->HP->text().toInt();
    if(firstcheat) che.show();
    firstcheat = 0;
}


void Widget::on_Mark0_clicked()
{
    int ID = 0;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark1_clicked()
{
    int ID = 1;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark2_clicked()
{
    int ID = 2;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark3_clicked()
{
    int ID = 3;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark4_clicked()
{
    int ID = 4;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark5_clicked()
{
    int ID = 5;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark6_clicked()
{
    int ID = 6;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark7_clicked()
{
    int ID = 7;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark8_clicked()
{
    int ID = 8;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}


void Widget::on_Mark9_clicked()
{
    int ID = 9;
    mark[ID] = (mark[ID] + 1) % 4;
    DisplayMark();
}

