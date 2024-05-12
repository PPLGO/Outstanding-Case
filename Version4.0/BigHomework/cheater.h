#ifndef CHEATER_H
#define CHEATER_H

#include <QWidget>

namespace Ui {
class cheater;
}

class cheater : public QWidget
{
    Q_OBJECT

public:
    explicit cheater(QWidget *parent = nullptr);
    ~cheater();

private:
    Ui::cheater *ui;
};

#endif // CHEATER_H
