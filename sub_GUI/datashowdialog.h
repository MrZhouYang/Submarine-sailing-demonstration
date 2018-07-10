#ifndef DATASHOWDIALOG_H
#define DATASHOWDIALOG_H

#include <QDialog>

namespace Ui {
class DataShowDialog;
}

class DataShowDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DataShowDialog(QWidget *parent = 0);
    ~DataShowDialog();

private slots:
    void on_pB_sure_triggered();

private:
    Ui::DataShowDialog *ui;
};

#endif // DATASHOWDIALOG_H
