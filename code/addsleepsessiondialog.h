#ifndef ADDSLEEPSESSIONDIALOG_H
#define ADDSLEEPSESSIONDIALOG_H

#include <QDialog>
#include <QDateTime>

namespace Ui {
class AddSleepSessionDialog;
}

class AddSleepSessionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddSleepSessionDialog(QWidget *parent = nullptr);
    ~AddSleepSessionDialog();

    QDateTime startTime() const;
    QDateTime endTime() const;
    int quality() const;
    QString notes() const;

private:
    Ui::AddSleepSessionDialog *ui;
};

#endif // ADDSLEEPSESSIONDIALOG_H
