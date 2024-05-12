/********************************************************************************
** Form generated from reading UI file 'cheater.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHEATER_H
#define UI_CHEATER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_cheater
{
public:
    QLabel *label;

    void setupUi(QWidget *cheater)
    {
        if (cheater->objectName().isEmpty())
            cheater->setObjectName(QString::fromUtf8("cheater"));
        cheater->resize(392, 66);
        label = new QLabel(cheater);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 391, 71));
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("image: url(:/photo/yourtrap.png);"));

        retranslateUi(cheater);

        QMetaObject::connectSlotsByName(cheater);
    } // setupUi

    void retranslateUi(QWidget *cheater)
    {
        cheater->setWindowTitle(QCoreApplication::translate("cheater", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class cheater: public Ui_cheater {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHEATER_H
