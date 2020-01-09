#include "urahdialog.h"
#include "ui_urahdialog.h"

UrahDialog::UrahDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UrahDialog)
{
    ui->setupUi(this);
}

UrahDialog::~UrahDialog()
{
    delete ui;
}
