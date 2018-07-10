#include "sub_GUI/pathdialog.h"
#include <QDebug>

PathDialog::PathDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PathDialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_sure,SIGNAL(clicked(bool)),this,SLOT(on_pushButton_sure_clicked()) );
    connect(ui->pushButton_cancel,SIGNAL(clicked(bool)), this, SLOT(deleteLater()) );
}

PathDialog::~PathDialog()
{
    delete ui;
}

void PathDialog::on_pushButton_sure_clicked()
{
    if( ui->comboBox_start->currentText()==QString("天津") && ui->comboBox_end->currentText() == QString("上海") )
    {
        qDebug()<< "路径选择：天津-》上海";
        emit pathSelected(1);
    }
    if( ui->comboBox_start->currentText()==QString("上海") && ui->comboBox_end->currentText() == QString("日本") )
    {
        qDebug()<< "路径选择：上海-》日本";
        emit pathSelected(2);
    }

    if( ui->comboBox_start->currentText()==QString("天津") && ui->comboBox_end->currentText() == QString("日本") )
    {
        qDebug()<< "路径选择：天津-》日本";
        emit pathSelected(3);
    }
    this->accept();
    this->deleteLater();
}


