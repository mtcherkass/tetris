#include "settingsdlg.h"
#include "ui_settingsdlg.h"
#include <tetrisdata.h>
#include <iostream>

/////////////////////////////////
SettingsDB::SettingsDB()
{
   mSpeed = 0;
   mChangeColor = true;
   int size = sizeof(mShapeTypes)/sizeof(bool);
   for (int i = 0; i < size; i++) mShapeTypes[i] = true;
}

void SettingsDB::toString(string& str)
{
    int i = 0;
    for (; i < TRX_NUM_OF_SHAPE_TYPES; i++)
    {
        str.push_back((char)mShapeTypes[i] + '0');
    }

    str.push_back((char)mChangeColor + '0');
    str.push_back((char)mSpeed + '0');
    str.push_back((char)0);
}

void SettingsDB::fromString(const char* str)
{
    int i = 0;
    for (; i < TRX_NUM_OF_SHAPE_TYPES; i++)
    {
        mShapeTypes[i] = (bool)(str[i] - '0');
    }

    mChangeColor = (bool)(str[i] - '0');
    mSpeed = (int)(str[i + 1] - '0');
}

///////////////////////////////////////////////////////
/////////////////////////////////
SettingsDlg::SettingsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsDlg)
{
    ui->setupUi(this);
    init();
}

SettingsDlg::~SettingsDlg()
{
    delete ui;
}

QCheckBox* SettingsDlg::getChkBox(int idx)
{
    if (idx == 0) return (ui->shapeCheckBox_0);
    if (idx == 1) return (ui->shapeCheckBox_1);
    if (idx == 2) return (ui->shapeCheckBox_2);
    if (idx == 3) return (ui->shapeCheckBox_3);
    if (idx == 4) return (ui->shapeCheckBox_4);
    if (idx == 5) return (ui->shapeCheckBox_5);
    if (idx == 6) return (ui->shapeCheckBox_6);
    return NULL;
}

void SettingsDlg::init()
{
    ui->spinBox->setValue(getSettingsDB()->mSpeed);
    ui->changeColorChkBox->setChecked(getSettingsDB()->mChangeColor);

    for (int i = 0; i < TRX_NUM_OF_SHAPE_TYPES; i++)
    {
        getChkBox(i)->setChecked(getSettingsDB()->mShapeTypes[i]);
        string img = "shape_";
        img += to_string(i) + ".png";
        setChkBoxIcon(img.c_str(), getChkBox(i));
    }
}

void SettingsDlg::setChkBoxIcon(const char* iconName, QCheckBox* box)
{
    QPixmap pix(iconName);
    QIcon icon(pix);
    box->setIcon(icon);
}

void SettingsDlg::on_SettingsCancelPB_clicked()
{
    close();
}

void SettingsDlg::on_SettingOkPB_clicked()
{
    getSettingsDB()->mSpeed = ui->spinBox->value();
    getSettingsDB()->mChangeColor = ui->changeColorChkBox->isChecked();

    for (int i = 0; i < TRX_NUM_OF_SHAPE_TYPES; i++)
    {
        getSettingsDB()->mShapeTypes[i] = getChkBox(i)->isChecked();
    }

    close();
}

//////////////////////////////////////

SettingsDB* getSettingsDB()
{
    static SettingsDB* s_settings = NULL;
    if (s_settings == NULL)
    {
        s_settings = new SettingsDB;
    }
    return s_settings;
}

void SettingsDlg::updateOkBtnAccess()
{
    int selectedShapesNum = 0;
    for (int i = 0; i < TRX_NUM_OF_SHAPE_TYPES; i++)
    {
        if (getChkBox(i)->isChecked()) ++selectedShapesNum;
    }

    bool okBtnDisableState = (selectedShapesNum < 4) ? true : false;
    ui->SettingOkPB->setDisabled(okBtnDisableState);
}
