/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayoutMain;
    QLabel *lblTitle;
    QFrame *frameMain;
    QVBoxLayout *verticalLayoutFrame;
    QTableWidget *tblSleepSessions;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnAddSleepSession;
    QPushButton *btnAnalyzeSleep;
    QPushButton *btnSaveData;
    QPushButton *btnLoadData;
    QPushButton *btnManageHabits;
    QPushButton *btnSmartAlarm;
    QLabel *lblFooter;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutMain = new QVBoxLayout(centralwidget);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        lblTitle = new QLabel(centralwidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);
        lblTitle->setStyleSheet(QString::fromUtf8("\n"
"        font-size: 24px;\n"
"        font-weight: bold;\n"
"        color: #3c3f41;\n"
"       "));

        verticalLayoutMain->addWidget(lblTitle);

        frameMain = new QFrame(centralwidget);
        frameMain->setObjectName("frameMain");
        frameMain->setFrameShape(QFrame::StyledPanel);
        frameMain->setFrameShadow(QFrame::Raised);
        verticalLayoutFrame = new QVBoxLayout(frameMain);
        verticalLayoutFrame->setObjectName("verticalLayoutFrame");
        tblSleepSessions = new QTableWidget(frameMain);
        tblSleepSessions->setObjectName("tblSleepSessions");
        tblSleepSessions->setColumnCount(2);
        tblSleepSessions->setRowCount(0);

        verticalLayoutFrame->addWidget(tblSleepSessions);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnAddSleepSession = new QPushButton(frameMain);
        btnAddSleepSession->setObjectName("btnAddSleepSession");

        horizontalLayoutButtons->addWidget(btnAddSleepSession);

        btnAnalyzeSleep = new QPushButton(frameMain);
        btnAnalyzeSleep->setObjectName("btnAnalyzeSleep");

        horizontalLayoutButtons->addWidget(btnAnalyzeSleep);

        btnSaveData = new QPushButton(frameMain);
        btnSaveData->setObjectName("btnSaveData");

        horizontalLayoutButtons->addWidget(btnSaveData);

        btnLoadData = new QPushButton(frameMain);
        btnLoadData->setObjectName("btnLoadData");

        horizontalLayoutButtons->addWidget(btnLoadData);

        btnManageHabits = new QPushButton(frameMain);
        btnManageHabits->setObjectName("btnManageHabits");

        horizontalLayoutButtons->addWidget(btnManageHabits);

        btnSmartAlarm = new QPushButton(frameMain);
        btnSmartAlarm->setObjectName("btnSmartAlarm");

        horizontalLayoutButtons->addWidget(btnSmartAlarm);


        verticalLayoutFrame->addLayout(horizontalLayoutButtons);


        verticalLayoutMain->addWidget(frameMain);

        lblFooter = new QLabel(centralwidget);
        lblFooter->setObjectName("lblFooter");
        lblFooter->setAlignment(Qt::AlignCenter);
        lblFooter->setStyleSheet(QString::fromUtf8("\n"
"        font-style: italic;\n"
"        color: #555555;\n"
"       "));

        verticalLayoutMain->addWidget(lblFooter);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Sleep Better App", nullptr));
        lblTitle->setText(QCoreApplication::translate("MainWindow", "Sleep Better App", nullptr));
        btnAddSleepSession->setText(QCoreApplication::translate("MainWindow", "Add Sleep Session", nullptr));
        btnAnalyzeSleep->setText(QCoreApplication::translate("MainWindow", "Analyze Sleep", nullptr));
        btnSaveData->setText(QCoreApplication::translate("MainWindow", "Save Data", nullptr));
        btnLoadData->setText(QCoreApplication::translate("MainWindow", "Load Data", nullptr));
        btnManageHabits->setText(QCoreApplication::translate("MainWindow", "Manage Habits", nullptr));
        btnSmartAlarm->setText(QCoreApplication::translate("MainWindow", "Smart Alarm", nullptr));
        lblFooter->setText(QCoreApplication::translate("MainWindow", "Track your habits and sleep patterns for a healthier life!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
