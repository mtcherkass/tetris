/********************************************************************************
** Form generated from reading UI file 'settingsdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSDLG_H
#define UI_SETTINGSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_SettingsDlg
{
public:
    QLabel *shapesLabel;
    QCheckBox *shapeCheckBox_0;
    QCheckBox *shapeCheckBox_1;
    QCheckBox *shapeCheckBox_2;
    QCheckBox *shapeCheckBox_3;
    QCheckBox *shapeCheckBox_4;
    QCheckBox *shapeCheckBox_5;
    QCheckBox *shapeCheckBox_6;
    QLabel *SpeedLabel;
    QSpinBox *spinBox;
    QPushButton *SettingOkPB;
    QPushButton *SettingsCancelPB;
    QFrame *line0;
    QFrame *line;
    QCheckBox *changeColorChkBox;
    QFrame *line_2;

    void setupUi(QDialog *SettingsDlg)
    {
        if (SettingsDlg->objectName().isEmpty())
            SettingsDlg->setObjectName(QStringLiteral("SettingsDlg"));
        SettingsDlg->resize(562, 415);
        shapesLabel = new QLabel(SettingsDlg);
        shapesLabel->setObjectName(QStringLiteral("shapesLabel"));
        shapesLabel->setGeometry(QRect(30, 10, 281, 31));
        QFont font;
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        shapesLabel->setFont(font);
        shapeCheckBox_0 = new QCheckBox(SettingsDlg);
        shapeCheckBox_0->setObjectName(QStringLiteral("shapeCheckBox_0"));
        shapeCheckBox_0->setGeometry(QRect(30, 50, 70, 61));
        QIcon icon(QIcon::fromTheme(QStringLiteral("shape_0.png")));
        shapeCheckBox_0->setIcon(icon);
        shapeCheckBox_0->setIconSize(QSize(50, 50));
        shapeCheckBox_0->setChecked(true);
        shapeCheckBox_1 = new QCheckBox(SettingsDlg);
        shapeCheckBox_1->setObjectName(QStringLiteral("shapeCheckBox_1"));
        shapeCheckBox_1->setGeometry(QRect(130, 50, 70, 61));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_1.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_1->setIcon(icon1);
        shapeCheckBox_1->setIconSize(QSize(50, 50));
        shapeCheckBox_1->setChecked(true);
        shapeCheckBox_2 = new QCheckBox(SettingsDlg);
        shapeCheckBox_2->setObjectName(QStringLiteral("shapeCheckBox_2"));
        shapeCheckBox_2->setGeometry(QRect(240, 50, 70, 61));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_2->setIcon(icon2);
        shapeCheckBox_2->setIconSize(QSize(50, 50));
        shapeCheckBox_2->setChecked(true);
        shapeCheckBox_3 = new QCheckBox(SettingsDlg);
        shapeCheckBox_3->setObjectName(QStringLiteral("shapeCheckBox_3"));
        shapeCheckBox_3->setGeometry(QRect(350, 54, 70, 51));
        QIcon icon3;
        icon3.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_3.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_3->setIcon(icon3);
        shapeCheckBox_3->setIconSize(QSize(50, 50));
        shapeCheckBox_3->setChecked(true);
        shapeCheckBox_4 = new QCheckBox(SettingsDlg);
        shapeCheckBox_4->setObjectName(QStringLiteral("shapeCheckBox_4"));
        shapeCheckBox_4->setGeometry(QRect(460, 55, 70, 51));
        QIcon icon4;
        icon4.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_4.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_4->setIcon(icon4);
        shapeCheckBox_4->setIconSize(QSize(50, 50));
        shapeCheckBox_4->setChecked(true);
        shapeCheckBox_5 = new QCheckBox(SettingsDlg);
        shapeCheckBox_5->setObjectName(QStringLiteral("shapeCheckBox_5"));
        shapeCheckBox_5->setGeometry(QRect(30, 140, 70, 51));
        QIcon icon5;
        icon5.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_5.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_5->setIcon(icon5);
        shapeCheckBox_5->setIconSize(QSize(50, 50));
        shapeCheckBox_5->setChecked(true);
        shapeCheckBox_6 = new QCheckBox(SettingsDlg);
        shapeCheckBox_6->setObjectName(QStringLiteral("shapeCheckBox_6"));
        shapeCheckBox_6->setGeometry(QRect(130, 140, 71, 51));
        shapeCheckBox_6->setContextMenuPolicy(Qt::DefaultContextMenu);
        QIcon icon6;
        icon6.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_6.png"), QSize(), QIcon::Normal, QIcon::Off);
        shapeCheckBox_6->setIcon(icon6);
        shapeCheckBox_6->setIconSize(QSize(50, 50));
        shapeCheckBox_6->setChecked(true);
        SpeedLabel = new QLabel(SettingsDlg);
        SpeedLabel->setObjectName(QStringLiteral("SpeedLabel"));
        SpeedLabel->setGeometry(QRect(30, 238, 91, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font1.setPointSize(12);
        SpeedLabel->setFont(font1);
        spinBox = new QSpinBox(SettingsDlg);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 239, 42, 31));
        spinBox->setMaximum(15);
        spinBox->setValue(0);
        SettingOkPB = new QPushButton(SettingsDlg);
        SettingOkPB->setObjectName(QStringLiteral("SettingOkPB"));
        SettingOkPB->setGeometry(QRect(320, 370, 75, 31));
        SettingsCancelPB = new QPushButton(SettingsDlg);
        SettingsCancelPB->setObjectName(QStringLiteral("SettingsCancelPB"));
        SettingsCancelPB->setGeometry(QRect(440, 370, 75, 31));
        line0 = new QFrame(SettingsDlg);
        line0->setObjectName(QStringLiteral("line0"));
        line0->setGeometry(QRect(30, 210, 501, 20));
        line0->setLineWidth(3);
        line0->setFrameShape(QFrame::HLine);
        line0->setFrameShadow(QFrame::Sunken);
        line = new QFrame(SettingsDlg);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(30, 280, 501, 20));
        line->setLineWidth(3);
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        changeColorChkBox = new QCheckBox(SettingsDlg);
        changeColorChkBox->setObjectName(QStringLiteral("changeColorChkBox"));
        changeColorChkBox->setGeometry(QRect(-70, 300, 221, 31));
        QFont font2;
        font2.setPointSize(12);
        changeColorChkBox->setFont(font2);
        changeColorChkBox->setLayoutDirection(Qt::RightToLeft);
        changeColorChkBox->setIconSize(QSize(20, 20));
        line_2 = new QFrame(SettingsDlg);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(30, 342, 501, 20));
        line_2->setLineWidth(3);
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        retranslateUi(SettingsDlg);

        QMetaObject::connectSlotsByName(SettingsDlg);
    } // setupUi

    void retranslateUi(QDialog *SettingsDlg)
    {
        SettingsDlg->setWindowTitle(QApplication::translate("SettingsDlg", "Settings", Q_NULLPTR));
        shapesLabel->setText(QApplication::translate("SettingsDlg", "Select playing shapes (more than 3):", Q_NULLPTR));
        shapeCheckBox_0->setText(QString());
        shapeCheckBox_1->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        shapeCheckBox_2->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        shapeCheckBox_3->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        shapeCheckBox_4->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        shapeCheckBox_5->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        shapeCheckBox_6->setText(QApplication::translate("SettingsDlg", "CheckBox", Q_NULLPTR));
        SpeedLabel->setText(QApplication::translate("SettingsDlg", "Speed level:", Q_NULLPTR));
        SettingOkPB->setText(QApplication::translate("SettingsDlg", "OK", Q_NULLPTR));
        SettingsCancelPB->setText(QApplication::translate("SettingsDlg", "Cancel", Q_NULLPTR));
        changeColorChkBox->setText(QApplication::translate("SettingsDlg", "Change color ", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SettingsDlg: public Ui_SettingsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSDLG_H
