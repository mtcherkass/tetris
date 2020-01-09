/*
 *  settingsdlg.h
 */

#ifndef SETTINGSDLG_H
#define SETTINGSDLG_H

#include <QDialog>
#include <QCheckBox>
#include <vector>
using namespace std;

#define TRX_NUM_OF_SHAPE_TYPES 7
#define TRX_MIN_SHAPE_TYPES_NUM 4

namespace Ui {
class SettingsDlg;
}

class SettingsDB
{
    bool mShapeTypes[TRX_NUM_OF_SHAPE_TYPES];
    int mSpeed;
    bool mChangeColor;

public:
    SettingsDB();
    int getSpeed() { return mSpeed; }
    void incSpeed() { ++mSpeed; }
    bool* getShapeTypes() { return mShapeTypes; }
    int getShapeTypesNum() { return TRX_NUM_OF_SHAPE_TYPES; }
    bool shouldChangeColor() { return mChangeColor; }
    friend class SettingsDlg;

    void toString(string&);
    void fromString(const char* );
};

class SettingsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsDlg(QWidget* parent = 0);
    ~SettingsDlg();

private slots:
    void on_SettingsCancelPB_clicked();
    void on_SettingOkPB_clicked();

    void on_shapeCheckBox_0_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_1_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_2_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_3_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_4_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_5_stateChanged(int ) { updateOkBtnAccess(); }
    void on_shapeCheckBox_6_stateChanged(int ) { updateOkBtnAccess(); }

private:
    void init();
    QCheckBox* getChkBox(int idx);
    void updateOkBtnAccess();
    void setChkBoxIcon(const char* iconName, QCheckBox* box);

    Ui::SettingsDlg *ui;
    SettingsDB* mSettings;
};

SettingsDB* getSettingsDB();

#endif // SETTINGSDLG_H
