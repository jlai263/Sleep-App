#include "addsleepsessiondialog.h"
#include "ui_addsleepsessiondialog.h"

AddSleepSessionDialog::AddSleepSessionDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddSleepSessionDialog)
{
    ui->setupUi(this);

    // Set default times:
    // Start => 8 hours before now, End => current time
    QDateTime now = QDateTime::currentDateTime();
    ui->dateTimeStart->setDateTime(now.addSecs(-8 * 3600)); // 8 hours behind current time
    ui->dateTimeEnd->setDateTime(now);                     // current time

    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &AddSleepSessionDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected,
            this, &AddSleepSessionDialog::reject);
}

AddSleepSessionDialog::~AddSleepSessionDialog()
{
    delete ui;
}

QDateTime AddSleepSessionDialog::startTime() const
{
    return ui->dateTimeStart->dateTime();
}

QDateTime AddSleepSessionDialog::endTime() const
{
    return ui->dateTimeEnd->dateTime();
}

int AddSleepSessionDialog::quality() const
{
    return ui->spinQuality->value(); // 1-5
}

QString AddSleepSessionDialog::notes() const
{
    return ui->textNotes->toPlainText();
}
