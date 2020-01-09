#include "aboutdialog.h"
#include "ui_aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AboutDialog)
{
    ui->setupUi(this);
    QPixmap leftPix("shape_1.png");
    ui->leftImgLabel->setPixmap(leftPix);

    QPixmap rightPix("shape_3.png");
    ui->rightImgLabel->setPixmap(rightPix);
}

AboutDialog::~AboutDialog()
{
    delete ui;
}

void AboutDialog::on_okPB_clicked()
{
    close();
}
