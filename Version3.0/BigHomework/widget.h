#ifndef WIDGET_H
#define WIDGET_H

#include <QDir>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QPixmap>
#include <QMessageBox>
#include <QMediaPlayer>
#include <QAudioOutput>
#include "hint.h"
#include "reverse.h"
#include "cheater.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    hint ht;
    reverse rev;
    cheater che;
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void DisplayLocation();
    void DisplayMinion();
    void DisplayButton();

private:

    QString LocationText[20],MinionText[20];
    int locations[20],minionID[10],minions[40];
    //locations : 地标text ID;minions：随从text ID;ID[i]:当前随从[i]的ID
    bool LocationVis[20],MinionVis[40];
    //地标[i%10]能否被看见; MinionVis[i]:ID[i%10]的随从词条[i]能否被看见
    int LastClicked,CheckposCnt,ReleaseCnt,hp,firstcheat;

    QMediaPlayer MusicPlayer;

private slots:

    void on_Minion0_clicked();

    void on_Minion1_clicked();

    void on_Minion2_clicked();

    void on_Minion3_clicked();

    void on_Minion4_clicked();

    void on_Minion5_clicked();

    void on_Minion6_clicked();

    void on_Minion7_clicked();

    void on_Minion8_clicked();

    void on_Minion9_clicked();

    void on_Location0_clicked();

    void on_Location1_clicked();

    void on_Location2_clicked();

    void on_Location3_clicked();

    void on_Location4_clicked();

    void on_Location5_clicked();

    void on_Location6_clicked();

    void on_Location7_clicked();

    void on_Location8_clicked();

    void on_Location9_clicked();

    void on_CheckMate_clicked();

    void on_Release_clicked();

    void on_Checkpos_clicked();

    void on_Hint_clicked();

    void on_HP_returnPressed();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
