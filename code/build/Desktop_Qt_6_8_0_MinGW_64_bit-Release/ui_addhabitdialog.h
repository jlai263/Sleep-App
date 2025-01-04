/********************************************************************************
** Form generated from reading UI file 'addhabitdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDHABITDIALOG_H
#define UI_ADDHABITDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddHabitDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblHabit;
    QComboBox *comboHabitName;
    QLabel *lblFrequency;
    QComboBox *comboFrequency;
    QLabel *lblNotes;
    QTextEdit *editNotes;
    QLabel *lblReminderTime;
    QTimeEdit *timeReminder;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddHabitDialog)
    {
        if (AddHabitDialog->objectName().isEmpty())
            AddHabitDialog->setObjectName("AddHabitDialog");
        verticalLayout = new QVBoxLayout(AddHabitDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        lblHabit = new QLabel(AddHabitDialog);
        lblHabit->setObjectName("lblHabit");

        formLayout->setWidget(0, QFormLayout::LabelRole, lblHabit);

        comboHabitName = new QComboBox(AddHabitDialog);
        comboHabitName->setObjectName("comboHabitName");

        formLayout->setWidget(0, QFormLayout::FieldRole, comboHabitName);

        lblFrequency = new QLabel(AddHabitDialog);
        lblFrequency->setObjectName("lblFrequency");

        formLayout->setWidget(1, QFormLayout::LabelRole, lblFrequency);

        comboFrequency = new QComboBox(AddHabitDialog);
        comboFrequency->setObjectName("comboFrequency");

        formLayout->setWidget(1, QFormLayout::FieldRole, comboFrequency);

        lblNotes = new QLabel(AddHabitDialog);
        lblNotes->setObjectName("lblNotes");

        formLayout->setWidget(2, QFormLayout::LabelRole, lblNotes);

        editNotes = new QTextEdit(AddHabitDialog);
        editNotes->setObjectName("editNotes");

        formLayout->setWidget(2, QFormLayout::FieldRole, editNotes);

        lblReminderTime = new QLabel(AddHabitDialog);
        lblReminderTime->setObjectName("lblReminderTime");

        formLayout->setWidget(3, QFormLayout::LabelRole, lblReminderTime);

        timeReminder = new QTimeEdit(AddHabitDialog);
        timeReminder->setObjectName("timeReminder");

        formLayout->setWidget(3, QFormLayout::FieldRole, timeReminder);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddHabitDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddHabitDialog);

        QMetaObject::connectSlotsByName(AddHabitDialog);
    } // setupUi

    void retranslateUi(QDialog *AddHabitDialog)
    {
        AddHabitDialog->setWindowTitle(QCoreApplication::translate("AddHabitDialog", "Add / Edit Habit", nullptr));
        lblHabit->setText(QCoreApplication::translate("AddHabitDialog", "Habit:", nullptr));
        lblFrequency->setText(QCoreApplication::translate("AddHabitDialog", "Frequency:", nullptr));
        lblNotes->setText(QCoreApplication::translate("AddHabitDialog", "Notes:", nullptr));
        lblReminderTime->setText(QCoreApplication::translate("AddHabitDialog", "Reminder Time:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddHabitDialog: public Ui_AddHabitDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDHABITDIALOG_H
