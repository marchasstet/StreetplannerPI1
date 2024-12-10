/********************************************************************************
** Form generated from reading UI file 'makestreet.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAKESTREET_H
#define UI_MAKESTREET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_MakeStreet
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QComboBox *comboBox_2;

    void setupUi(QDialog *MakeStreet)
    {
        if (MakeStreet->objectName().isEmpty())
            MakeStreet->setObjectName("MakeStreet");
        MakeStreet->resize(400, 300);
        buttonBox = new QDialogButtonBox(MakeStreet);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(MakeStreet);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 0, 58, 16));
        label_2 = new QLabel(MakeStreet);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(130, 0, 58, 16));
        comboBox = new QComboBox(MakeStreet);
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(0, 30, 103, 32));
        comboBox_2 = new QComboBox(MakeStreet);
        comboBox_2->setObjectName("comboBox_2");
        comboBox_2->setGeometry(QRect(120, 30, 103, 32));

        retranslateUi(MakeStreet);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, MakeStreet, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, MakeStreet, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(MakeStreet);
    } // setupUi

    void retranslateUi(QDialog *MakeStreet)
    {
        MakeStreet->setWindowTitle(QCoreApplication::translate("MakeStreet", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("MakeStreet", "Stadt1", nullptr));
        label_2->setText(QCoreApplication::translate("MakeStreet", "Stadt2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MakeStreet: public Ui_MakeStreet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAKESTREET_H
