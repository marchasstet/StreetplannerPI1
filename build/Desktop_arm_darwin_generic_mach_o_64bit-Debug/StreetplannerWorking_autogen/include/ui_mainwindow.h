/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionclear_scene;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit;
    QPushButton *pushButton_10;
    QPushButton *pushButton_6;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_9;
    QPushButton *pushButton_2;
    QCheckBox *checkBox;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_7;
    QPushButton *pushButton_4;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_8;
    QLabel *label;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QMenuBar *menubar;
    QMenu *menuFilke;
    QMenu *menuScene;
    QMenu *menuInfo;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setEnabled(false);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName("actionSave");
        actionSave->setEnabled(false);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        actionclear_scene = new QAction(MainWindow);
        actionclear_scene->setObjectName("actionclear_scene");
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName("actionAbout");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName("lineEdit");

        gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");

        gridLayout->addWidget(pushButton_10, 14, 0, 1, 1);

        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");

        gridLayout->addWidget(pushButton_6, 12, 0, 1, 1);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 17, 0, 1, 1);

        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 10, 0, 1, 1);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 5, 0, 1, 1);

        checkBox = new QCheckBox(centralwidget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 4, 0, 1, 1);

        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 9, 0, 1, 1);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 3, 0, 1, 1);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");

        gridLayout->addWidget(pushButton_7, 13, 0, 1, 1);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 8, 0, 1, 1);

        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setMaximumSize(QSize(1000, 1000));

        gridLayout->addWidget(graphicsView, 0, 1, 18, 1);

        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 11, 0, 1, 1);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        pushButton_11 = new QPushButton(centralwidget);
        pushButton_11->setObjectName("pushButton_11");

        gridLayout->addWidget(pushButton_11, 7, 0, 1, 1);

        pushButton_12 = new QPushButton(centralwidget);
        pushButton_12->setObjectName("pushButton_12");

        gridLayout->addWidget(pushButton_12, 15, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        menuFilke = new QMenu(menubar);
        menuFilke->setObjectName("menuFilke");
        menuScene = new QMenu(menubar);
        menuScene->setObjectName("menuScene");
        menuInfo = new QMenu(menubar);
        menuInfo->setObjectName("menuInfo");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFilke->menuAction());
        menubar->addAction(menuScene->menuAction());
        menubar->addAction(menuInfo->menuAction());
        menuFilke->addAction(actionOpen);
        menuFilke->addAction(actionSave);
        menuFilke->addSeparator();
        menuFilke->addAction(actionExit);
        menuScene->addAction(actionclear_scene);
        menuInfo->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
#if QT_CONFIG(shortcut)
        actionExit->setShortcut(QCoreApplication::translate("MainWindow", "Alt+E", nullptr));
#endif // QT_CONFIG(shortcut)
        actionclear_scene->setText(QCoreApplication::translate("MainWindow", "clear scene", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainWindow", "About", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "Add Street", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Add City", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Test all Cities", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "Test Dijkstra", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Test Draw City", nullptr));
        checkBox->setText(QCoreApplication::translate("MainWindow", "Test fkt hide", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "Test add Street", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "PushButton", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "Fill Map", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Test streets", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "TestAbstMap", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        pushButton_11->setText(QCoreApplication::translate("MainWindow", "Test SmallBig ", nullptr));
        pushButton_12->setText(QCoreApplication::translate("MainWindow", "Fill map File", nullptr));
        menuFilke->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuScene->setTitle(QCoreApplication::translate("MainWindow", "Scene", nullptr));
        menuInfo->setTitle(QCoreApplication::translate("MainWindow", "Info", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
