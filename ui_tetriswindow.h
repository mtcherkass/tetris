/********************************************************************************
** Form generated from reading UI file 'tetriswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TETRISWINDOW_H
#define UI_TETRISWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TetrisWindow
{
public:
    QAction *actionNew_game;
    QAction *actionSettings;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QPushButton *newGamePB;
    QPushButton *settingsPB;
    QLabel *scoreLable;
    QLabel *nextShapeImgLbl;
    QLabel *nextShapeLbl;
    QLabel *bobSpogLbl;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TetrisWindow)
    {
        if (TetrisWindow->objectName().isEmpty())
            TetrisWindow->setObjectName(QStringLiteral("TetrisWindow"));
        TetrisWindow->resize(520, 637);
        actionNew_game = new QAction(TetrisWindow);
        actionNew_game->setObjectName(QStringLiteral("actionNew_game"));
        actionSettings = new QAction(TetrisWindow);
        actionSettings->setObjectName(QStringLiteral("actionSettings"));
        actionExit = new QAction(TetrisWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionAbout = new QAction(TetrisWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        centralWidget = new QWidget(TetrisWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 80, 503, 503));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        newGamePB = new QPushButton(centralWidget);
        newGamePB->setObjectName(QStringLiteral("newGamePB"));
        newGamePB->setGeometry(QRect(10, 0, 80, 80));
        QIcon icon;
        icon.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/start.png"), QSize(), QIcon::Normal, QIcon::Off);
        newGamePB->setIcon(icon);
        newGamePB->setIconSize(QSize(70, 70));
        settingsPB = new QPushButton(centralWidget);
        settingsPB->setObjectName(QStringLiteral("settingsPB"));
        settingsPB->setGeometry(QRect(90, 0, 80, 80));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../build-Tetris-Desktop_Qt_5_8_0_MinGW_32bit-Debug/debug/settings.png"), QSize(), QIcon::Normal, QIcon::Off);
        settingsPB->setIcon(icon1);
        settingsPB->setIconSize(QSize(68, 68));
        scoreLable = new QLabel(centralWidget);
        scoreLable->setObjectName(QStringLiteral("scoreLable"));
        scoreLable->setGeometry(QRect(210, 10, 101, 51));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        scoreLable->setFont(font);
        nextShapeImgLbl = new QLabel(centralWidget);
        nextShapeImgLbl->setObjectName(QStringLiteral("nextShapeImgLbl"));
        nextShapeImgLbl->setGeometry(QRect(410, 10, 51, 51));
        nextShapeLbl = new QLabel(centralWidget);
        nextShapeLbl->setObjectName(QStringLiteral("nextShapeLbl"));
        nextShapeLbl->setGeometry(QRect(320, 20, 81, 31));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        nextShapeLbl->setFont(font1);
        bobSpogLbl = new QLabel(centralWidget);
        bobSpogLbl->setObjectName(QStringLiteral("bobSpogLbl"));
        bobSpogLbl->setGeometry(QRect(464, 10, 45, 50));
        TetrisWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TetrisWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 520, 21));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        TetrisWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TetrisWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TetrisWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TetrisWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TetrisWindow->setStatusBar(statusBar);

        menuBar->addAction(menuMenu->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionNew_game);
        menuMenu->addAction(actionSettings);
        menuMenu->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(TetrisWindow);

        QMetaObject::connectSlotsByName(TetrisWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TetrisWindow)
    {
        TetrisWindow->setWindowTitle(QApplication::translate("TetrisWindow", "Tetris", Q_NULLPTR));
        actionNew_game->setText(QApplication::translate("TetrisWindow", "New game", Q_NULLPTR));
        actionSettings->setText(QApplication::translate("TetrisWindow", "Settings", Q_NULLPTR));
        actionExit->setText(QApplication::translate("TetrisWindow", "Exit", Q_NULLPTR));
        actionAbout->setText(QApplication::translate("TetrisWindow", "About", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        newGamePB->setToolTip(QApplication::translate("TetrisWindow", "New Game", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        newGamePB->setText(QString());
#ifndef QT_NO_TOOLTIP
        settingsPB->setToolTip(QApplication::translate("TetrisWindow", "Settings ..", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        settingsPB->setText(QString());
        scoreLable->setText(QApplication::translate("TetrisWindow", "Score: 0", Q_NULLPTR));
        nextShapeImgLbl->setText(QString());
        nextShapeLbl->setText(QApplication::translate("TetrisWindow", "Next Shape :", Q_NULLPTR));
        bobSpogLbl->setText(QString());
        menuMenu->setTitle(QApplication::translate("TetrisWindow", "Game", Q_NULLPTR));
        menuHelp->setTitle(QApplication::translate("TetrisWindow", "Help", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TetrisWindow: public Ui_TetrisWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TETRISWINDOW_H
