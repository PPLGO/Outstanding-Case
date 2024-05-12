/********************************************************************************
** Form generated from reading UI file 'hint.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HINT_H
#define UI_HINT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_hint
{
public:
    QLabel *label;

    void setupUi(QWidget *hint)
    {
        if (hint->objectName().isEmpty())
            hint->setObjectName(QString::fromUtf8("hint"));
        hint->resize(420, 268);
        label = new QLabel(hint);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-10, -10, 441, 291));
        label->setStyleSheet(QString::fromUtf8("image: url(:/photo/hintp.png);"));

        retranslateUi(hint);

        QMetaObject::connectSlotsByName(hint);
    } // setupUi

    void retranslateUi(QWidget *hint)
    {
        hint->setWindowTitle(QCoreApplication::translate("hint", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class hint: public Ui_hint {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HINT_H
