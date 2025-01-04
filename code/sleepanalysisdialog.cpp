#include "sleepanalysisdialog.h"
#include "ui_sleepanalysisdialog.h"

#include <QPushButton>
#include <QDebug>

SleepAnalysisDialog::SleepAnalysisDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SleepAnalysisDialog)
{
    ui->setupUi(this);

    // Connect the Close button
    connect(ui->btnClose, &QPushButton::clicked,
            this, &SleepAnalysisDialog::onCloseClicked);
}

SleepAnalysisDialog::~SleepAnalysisDialog()
{
    delete ui;
}

void SleepAnalysisDialog::setAnalyzer(const SleepAnalyzer &analyzer)
{
    m_analyzer = analyzer;
    buildAnalysisText();
}

void SleepAnalysisDialog::buildAnalysisText()
{
    // We'll show total hours, average, last 14 days, plus any recommendations
    double total = m_analyzer.getTotalSleepHours();
    double avgAll = m_analyzer.getAverageSleepHours();
    double avg14  = m_analyzer.getAverageSleepHoursLast14Days();

    // Build a text block
    QString text;
    text += "<b>Total Sleep (all-time):</b> "
            + QString::number(total, 'f', 2) + " hours<br>";

    text += "<b>Average Sleep (all-time):</b> "
            + QString::number(avgAll, 'f', 2) + " hours/night<br>";

    text += "<b>Average Sleep (last 14 days):</b> "
            + QString::number(avg14, 'f', 2) + " hours/night<br><br>";

    // Simple recommendation logic
    if (avg14 < 6) {
        text += "You're sleeping less than 6 hours recently. Consider going to bed earlier.<br>";
    } else if (avg14 < 7) {
        text += "Slightly below recommended 7-8 hours. Try to allocate more rest time.<br>";
    } else if (avg14 <= 8) {
        text += "You're within the recommended 7-8 hours—great job!<br>";
    } else {
        text += "You're sleeping more than 8 hours recently. If you feel fine, that's okay; otherwise check for oversleeping.<br>";
    }

    // Compare recent to all-time
    double diff = avg14 - avgAll;
    if (diff > 1.0) {
        text += "Your recent sleep is significantly higher than your all-time average—nice improvement!<br>";
    } else if (diff < -1.0) {
        text += "Your recent sleep is significantly lower than your all-time average—try to see what's changed.<br>";
    }

    // Set text on the label
    ui->lblAnalysis->setText(text);
}

void SleepAnalysisDialog::onCloseClicked()
{
    close(); // or accept();
}
