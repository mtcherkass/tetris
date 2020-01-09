/********************************************************************************
** Form generated from reading UI file 'urahdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_URAHDIALOG_H
#define UI_URAHDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_UrahDialog
{
public:
    QLabel *label;

    void setupUi(QDialog *UrahDialog)
    {
        if (UrahDialog->objectName().isEmpty())
            UrahDialog->setObjectName(QStringLiteral("UrahDialog"));
        UrahDialog->resize(152, 82);
        UrahDialog->setAutoFillBackground(false);
        label = new QLabel(UrahDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 151, 81));
        QFont font;
        font.setFamily(QStringLiteral("Mongolian Baiti"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(UrahDialog);

        QMetaObject::connectSlotsByName(UrahDialog);
    } // setupUi

    void retranslateUi(QDialog *UrahDialog)
    {
        UrahDialog->setWindowTitle(QString());
        label->setText(QApplication::translate("UrahDialog", "YES !!!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class UrahDialog: public Ui_UrahDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_URAHDIALOG_H
