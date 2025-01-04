/********************************************************************************
** Form generated from reading UI file 'smartalarmdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTALARMDIALOG_H
#define UI_SMARTALARMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SmartAlarmDialog
{
public:
    QVBoxLayout *verticalLayoutMain;
    QFormLayout *formLayout;
    QLabel *lblWakeTime;
    QTimeEdit *timeTargetWake;
    QLabel *lblDesiredHours;
    QDoubleSpinBox *spinDesiredHours;
    QLabel *lblRecommendedBedtimeLabel;
    QLabel *lblOptimalTime;
    QHBoxLayout *horizontalLayoutButtons;
    QPushButton *btnCalculate;
    QPushButton *buttonBoxOk;
    QPushButton *buttonBoxCancel;

    void setupUi(QDialog *SmartAlarmDialog)
    {
        if (SmartAlarmDialog->objectName().isEmpty())
            SmartAlarmDialog->setObjectName("SmartAlarmDialog");
        verticalLayoutMain = new QVBoxLayout(SmartAlarmDialog);
        verticalLayoutMain->setObjectName("verticalLayoutMain");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        lblWakeTime = new QLabel(SmartAlarmDialog);
        lblWakeTime->setObjectName("lblWakeTime");

        formLayout->setWidget(0, QFormLayout::LabelRole, lblWakeTime);

        timeTargetWake = new QTimeEdit(SmartAlarmDialog);
        timeTargetWake->setObjectName("timeTargetWake");

        formLayout->setWidget(0, QFormLayout::FieldRole, timeTargetWake);

        lblDesiredHours = new QLabel(SmartAlarmDialog);
        lblDesiredHours->setObjectName("lblDesiredHours");

        formLayout->setWidget(1, QFormLayout::LabelRole, lblDesiredHours);

        spinDesiredHours = new QDoubleSpinBox(SmartAlarmDialog);
        spinDesiredHours->setObjectName("spinDesiredHours");
        spinDesiredHours->setMinimum(0.000000000000000);
        spinDesiredHours->setMaximum(12.000000000000000);
        spinDesiredHours->setValue(8.000000000000000);
        spinDesiredHours->setSingleStep(0.500000000000000);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinDesiredHours);

        lblRecommendedBedtimeLabel = new QLabel(SmartAlarmDialog);
        lblRecommendedBedtimeLabel->setObjectName("lblRecommendedBedtimeLabel");

        formLayout->setWidget(2, QFormLayout::LabelRole, lblRecommendedBedtimeLabel);

        lblOptimalTime = new QLabel(SmartAlarmDialog);
        lblOptimalTime->setObjectName("lblOptimalTime");

        formLayout->setWidget(2, QFormLayout::FieldRole, lblOptimalTime);


        verticalLayoutMain->addLayout(formLayout);

        horizontalLayoutButtons = new QHBoxLayout();
        horizontalLayoutButtons->setObjectName("horizontalLayoutButtons");
        btnCalculate = new QPushButton(SmartAlarmDialog);
        btnCalculate->setObjectName("btnCalculate");

        horizontalLayoutButtons->addWidget(btnCalculate);

        buttonBoxOk = new QPushButton(SmartAlarmDialog);
        buttonBoxOk->setObjectName("buttonBoxOk");

        horizontalLayoutButtons->addWidget(buttonBoxOk);

        buttonBoxCancel = new QPushButton(SmartAlarmDialog);
        buttonBoxCancel->setObjectName("buttonBoxCancel");

        horizontalLayoutButtons->addWidget(buttonBoxCancel);


        verticalLayoutMain->addLayout(horizontalLayoutButtons);


        retranslateUi(SmartAlarmDialog);

        QMetaObject::connectSlotsByName(SmartAlarmDialog);
    } // setupUi

    void retranslateUi(QDialog *SmartAlarmDialog)
    {
        SmartAlarmDialog->setWindowTitle(QCoreApplication::translate("SmartAlarmDialog", "Smart Alarm", nullptr));
        lblWakeTime->setText(QCoreApplication::translate("SmartAlarmDialog", "Target Wake Time:", nullptr));
        lblDesiredHours->setText(QCoreApplication::translate("SmartAlarmDialog", "Desired Sleep (hrs):", nullptr));
        lblRecommendedBedtimeLabel->setText(QCoreApplication::translate("SmartAlarmDialog", "Recommended Bedtime:", nullptr));
        lblOptimalTime->setText(QCoreApplication::translate("SmartAlarmDialog", "--:--", nullptr));
        btnCalculate->setText(QCoreApplication::translate("SmartAlarmDialog", "Calculate", nullptr));
        buttonBoxOk->setText(QCoreApplication::translate("SmartAlarmDialog", "OK", nullptr));
        buttonBoxCancel->setText(QCoreApplication::translate("SmartAlarmDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SmartAlarmDialog: public Ui_SmartAlarmDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTALARMDIALOG_H
