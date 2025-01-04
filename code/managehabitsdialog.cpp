#include "managehabitsdialog.h"
#include "ui_managehabitsdialog.h"

#include <QDebug>
#include <QMessageBox>
#include "addhabitdialog.h"

ManageHabitsDialog::ManageHabitsDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ManageHabitsDialog)
{
    ui->setupUi(this);

    // Table setup
    ui->tblHabits->setColumnCount(3);
    ui->tblHabits->setHorizontalHeaderLabels(
        QStringList() << "Name" << "Frequency" << "Notes"
        );
    ui->tblHabits->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tblHabits->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->tblHabits->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Connect buttons
    connect(ui->btnAddHabit, &QPushButton::clicked,
            this, &ManageHabitsDialog::onAddHabitClicked);
    connect(ui->btnEditHabit, &QPushButton::clicked,
            this, &ManageHabitsDialog::onEditHabitClicked);
    connect(ui->btnRemoveHabit, &QPushButton::clicked,
            this, &ManageHabitsDialog::onRemoveHabitClicked);
    connect(ui->btnClose, &QPushButton::clicked,
            this, &ManageHabitsDialog::onCloseClicked);
}

ManageHabitsDialog::~ManageHabitsDialog()
{
    delete ui;
}

void ManageHabitsDialog::setHabitManager(const HabitManager &manager)
{
    m_manager = manager;
    rebuildTable();
}

HabitManager ManageHabitsDialog::habitManager() const
{
    return m_manager;
}

void ManageHabitsDialog::rebuildTable()
{
    ui->tblHabits->setRowCount(0);
    auto habits = m_manager.habits();
    for (int i = 0; i < habits.size(); i++) {
        ui->tblHabits->insertRow(i);

        // Name
        ui->tblHabits->setItem(i, 0,
                               new QTableWidgetItem(habits[i].name())
                               );

        // Frequency
        QString freqStr;
        switch (habits[i].frequency()) {
        case HabitFrequency::Daily:  freqStr = "Daily"; break;
        case HabitFrequency::Weekly: freqStr = "Weekly"; break;
        default:                     freqStr = "Custom"; break;
        }
        ui->tblHabits->setItem(i, 1,
                               new QTableWidgetItem(freqStr)
                               );

        // Notes
        ui->tblHabits->setItem(i, 2,
                               new QTableWidgetItem(habits[i].notes())
                               );
    }
}

void ManageHabitsDialog::onAddHabitClicked()
{
    AddHabitDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted) {
        Habit h = dlg.habit();
        m_manager.addHabit(h);
        rebuildTable();
    }
}

void ManageHabitsDialog::onEditHabitClicked()
{
    int row = ui->tblHabits->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Edit Habit", "Select a habit to edit.");
        return;
    }

    auto habits = m_manager.habits();
    if (row >= habits.size()) return; // safety

    // Pre-fill AddHabitDialog
    AddHabitDialog dlg(this);
    dlg.setHabit(habits[row]);
    if (dlg.exec() == QDialog::Accepted) {
        // Update that habit
        habits[row] = dlg.habit();
        // Overwrite manager
        m_manager = HabitManager();
        for (auto &h : habits) {
            m_manager.addHabit(h);
        }
        rebuildTable();
    }
}

void ManageHabitsDialog::onRemoveHabitClicked()
{
    int row = ui->tblHabits->currentRow();
    if (row < 0) {
        QMessageBox::warning(this, "Remove Habit", "Select a habit to remove.");
        return;
    }
    m_manager.removeHabit(row);
    rebuildTable();
}

void ManageHabitsDialog::onCloseClicked()
{
    close();
}
