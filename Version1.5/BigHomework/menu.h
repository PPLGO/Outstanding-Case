#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "Widget.h"

namespace Ui {
class menu;
}

class menu : public QWidget
{
    Q_OBJECT

public:
    Widget w;
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:

    void on_StartButton_clicked();

private:
    Ui::menu *ui;
};

#endif // MENU_H
