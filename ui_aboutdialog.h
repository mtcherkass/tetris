/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QPushButton *okPB;
    QLabel *titleLabel;
    QLabel *authorLabel;
    QLabel *leftImgLabel;
    QLabel *rightImgLabel;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(400, 178);
        okPB = new QPushButton(AboutDialog);
        okPB->setObjectName(QStringLiteral("okPB"));
        okPB->setGeometry(QRect(160, 130, 75, 23));
        titleLabel = new QLabel(AboutDialog);
        titleLabel->setObjectName(QStringLiteral("titleLabel"));
        titleLabel->setGeometry(QRect(140, 10, 111, 31));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignCenter);
        authorLabel = new QLabel(AboutDialog);
        authorLabel->setObjectName(QStringLiteral("authorLabel"));
        authorLabel->setGeometry(QRect(106, 50, 181, 20));
        authorLabel->setAlignment(Qt::AlignCenter);
        leftImgLabel = new QLabel(AboutDialog);
        leftImgLabel->setObjectName(QStringLiteral("leftImgLabel"));
        leftImgLabel->setGeometry(QRect(40, 20, 47, 41));
        leftImgLabel->setPixmap(QPixmap(QString::fromUtf8("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_1.png")));
        rightImgLabel = new QLabel(AboutDialog);
        rightImgLabel->setObjectName(QStringLiteral("rightImgLabel"));
        rightImgLabel->setGeometry(QRect(310, 20, 51, 41));
        rightImgLabel->setPixmap(QPixmap(QString::fromUtf8("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/shape_3.png")));

        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "Dialog", Q_NULLPTR));
        okPB->setText(QApplication::translate("AboutDialog", "OK", Q_NULLPTR));
        titleLabel->setText(QApplication::translate("AboutDialog", "TETRIS", Q_NULLPTR));
        authorLabel->setText(QApplication::translate("AboutDialog", "Created by Moti Tcherkas", Q_NULLPTR));
        leftImgLabel->setText(QString());
        rightImgLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
