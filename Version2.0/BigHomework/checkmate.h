#ifndef CHECKMATE_H
#define CHECKMATE_H

#include <QWidget>

namespace Ui {
class CheckMate;
}

class CheckMate : public QWidget
{
    Q_OBJECT

public:
    explicit CheckMate(QWidget *parent = nullptr);
    ~CheckMate();

private:
    Ui::CheckMate *ui;
};

#endif // CHECKMATE_H
