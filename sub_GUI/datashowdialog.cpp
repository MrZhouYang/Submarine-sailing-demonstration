#include "sub_GUI/datashowdialog.h"
#include "ui_datashowdialog.h"

DataShowDialog::DataShowDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataShowDialog)
{
    ui->setupUi(this);

    ui->pB_sure->setFocus();

    connect(ui->pB_sure, SIGNAL(clicked(bool)), this, SLOT(on_pB_sure_triggered()) );
    connect(ui->pB_cancel,SIGNAL(clicked(bool)), this, SLOT(deleteLater()));
}

DataShowDialog::~DataShowDialog()
{
    delete ui;
}

void DataShowDialog::on_pB_sure_triggered()
{
    this->accept();
    this->deleteLater();
}
