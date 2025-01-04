#ifndef SLEEPANALYSISDIALOG_H
#define SLEEPANALYSISDIALOG_H

#include <QDialog>
#include "sleepanalyzer.h"

namespace Ui {
class SleepAnalysisDialog;
}

class SleepAnalysisDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SleepAnalysisDialog(QWidget *parent = nullptr);
    ~SleepAnalysisDialog();

    // Set the analyzer so we can compute and display stats
    void setAnalyzer(const SleepAnalyzer &analyzer);

private slots:
    void onCloseClicked();

private:
    Ui::SleepAnalysisDialog *ui;
    SleepAnalyzer m_analyzer;
    void buildAnalysisText();
};

#endif // SLEEPANALYSISDIALOG_H
