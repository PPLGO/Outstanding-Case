/********************************************************************************
** Form generated from reading UI file 'checkmate.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKMATE_H
#define UI_CHECKMATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckMate
{
public:

    void setupUi(QWidget *CheckMate)
    {
        if (CheckMate->objectName().isEmpty())
            CheckMate->setObjectName(QString::fromUtf8("CheckMate"));
        CheckMate->resize(883, 509);

        retranslateUi(CheckMate);

        QMetaObject::connectSlotsByName(CheckMate);
    } // setupUi

    void retranslateUi(QWidget *CheckMate)
    {
        CheckMate->setWindowTitle(QCoreApplication::translate("CheckMate", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckMate: public Ui_CheckMate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKMATE_H
