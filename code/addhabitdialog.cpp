#include "addhabitdialog.h"
#include "ui_addhabitdialog.h"

AddHabitDialog::AddHabitDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddHabitDialog)
{
    ui->setupUi(this);

    ui->comboHabitName->addItem("Drink water");
    ui->comboHabitName->addItem("Eat food");
    ui->comboHabitName->addItem("Exercise");

    ui->comboFrequency->addItem("Daily");
    ui->comboFrequency->addItem("Weekly");
    ui->comboFrequency->addItem("Custom");

    connect(ui->buttonBox, &QDialogButtonBox::accepted,
            this, &AddHabitDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected,
            this, &AddHabitDialog::reject);
}

AddHabitDialog::~AddHabitDialog()
{
    delete ui;
}

// Returns a Habit object with the user's selections
Habit AddHabitDialog::habit() const
{
    Habit h;

    // 1) The user picks from comboHabitName for the habit name
    QString chosenName = ui->comboHabitName->currentText();
    h.setName(chosenName);

    // 2) Frequency from comboFrequency
    QString freqStr = ui->comboFrequency->currentText();
    if (freqStr == "Daily") {
        h.setFrequency(HabitFrequency::Daily);
    } else if (freqStr == "Weekly") {
        h.setFrequency(HabitFrequency::Weekly);
    } else {
        h.setFrequency(HabitFrequency::Custom);
    }

    // 3) Notes
    QString notes = ui->editNotes->toPlainText();
    h.setNotes(notes);

    // 4) One reminder time
    QList<QTime> times;
    times.append(ui->timeReminder->time());
    h.setReminderTimes(times);

    return h;
}

void AddHabitDialog::setHabit(const Habit &existing)
{
    // If we want to select the name in comboHabitName
    int idxName = ui->comboHabitName->findText(existing.name());
    if (idxName >= 0) {
        ui->comboHabitName->setCurrentIndex(idxName);
    }

    // Frequency
    switch (existing.frequency()) {
    case HabitFrequency::Daily:
        ui->comboFrequency->setCurrentText("Daily");
        break;
    case HabitFrequency::Weekly:
        ui->comboFrequency->setCurrentText("Weekly");
        break;
    default:
        ui->comboFrequency->setCurrentText("Custom");
        break;
    }

    // Notes
    ui->editNotes->setPlainText(existing.notes());

    // If there's at least one reminder time
    if (!existing.reminderTimes().isEmpty()) {
        ui->timeReminder->setTime(existing.reminderTimes().first());
    }
}
