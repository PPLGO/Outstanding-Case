/********************************************************************************
** Form generated from reading UI file 'reverse.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REVERSE_H
#define UI_REVERSE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_reverse
{
public:
    QLabel *label;

    void setupUi(QWidget *reverse)
    {
        if (reverse->objectName().isEmpty())
            reverse->setObjectName(QString::fromUtf8("reverse"));
        reverse->resize(251, 30);
        label = new QLabel(reverse);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 251, 31));
        label->setStyleSheet(QString::fromUtf8("image: url(:/photo/reverse.png);"));

        retranslateUi(reverse);

        QMetaObject::connectSlotsByName(reverse);
    } // setupUi

    void retranslateUi(QWidget *reverse)
    {
        reverse->setWindowTitle(QCoreApplication::translate("reverse", "Form", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class reverse: public Ui_reverse {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REVERSE_H
