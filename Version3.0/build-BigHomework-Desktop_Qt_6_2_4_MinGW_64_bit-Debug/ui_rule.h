/********************************************************************************
** Form generated from reading UI file 'rule.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RULE_H
#define UI_RULE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rule
{
public:
    QLabel *label;

    void setupUi(QWidget *rule)
    {
        if (rule->objectName().isEmpty())
            rule->setObjectName(QString::fromUtf8("rule"));
        rule->resize(597, 88);
        label = new QLabel(rule);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 601, 91));
        label->setStyleSheet(QString::fromUtf8("image: url(:/photo/GameR.png);\n"
"image: url(:/photo/cheated.png);"));

        retranslateUi(rule);

        QMetaObject::connectSlotsByName(rule);
    } // setupUi

    void retranslateUi(QWidget *rule)
    {
        rule->setWindowTitle(QCoreApplication::translate("rule", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class rule: public Ui_rule {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RULE_H
