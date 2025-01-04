/********************************************************************************
** Form generated from reading UI file 'settingsdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDIALOG_H
#define UI_SETTINGSDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingsDialog
{
public:
    QSpinBox *sleepDurationSpinBox;
    QLabel *label;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SettingsDialog)
    {
        if (SettingsDialog->objectName().isEmpty())
            SettingsDialog->setObjectName("SettingsDialog");
        SettingsDialog->resize(400, 300);
        sleepDurationSpinBox = new QSpinBox(SettingsDialog);
        sleepDurationSpinBox->setObjectName("sleepDurationSpinBox");
        sleepDurationSpinBox->setGeometry(QRect(100, 80, 91, 25));
        sleepDurationSpinBox->setMinimum(4);
        sleepDurationSpinBox->setMaximum(12);
        label = new QLabel(SettingsDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 50, 161, 16));
        confirmButton = new QPushButton(SettingsDialog);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(100, 130, 80, 24));
        cancelButton = new QPushButton(SettingsDialog);
        cancelButton->setObjectName("cancelButton");
        cancelButton->setGeometry(QRect(190, 130, 80, 24));

        retranslateUi(SettingsDialog);

        QMetaObject::connectSlotsByName(SettingsDialog);
    } // setupUi

    void retranslateUi(QDialog *SettingsDialog)
    {
        SettingsDialog->setWindowTitle(QCoreApplication::translate("SettingsDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("SettingsDialog", "Target Sleep Duration (hours)", nullptr));
        confirmButton->setText(QCoreApplication::translate("SettingsDialog", "Save", nullptr));
        cancelButton->setText(QCoreApplication::translate("SettingsDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsDialog: public Ui_SettingsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDIALOG_H
