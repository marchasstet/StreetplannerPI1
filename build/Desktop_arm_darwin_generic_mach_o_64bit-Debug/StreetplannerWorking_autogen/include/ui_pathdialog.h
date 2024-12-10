/********************************************************************************
** Form generated from reading UI file 'pathdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATHDIALOG_H
#define UI_PATHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PathDialog
{
public:
    QDialogButtonBox *buttonBox;
    QComboBox *startCity_Selection;
    QComboBox *destinationCity_Selection;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *PathDialog)
    {
        if (PathDialog->objectName().isEmpty())
            PathDialog->setObjectName("PathDialog");
        PathDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(PathDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        startCity_Selection = new QComboBox(PathDialog);
        startCity_Selection->setObjectName("startCity_Selection");
        startCity_Selection->setGeometry(QRect(30, 20, 103, 32));
        destinationCity_Selection = new QComboBox(PathDialog);
        destinationCity_Selection->setObjectName("destinationCity_Selection");
        destinationCity_Selection->setGeometry(QRect(30, 90, 103, 32));
        label = new QLabel(PathDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 0, 131, 16));
        label_2 = new QLabel(PathDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 60, 58, 16));

        retranslateUi(PathDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, PathDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, PathDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(PathDialog);
    } // setupUi

    void retranslateUi(QDialog *PathDialog)
    {
        PathDialog->setWindowTitle(QCoreApplication::translate("PathDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("PathDialog", "Start Stadt", nullptr));
        label_2->setText(QCoreApplication::translate("PathDialog", "Ziel Stadt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PathDialog: public Ui_PathDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATHDIALOG_H
