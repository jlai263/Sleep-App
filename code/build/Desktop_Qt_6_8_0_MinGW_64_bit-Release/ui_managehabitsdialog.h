/********************************************************************************
** Form generated from reading UI file 'managehabitsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MANAGEHABITSDIALOG_H
#define UI_MANAGEHABITSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ManageHabitsDialog
{
public:
    QVBoxLayout *verticalLayoutMain;
    QTableWidget *tblHabits;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnAddHabit;
    QPushButton *btnEditHabit;
    QPushButton *btnRemoveHabit;
    QPushButton *btnClose;

    void setupUi(QDialog *ManageHabitsDialog)
    {
        if (ManageHabitsDialog->objectName().isEmpty())
            ManageHabitsDialog->setObjectName("ManageHabitsDialog");
        verticalLayoutMain = new QVBoxLayout(ManageHabitsDialog);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        tblHabits = new QTableWidget(ManageHabitsDialog);
        tblHabits->setObjectName("tblHabits");
        tblHabits->setColumnCount(3);
        tblHabits->setRowCount(0);

        verticalLayoutMain->addWidget(tblHabits);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnAddHabit = new QPushButton(ManageHabitsDialog);
        btnAddHabit->setObjectName("btnAddHabit");

        horizontalLayoutButtons->addWidget(btnAddHabit);

        btnEditHabit = new QPushButton(ManageHabitsDialog);
        btnEditHabit->setObjectName("btnEditHabit");

        horizontalLayoutButtons->addWidget(btnEditHabit);

        btnRemoveHabit = new QPushButton(ManageHabitsDialog);
        btnRemoveHabit->setObjectName("btnRemoveHabit");

        horizontalLayoutButtons->addWidget(btnRemoveHabit);

        btnClose = new QPushButton(ManageHabitsDialog);
        btnClose->setObjectName("btnClose");

        horizontalLayoutButtons->addWidget(btnClose);


        verticalLayoutMain->addLayout(horizontalLayoutButtons);


        retranslateUi(ManageHabitsDialog);

        QMetaObject::connectSlotsByName(ManageHabitsDialog);
    } // setupUi

    void retranslateUi(QDialog *ManageHabitsDialog)
    {
        ManageHabitsDialog->setWindowTitle(QCoreApplication::translate("ManageHabitsDialog", "Manage Habits", nullptr));
        btnAddHabit->setText(QCoreApplication::translate("ManageHabitsDialog", "Add Habit", nullptr));
        btnEditHabit->setText(QCoreApplication::translate("ManageHabitsDialog", "Edit Habit", nullptr));
        btnRemoveHabit->setText(QCoreApplication::translate("ManageHabitsDialog", "Remove Habit", nullptr));
        btnClose->setText(QCoreApplication::translate("ManageHabitsDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ManageHabitsDialog: public Ui_ManageHabitsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MANAGEHABITSDIALOG_H
