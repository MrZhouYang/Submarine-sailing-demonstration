#include "sub_GUI/automodedialog.h"
#include "ui_automodedialog.h"

AutomodeDialog::AutomodeDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AutomodeDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_sure,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_sure_clicked()) );
    connect(ui->pushButton_cancel,SIGNAL(clicked(bool)), this, SLOT(deleteLater()) );
}

AutomodeDialog::~AutomodeDialog()
{
    delete ui;
}

void AutomodeDialog::on_pushButton_sure_clicked()
{
    this->accept();
    this->deleteLater();
}
