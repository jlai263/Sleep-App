#ifndef ADDHABITDIALOG_H
#define ADDHABITDIALOG_H

#include <QDialog>
#include "habit.h"

namespace Ui {
class AddHabitDialog;
}

class AddHabitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddHabitDialog(QWidget *parent = nullptr);
    ~AddHabitDialog();

    Habit habit() const;       // Return the Habit object built from the user input
    void setHabit(const Habit &h); // If editing an existing habit

private:
    Ui::AddHabitDialog *ui;
};

#endif // ADDHABITDIALOG_H
