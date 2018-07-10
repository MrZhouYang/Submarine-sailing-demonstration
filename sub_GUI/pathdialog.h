#ifndef PATHDIALOG_H
#define PATHDIALOG_H

#include <QDialog>
#include "ui_pathdialog.h"

namespace Ui {
class PathDialog;
}

class PathDialog : public QDialog
{
    Q_OBJECT

public:
    explicit PathDialog(QWidget *parent = 0);
    ~PathDialog();

private:
    Ui::PathDialog *ui;

private slots:
    void on_pushButton_sure_clicked();

signals:
    void pathSelected(int path);
};

#endif // PATHDIALOG_H
