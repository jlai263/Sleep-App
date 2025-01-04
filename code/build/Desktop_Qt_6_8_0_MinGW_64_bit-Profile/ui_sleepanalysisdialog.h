/********************************************************************************
** Form generated from reading UI file 'sleepanalysisdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SLEEPANALYSISDIALOG_H
#define UI_SLEEPANALYSISDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SleepAnalysisDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblAnalysis;
    QPushButton *btnClose;

    void setupUi(QDialog *SleepAnalysisDialog)
    {
        if (SleepAnalysisDialog->objectName().isEmpty())
            SleepAnalysisDialog->setObjectName("SleepAnalysisDialog");
        verticalLayout = new QVBoxLayout(SleepAnalysisDialog);
        verticalLayout->setObjectName("verticalLayout");
        lblAnalysis = new QLabel(SleepAnalysisDialog);
        lblAnalysis->setObjectName("lblAnalysis");
        lblAnalysis->setAlignment(Qt::AlignTop|Qt::AlignLeft);

        verticalLayout->addWidget(lblAnalysis);

        btnClose = new QPushButton(SleepAnalysisDialog);
        btnClose->setObjectName("btnClose");

        verticalLayout->addWidget(btnClose);


        retranslateUi(SleepAnalysisDialog);

        QMetaObject::connectSlotsByName(SleepAnalysisDialog);
    } // setupUi

    void retranslateUi(QDialog *SleepAnalysisDialog)
    {
        SleepAnalysisDialog->setWindowTitle(QCoreApplication::translate("SleepAnalysisDialog", "Sleep Analysis", nullptr));
        lblAnalysis->setText(QCoreApplication::translate("SleepAnalysisDialog", "Analysis text goes here...", nullptr));
        btnClose->setText(QCoreApplication::translate("SleepAnalysisDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SleepAnalysisDialog: public Ui_SleepAnalysisDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SLEEPANALYSISDIALOG_H
