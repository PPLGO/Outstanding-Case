#ifndef HINT_H
#define HINT_H

#include <QWidget>

namespace Ui {
class hint;
}

class hint : public QWidget
{
    Q_OBJECT

public:
    explicit hint(QWidget *parent = nullptr);
    ~hint();

private:
    Ui::hint *ui;
};

#endif // HINT_H
