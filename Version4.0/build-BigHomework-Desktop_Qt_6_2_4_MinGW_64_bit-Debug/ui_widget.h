/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QPushButton *CheckMate;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *Location0;
    QPushButton *Location1;
    QPushButton *Location2;
    QPushButton *Location3;
    QPushButton *Location4;
    QPushButton *Location5;
    QPushButton *Location6;
    QPushButton *Location7;
    QPushButton *Location8;
    QPushButton *Location9;
    QPushButton *Checkpos;
    QPushButton *Detect;
    QPushButton *Hint;
    QLabel *label;
    QLineEdit *HP;
    QLabel *Background;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *Minion0;
    QPushButton *Minion1;
    QPushButton *Minion2;
    QPushButton *Minion3;
    QPushButton *Minion4;
    QPushButton *Minion5;
    QPushButton *Minion6;
    QPushButton *Minion7;
    QPushButton *Minion8;
    QPushButton *Minion9;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Mark0;
    QPushButton *Mark1;
    QPushButton *Mark2;
    QPushButton *Mark3;
    QPushButton *Mark4;
    QPushButton *Mark5;
    QPushButton *Mark6;
    QPushButton *Mark7;
    QPushButton *Mark8;
    QPushButton *Mark9;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(896, 600);
        CheckMate = new QPushButton(Widget);
        CheckMate->setObjectName(QString::fromUtf8("CheckMate"));
        CheckMate->setGeometry(QRect(820, 190, 80, 24));
        layoutWidget = new QWidget(Widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 100, 856, 82));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Location0 = new QPushButton(layoutWidget);
        Location0->setObjectName(QString::fromUtf8("Location0"));
        Location0->setMinimumSize(QSize(80, 80));
        Location0->setMaximumSize(QSize(80, 80));
        Location0->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location0);

        Location1 = new QPushButton(layoutWidget);
        Location1->setObjectName(QString::fromUtf8("Location1"));
        Location1->setMinimumSize(QSize(80, 80));
        Location1->setMaximumSize(QSize(80, 80));
        Location1->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location1);

        Location2 = new QPushButton(layoutWidget);
        Location2->setObjectName(QString::fromUtf8("Location2"));
        Location2->setMinimumSize(QSize(80, 80));
        Location2->setMaximumSize(QSize(80, 80));
        Location2->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location2);

        Location3 = new QPushButton(layoutWidget);
        Location3->setObjectName(QString::fromUtf8("Location3"));
        Location3->setMinimumSize(QSize(80, 80));
        Location3->setMaximumSize(QSize(80, 80));
        Location3->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location3);

        Location4 = new QPushButton(layoutWidget);
        Location4->setObjectName(QString::fromUtf8("Location4"));
        Location4->setMinimumSize(QSize(80, 80));
        Location4->setMaximumSize(QSize(80, 80));
        Location4->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location4);

        Location5 = new QPushButton(layoutWidget);
        Location5->setObjectName(QString::fromUtf8("Location5"));
        Location5->setMinimumSize(QSize(80, 80));
        Location5->setMaximumSize(QSize(80, 80));
        Location5->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location5);

        Location6 = new QPushButton(layoutWidget);
        Location6->setObjectName(QString::fromUtf8("Location6"));
        Location6->setMinimumSize(QSize(80, 80));
        Location6->setMaximumSize(QSize(80, 80));
        Location6->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location6);

        Location7 = new QPushButton(layoutWidget);
        Location7->setObjectName(QString::fromUtf8("Location7"));
        Location7->setMinimumSize(QSize(80, 80));
        Location7->setMaximumSize(QSize(80, 80));
        Location7->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location7);

        Location8 = new QPushButton(layoutWidget);
        Location8->setObjectName(QString::fromUtf8("Location8"));
        Location8->setMinimumSize(QSize(80, 80));
        Location8->setMaximumSize(QSize(80, 80));
        Location8->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location8);

        Location9 = new QPushButton(layoutWidget);
        Location9->setObjectName(QString::fromUtf8("Location9"));
        Location9->setMinimumSize(QSize(80, 80));
        Location9->setMaximumSize(QSize(80, 80));
        Location9->setIconSize(QSize(40, 40));

        horizontalLayout_3->addWidget(Location9);

        Checkpos = new QPushButton(Widget);
        Checkpos->setObjectName(QString::fromUtf8("Checkpos"));
        Checkpos->setGeometry(QRect(240, 380, 70, 70));
        Detect = new QPushButton(Widget);
        Detect->setObjectName(QString::fromUtf8("Detect"));
        Detect->setGeometry(QRect(530, 380, 70, 70));
        Hint = new QPushButton(Widget);
        Hint->setObjectName(QString::fromUtf8("Hint"));
        Hint->setGeometry(QRect(60, 400, 80, 24));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 360, 161, 201));
        label->setStyleSheet(QString::fromUtf8("image: url(:/Nahida3.jpg);\n"
"image: url(:/photo/Nahida3.jpg);"));
        HP = new QLineEdit(Widget);
        HP->setObjectName(QString::fromUtf8("HP"));
        HP->setGeometry(QRect(480, 540, 31, 31));
        Background = new QLabel(Widget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(-7, -5, 911, 611));
        Background->setStyleSheet(QString::fromUtf8("border-image: url(:/photo/Castle1.png);"));
        verticalLayoutWidget = new QWidget(Widget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(20, 220, 861, 122));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Minion0 = new QPushButton(verticalLayoutWidget);
        Minion0->setObjectName(QString::fromUtf8("Minion0"));
        Minion0->setMinimumSize(QSize(80, 80));
        Minion0->setMaximumSize(QSize(80, 80));
        Minion0->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion0);

        Minion1 = new QPushButton(verticalLayoutWidget);
        Minion1->setObjectName(QString::fromUtf8("Minion1"));
        Minion1->setMinimumSize(QSize(80, 80));
        Minion1->setMaximumSize(QSize(80, 80));
        Minion1->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion1);

        Minion2 = new QPushButton(verticalLayoutWidget);
        Minion2->setObjectName(QString::fromUtf8("Minion2"));
        Minion2->setMinimumSize(QSize(80, 80));
        Minion2->setMaximumSize(QSize(80, 80));
        Minion2->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion2);

        Minion3 = new QPushButton(verticalLayoutWidget);
        Minion3->setObjectName(QString::fromUtf8("Minion3"));
        Minion3->setMinimumSize(QSize(80, 80));
        Minion3->setMaximumSize(QSize(80, 80));
        Minion3->setStyleSheet(QString::fromUtf8(""));
        Minion3->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion3);

        Minion4 = new QPushButton(verticalLayoutWidget);
        Minion4->setObjectName(QString::fromUtf8("Minion4"));
        Minion4->setMinimumSize(QSize(80, 80));
        Minion4->setMaximumSize(QSize(80, 80));
        Minion4->setStyleSheet(QString::fromUtf8(""));
        Minion4->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion4);

        Minion5 = new QPushButton(verticalLayoutWidget);
        Minion5->setObjectName(QString::fromUtf8("Minion5"));
        Minion5->setMinimumSize(QSize(80, 80));
        Minion5->setMaximumSize(QSize(80, 80));
        Minion5->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion5);

        Minion6 = new QPushButton(verticalLayoutWidget);
        Minion6->setObjectName(QString::fromUtf8("Minion6"));
        Minion6->setMinimumSize(QSize(80, 80));
        Minion6->setMaximumSize(QSize(80, 80));
        Minion6->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion6);

        Minion7 = new QPushButton(verticalLayoutWidget);
        Minion7->setObjectName(QString::fromUtf8("Minion7"));
        Minion7->setMinimumSize(QSize(80, 80));
        Minion7->setMaximumSize(QSize(80, 80));
        Minion7->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion7);

        Minion8 = new QPushButton(verticalLayoutWidget);
        Minion8->setObjectName(QString::fromUtf8("Minion8"));
        Minion8->setMinimumSize(QSize(80, 80));
        Minion8->setMaximumSize(QSize(80, 80));
        Minion8->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion8);

        Minion9 = new QPushButton(verticalLayoutWidget);
        Minion9->setObjectName(QString::fromUtf8("Minion9"));
        Minion9->setMinimumSize(QSize(80, 80));
        Minion9->setMaximumSize(QSize(80, 80));
        Minion9->setIconSize(QSize(40, 40));

        horizontalLayout->addWidget(Minion9);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(30);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        Mark0 = new QPushButton(verticalLayoutWidget);
        Mark0->setObjectName(QString::fromUtf8("Mark0"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Mark0->sizePolicy().hasHeightForWidth());
        Mark0->setSizePolicy(sizePolicy);
        Mark0->setMinimumSize(QSize(30, 30));
        Mark0->setMaximumSize(QSize(30, 30));
        Mark0->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark0);

        Mark1 = new QPushButton(verticalLayoutWidget);
        Mark1->setObjectName(QString::fromUtf8("Mark1"));
        Mark1->setMinimumSize(QSize(30, 30));
        Mark1->setMaximumSize(QSize(30, 30));
        Mark1->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark1);

        Mark2 = new QPushButton(verticalLayoutWidget);
        Mark2->setObjectName(QString::fromUtf8("Mark2"));
        Mark2->setMinimumSize(QSize(30, 30));
        Mark2->setMaximumSize(QSize(30, 30));
        Mark2->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark2);

        Mark3 = new QPushButton(verticalLayoutWidget);
        Mark3->setObjectName(QString::fromUtf8("Mark3"));
        Mark3->setMinimumSize(QSize(30, 30));
        Mark3->setMaximumSize(QSize(30, 30));
        Mark3->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark3);

        Mark4 = new QPushButton(verticalLayoutWidget);
        Mark4->setObjectName(QString::fromUtf8("Mark4"));
        Mark4->setMinimumSize(QSize(30, 30));
        Mark4->setMaximumSize(QSize(30, 30));
        Mark4->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark4);

        Mark5 = new QPushButton(verticalLayoutWidget);
        Mark5->setObjectName(QString::fromUtf8("Mark5"));
        Mark5->setMinimumSize(QSize(30, 30));
        Mark5->setMaximumSize(QSize(30, 30));
        Mark5->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark5);

        Mark6 = new QPushButton(verticalLayoutWidget);
        Mark6->setObjectName(QString::fromUtf8("Mark6"));
        Mark6->setMinimumSize(QSize(30, 30));
        Mark6->setMaximumSize(QSize(30, 30));
        Mark6->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark6);

        Mark7 = new QPushButton(verticalLayoutWidget);
        Mark7->setObjectName(QString::fromUtf8("Mark7"));
        Mark7->setMinimumSize(QSize(30, 30));
        Mark7->setMaximumSize(QSize(30, 30));
        Mark7->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark7);

        Mark8 = new QPushButton(verticalLayoutWidget);
        Mark8->setObjectName(QString::fromUtf8("Mark8"));
        Mark8->setMinimumSize(QSize(30, 30));
        Mark8->setMaximumSize(QSize(30, 30));
        Mark8->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark8);

        Mark9 = new QPushButton(verticalLayoutWidget);
        Mark9->setObjectName(QString::fromUtf8("Mark9"));
        Mark9->setMinimumSize(QSize(30, 30));
        Mark9->setMaximumSize(QSize(30, 30));
        Mark9->setIconSize(QSize(25, 25));

        horizontalLayout_2->addWidget(Mark9);


        verticalLayout->addLayout(horizontalLayout_2);

        Background->raise();
        CheckMate->raise();
        layoutWidget->raise();
        Checkpos->raise();
        Detect->raise();
        Hint->raise();
        label->raise();
        HP->raise();
        verticalLayoutWidget->raise();

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        CheckMate->setText(QCoreApplication::translate("Widget", "CheckMate", nullptr));
        Location0->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location1->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Location9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Checkpos->setText(QCoreApplication::translate("Widget", "Checkpos", nullptr));
        Detect->setText(QCoreApplication::translate("Widget", "Detect", nullptr));
        Hint->setText(QCoreApplication::translate("Widget", "Hint", nullptr));
        label->setText(QString());
        Background->setText(QString());
        Minion0->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion1->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion2->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion3->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion4->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion5->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion6->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion7->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion8->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Minion9->setText(QCoreApplication::translate("Widget", "PushButton", nullptr));
        Mark0->setText(QString());
        Mark1->setText(QString());
        Mark2->setText(QString());
        Mark3->setText(QString());
        Mark4->setText(QString());
        Mark5->setText(QString());
        Mark6->setText(QString());
        Mark7->setText(QString());
        Mark8->setText(QString());
        Mark9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
