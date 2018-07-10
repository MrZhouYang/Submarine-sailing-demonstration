#include "sub_GUI/manualdialog.h"
#include "ui_manualdialog.h"

ManualDialog::ManualDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ManualDialog)
{
    ui->setupUi(this);

    ui->pushButton_sure->setFocus();

    connect(ui->pushButton_sure,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_sure_clicked()) );
    connect(ui->pushButton_cancel,SIGNAL(clicked(bool)), this, SLOT(deleteLater()) );
}

ManualDialog::~ManualDialog()
{
    delete ui;
}

void ManualDialog::on_pushButton_sure_clicked()
{
    this->accept();
    this->deleteLater();
}
