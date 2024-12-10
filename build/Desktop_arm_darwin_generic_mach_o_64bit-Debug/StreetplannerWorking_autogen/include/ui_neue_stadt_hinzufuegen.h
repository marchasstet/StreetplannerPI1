/********************************************************************************
** Form generated from reading UI file 'neue_stadt_hinzufuegen.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEUE_STADT_HINZUFUEGEN_H
#define UI_NEUE_STADT_HINZUFUEGEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Neue_Stadt_Hinzufuegen
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QLabel *label_3;
    QDialogButtonBox *buttonBox;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;

    void setupUi(QDialog *Neue_Stadt_Hinzufuegen)
    {
        if (Neue_Stadt_Hinzufuegen->objectName().isEmpty())
            Neue_Stadt_Hinzufuegen->setObjectName("Neue_Stadt_Hinzufuegen");
        Neue_Stadt_Hinzufuegen->resize(400, 300);
        formLayout = new QFormLayout(Neue_Stadt_Hinzufuegen);
        formLayout->setObjectName("formLayout");
        label = new QLabel(Neue_Stadt_Hinzufuegen);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(Neue_Stadt_Hinzufuegen);
        lineEdit->setObjectName("lineEdit");

        formLayout->setWidget(1, QFormLayout::LabelRole, lineEdit);

        label_2 = new QLabel(Neue_Stadt_Hinzufuegen);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(Neue_Stadt_Hinzufuegen);
        label_3->setObjectName("label_3");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        buttonBox = new QDialogButtonBox(Neue_Stadt_Hinzufuegen);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(6, QFormLayout::LabelRole, buttonBox);

        spinBox = new QSpinBox(Neue_Stadt_Hinzufuegen);
        spinBox->setObjectName("spinBox");
        spinBox->setMinimum(-1000);
        spinBox->setMaximum(1000);

        formLayout->setWidget(5, QFormLayout::LabelRole, spinBox);

        spinBox_2 = new QSpinBox(Neue_Stadt_Hinzufuegen);
        spinBox_2->setObjectName("spinBox_2");
        spinBox_2->setMinimum(-1000);
        spinBox_2->setMaximum(1000);

        formLayout->setWidget(3, QFormLayout::LabelRole, spinBox_2);

        pushButton = new QPushButton(Neue_Stadt_Hinzufuegen);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(6, QFormLayout::FieldRole, pushButton);


        retranslateUi(Neue_Stadt_Hinzufuegen);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Neue_Stadt_Hinzufuegen, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Neue_Stadt_Hinzufuegen, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Neue_Stadt_Hinzufuegen);
    } // setupUi

    void retranslateUi(QDialog *Neue_Stadt_Hinzufuegen)
    {
        Neue_Stadt_Hinzufuegen->setWindowTitle(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "Bitte Namen der Stadt Eingeben", nullptr));
        lineEdit->setText(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "ihre Eingabe", nullptr));
        label_2->setText(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "X Koordinate", nullptr));
        label_3->setText(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "Y Koordinate", nullptr));
        pushButton->setText(QCoreApplication::translate("Neue_Stadt_Hinzufuegen", "Create City", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Neue_Stadt_Hinzufuegen: public Ui_Neue_Stadt_Hinzufuegen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEUE_STADT_HINZUFUEGEN_H
