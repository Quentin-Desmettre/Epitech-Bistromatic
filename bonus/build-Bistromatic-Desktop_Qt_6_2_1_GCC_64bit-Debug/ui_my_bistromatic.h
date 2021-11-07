/********************************************************************************
** Form generated from reading UI file 'my_bistromatic.ui'
**
** Created by: Qt User Interface Compiler version 6.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MY_BISTROMATIC_H
#define UI_MY_BISTROMATIC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_my_bistromatic
{
public:

    void setupUi(QWidget *my_bistromatic)
    {
        if (my_bistromatic->objectName().isEmpty())
            my_bistromatic->setObjectName(QString::fromUtf8("my_bistromatic"));
        my_bistromatic->resize(400, 300);

        retranslateUi(my_bistromatic);

        QMetaObject::connectSlotsByName(my_bistromatic);
    } // setupUi

    void retranslateUi(QWidget *my_bistromatic)
    {
        my_bistromatic->setWindowTitle(QCoreApplication::translate("my_bistromatic", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class my_bistromatic: public Ui_my_bistromatic {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MY_BISTROMATIC_H
