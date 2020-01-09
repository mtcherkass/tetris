/*
 *  tetriswindow.h
 */

#ifndef TETRISWINDOW_H
#define TETRISWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QPixmap>
#include <tetrisdata.h>
#include <settingsdlg.h>


namespace Ui {
class TetrisWindow;
}

//**********************************
class UnitUI
{
    QGraphicsRectItem *mGraphRect;
    QGraphicsScene *mScene;

public:
    UnitUI(const Unit& coord, QGraphicsScene *scene);
    ~UnitUI();
    QGraphicsScene* getScene() { return mScene; }
    QGraphicsRectItem* getRect() { return mGraphRect; }
    void moveUnit(const QPoint& updateDelta);
    void updateColor();
};

//**********************************
class UnitEntity
{
    UnitUI* mUnitUi;
    Unit mUnitCoord;

public:
    UnitEntity(UnitUI* unit_ui, const Unit& unit_coord) :
        mUnitUi(unit_ui), mUnitCoord(unit_coord) { }
    ~UnitEntity();
    const Unit& getCoord() { return mUnitCoord; }
    friend class UnitsManager;
};

typedef UnitUI* UnitPtr;
//**********************************
class ShapeUI
{
    QGraphicsScene *mScene;
    UnitPtr mUnits[3][3];
    int mXPos;
    int mYPos;
    int mCurrShapeType;
    int mNextShapeType;

    void cleanUnits();
    void getCoord(int xPos, int yPos, Unit& coord);


public:
    ShapeUI(QGraphicsScene *scene);
    ~ShapeUI();
    void move(MoveDirection direction);
    void rotateData();
    void rotateDataBack() { for (int i = 0; i < 3; i++) rotateData(); }
    void rotateUI();
    void getUnitsCoord(vector<Unit>& unitsArr);
    void addScreenUnits(vector<UnitEntity*>& unitsArr);
    void generateShape();
    void getNextShapeTypeImage(string& img_name);
};

///////////////////////////////////////////////
/// The UnitsManager class
///
class UnitsManager
{
    vector<UnitEntity*> mScreenUnits;
    bool removeFirstInArr (int height_val);

public:
    void addMovingShapeToDB(ShapeUI* shape);
    bool isUnitCollapse(const Unit& unit) const;
    void removeFullRow(int fullRowHeight);
    void moveOnRemovedFullRow(int fullRowHeight);
    int getFullRowHeight ();
    void clean();
    void updateUnitsColor();
};


//**********************************
class TetrisWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TetrisWindow(QWidget *parent = 0);
    ~TetrisWindow();
    static QColor getBrushColor() { return sBrushColor; }
    static QColor getPenColor() { return sPenColor; }


public slots:
    void nextMoveCB();

private slots:
    void on_newGamePB_clicked();
    void on_settingsPB_clicked();
    void on_About_clicked();
    void on_Exit_clicked();

protected:
    void closeEvent(QCloseEvent *) override;

private:
    bool isLegalLocation(vector<Unit>& unitsArr);
    bool isUnitPosOutOfScreen(const Unit& unitPos);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    bool moveAction(MoveDirection direction);
    void rotateAction();
    void moveDownBottom();
    void endGame();
    void cleanScreen();
    void updateScoreLabel();
    void showNextShapeImg();
    void showBobSpogImg(bool);
    void showScore();
    void pause();
    int getTimerDelayVal();
    void changeUnitsColor();
    void initMenu();
    void loadSettings();
    void saveSettings();
    void setBtnIcon(const char* iconName, QPushButton* pb);
    static void randUnitColor();

    Ui::TetrisWindow *ui;
    QGraphicsScene *mScene;
    ShapeUI* mMovingShape;
    UnitsManager mUManager;
    QTimer *mTimer;
    int mScore;
    bool mGameIsRunning;
    bool mBobSpogShown;
    static QColor sPenColor;
    static QColor sBrushColor;
};

#endif // TETRISWINDOW_H
