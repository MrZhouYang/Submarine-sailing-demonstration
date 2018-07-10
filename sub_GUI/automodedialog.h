#ifndef AUTOMODEDIALOG_H
#define AUTOMODEDIALOG_H

#include <QDialog>

namespace Ui {
class AutomodeDialog;
}

class AutomodeDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AutomodeDialog(QWidget *parent = 0);
    ~AutomodeDialog();

private slots:
    void on_pushButton_sure_clicked();

private:
    Ui::AutomodeDialog *ui;
};

#endif // AUTOMODEDIALOG_H
