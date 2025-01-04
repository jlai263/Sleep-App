/********************************************************************************
** Form generated from reading UI file 'addsleepsessiondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSLEEPSESSIONDIALOG_H
#define UI_ADDSLEEPSESSIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddSleepSessionDialog
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *lblStart;
    QDateTimeEdit *dateTimeStart;
    QLabel *lblEnd;
    QDateTimeEdit *dateTimeEnd;
    QLabel *lblQuality;
    QSpinBox *spinQuality;
    QLabel *lblNotes;
    QTextEdit *textNotes;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddSleepSessionDialog)
    {
        if (AddSleepSessionDialog->objectName().isEmpty())
            AddSleepSessionDialog->setObjectName("AddSleepSessionDialog");
        verticalLayout = new QVBoxLayout(AddSleepSessionDialog);
        verticalLayout->setObjectName("verticalLayout");
        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        lblStart = new QLabel(AddSleepSessionDialog);
        lblStart->setObjectName("lblStart");

        formLayout->setWidget(0, QFormLayout::LabelRole, lblStart);

        dateTimeStart = new QDateTimeEdit(AddSleepSessionDialog);
        dateTimeStart->setObjectName("dateTimeStart");

        formLayout->setWidget(0, QFormLayout::FieldRole, dateTimeStart);

        lblEnd = new QLabel(AddSleepSessionDialog);
        lblEnd->setObjectName("lblEnd");

        formLayout->setWidget(1, QFormLayout::LabelRole, lblEnd);

        dateTimeEnd = new QDateTimeEdit(AddSleepSessionDialog);
        dateTimeEnd->setObjectName("dateTimeEnd");

        formLayout->setWidget(1, QFormLayout::FieldRole, dateTimeEnd);

        lblQuality = new QLabel(AddSleepSessionDialog);
        lblQuality->setObjectName("lblQuality");

        formLayout->setWidget(2, QFormLayout::LabelRole, lblQuality);

        spinQuality = new QSpinBox(AddSleepSessionDialog);
        spinQuality->setObjectName("spinQuality");
        spinQuality->setMinimum(1);
        spinQuality->setMaximum(5);
        spinQuality->setValue(3);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinQuality);

        lblNotes = new QLabel(AddSleepSessionDialog);
        lblNotes->setObjectName("lblNotes");

        formLayout->setWidget(3, QFormLayout::LabelRole, lblNotes);

        textNotes = new QTextEdit(AddSleepSessionDialog);
        textNotes->setObjectName("textNotes");

        formLayout->setWidget(3, QFormLayout::FieldRole, textNotes);


        verticalLayout->addLayout(formLayout);

        buttonBox = new QDialogButtonBox(AddSleepSessionDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddSleepSessionDialog);

        QMetaObject::connectSlotsByName(AddSleepSessionDialog);
    } // setupUi

    void retranslateUi(QDialog *AddSleepSessionDialog)
    {
        AddSleepSessionDialog->setWindowTitle(QCoreApplication::translate("AddSleepSessionDialog", "Add Sleep Session", nullptr));
        lblStart->setText(QCoreApplication::translate("AddSleepSessionDialog", "Start Time:", nullptr));
        lblEnd->setText(QCoreApplication::translate("AddSleepSessionDialog", "End Time:", nullptr));
        lblQuality->setText(QCoreApplication::translate("AddSleepSessionDialog", "Quality (1-5):", nullptr));
        lblNotes->setText(QCoreApplication::translate("AddSleepSessionDialog", "Notes:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddSleepSessionDialog: public Ui_AddSleepSessionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSLEEPSESSIONDIALOG_H
