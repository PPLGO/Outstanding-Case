/********************************************************************************
** Form generated from reading UI file 'menu.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENU_H
#define UI_MENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_menu
{
public:
    QPushButton *StartButton;
    QPushButton *Rule;

    void setupUi(QWidget *menu)
    {
        if (menu->objectName().isEmpty())
            menu->setObjectName(QString::fromUtf8("menu"));
        menu->resize(896, 600);
        menu->setAutoFillBackground(true);
        menu->setStyleSheet(QString::fromUtf8("background-image: url(:/photo/Castle1.png);"));
        StartButton = new QPushButton(menu);
        StartButton->setObjectName(QString::fromUtf8("StartButton"));
        StartButton->setGeometry(QRect(360, 210, 80, 24));
        Rule = new QPushButton(menu);
        Rule->setObjectName(QString::fromUtf8("Rule"));
        Rule->setGeometry(QRect(360, 260, 80, 24));

        retranslateUi(menu);

        QMetaObject::connectSlotsByName(menu);
    } // setupUi

    void retranslateUi(QWidget *menu)
    {
        menu->setWindowTitle(QCoreApplication::translate("menu", "Form", nullptr));
        StartButton->setText(QCoreApplication::translate("menu", "\345\274\200\345\247\213\346\270\270\346\210\217", nullptr));
        Rule->setText(QCoreApplication::translate("menu", "\346\270\270\346\210\217\350\247\204\345\210\231", nullptr));
    } // retranslateUi

};

namespace Ui {
    class menu: public Ui_menu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENU_H
