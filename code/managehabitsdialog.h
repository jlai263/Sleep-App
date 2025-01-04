#ifndef MANAGEHABITSDIALOG_H
#define MANAGEHABITSDIALOG_H

#include <QDialog>
#include "habitmanager.h"

namespace Ui {
class ManageHabitsDialog;
}

class ManageHabitsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ManageHabitsDialog(QWidget *parent = nullptr);
    ~ManageHabitsDialog();

    void setHabitManager(const HabitManager &manager);
    HabitManager habitManager() const;

private slots:
    void onAddHabitClicked();
    void onEditHabitClicked();
    void onRemoveHabitClicked();
    void onCloseClicked();

private:
    Ui::ManageHabitsDialog *ui;
    HabitManager m_manager;  // local copy

    void rebuildTable();
};

#endif // MANAGEHABITSDIALOG_H
