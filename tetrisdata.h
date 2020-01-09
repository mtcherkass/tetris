/*
 *  tetrisdata.h
 */

#ifndef TETRISDATA_H
#define TETRISDATA_H

#include <settingsdlg.h>
#include <QtCore>
#include <QPoint>
#include <vector>

using namespace std;

// {0,0} coordinate located in Left - Bottom corner.
// Therefore all the coordinate values are positive

const int UNIT_HEIGHT = 20;
const int UNIT_WIDTH = 20;
const int SCREEN_WIDTH = 500;
const int SCREEN_HEIGHT = 500;
const int MOVE_VAL = UNIT_HEIGHT / 2;

enum MoveDirection
{
    MOVE_ON,
    MOVE_RIGHT,
    MOVE_LEFT
};

class Unit
{
    int mX;
    int mY;

public:
    Unit() : mX(0), mY(0) { }
    void set(int x, int y) { mX = x; mY = y; }
    void setX(int x) { mX = x; }
    void setY(int y) { mY = y; }
    int x() const { return mX; }
    int y() const { return mY; }
    bool isInside(const Unit& unit) const;
    Unit& operator=(const Unit& unit) { set(unit.mX, unit.mY); return *this; }
};


/////////////////////////////////////////////
/// The Shape class
///
class Shape
{
    bool mUnitsMap[3][3];

    void setMovingObj(bool,bool,bool,bool,bool,bool,bool,bool,bool);

public:
    Shape(int shapeType);
    bool hasUnitInPos(int x, int y) { return mUnitsMap[y][x]; }
    static int getRandomShapeType();
};


///////////////////////////////////////////////
/// The UnitsManager class
///
class UnitUtil
{
public:
    static void updateUnitsCoordLoc(MoveDirection direction, vector<Unit>& units);
    static void getMoveDelta(MoveDirection direction, QPoint& delta);
    int getTimerDelayVal(int score);
};

void showMsg(const char* title, const char* msg);
UnitUtil* getUtil ();

#endif // TETRISDATA_H
