#include <tetrisdata.h>

const int TTX_TIMER_DELAY = 200;

bool Unit::isInside(const Unit& unit) const
{
    if ((unit.x() + UNIT_WIDTH > x()) && // from left side (X check)
        (unit.x() < x() + UNIT_WIDTH))  // from right side (X check)
         {
            if (unit.y() > y() - UNIT_HEIGHT && // from bottom side (Y check)
                unit.y() - UNIT_HEIGHT < y())  // from top side (Y check)
            return true;
         }

    return false;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
Shape::Shape(int shapeType)
{
    switch(shapeType)
    {
    case 0:
    {
    // 0 * 0
    // * * *
    // 0 0 0
        setMovingObj(false, true, false,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 1:
    {
        // 0 0 *
        // * * *
        // 0 0 0
        setMovingObj(false, false, true,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 2:
    {
        // * 0 *
        // * * *
        // 0 0 0
        setMovingObj(true, false, true,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 3:
    {
        // * 0 0
        // * * *
        // 0 0 0
        setMovingObj(true, false, false,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 4:
    {
        // 0 0 0
        // * * *
        // 0 0 0
        setMovingObj(false, false, false,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 5:
    {
        // * * *
        // * * *
        // 0 0 0
        setMovingObj(true, true, true,
                     true, true, true,
                     false, false, false);
        break;
    }
    case 6:
    {
        // 0 * 0
        // * * *
        // * 0 *
        setMovingObj(false, true, false,
                     true, true, true,
                     true, false, true);
        break;
    }

    }
}

void Shape::setMovingObj(bool a00, bool a01, bool a02,
                         bool a10, bool a11, bool a12,
                         bool a20, bool a21, bool a22)
{
    mUnitsMap[0][0] = a00;
    mUnitsMap[0][1] = a01;
    mUnitsMap[0][2] = a02;
    mUnitsMap[1][0] = a10;
    mUnitsMap[1][1] = a11;
    mUnitsMap[1][2] = a12;
    mUnitsMap[2][0] = a20;
    mUnitsMap[2][1] = a21;
    mUnitsMap[2][2] = a22;
}

int Shape::getRandomShapeType()
{
    bool* shapeTypes = getSettingsDB()->getShapeTypes();
    int shapeTypesNum = getSettingsDB()->getShapeTypesNum();
    int shapeType = -1;

    while (shapeType == -1)
    {
        int randType = rand() % shapeTypesNum;
        if (shapeTypes[randType])
        {
            shapeType = randType;
        }
    }

    return shapeType;
}

///////////////////////////////////////////////////////
///////////////////////////////////////////////////////
///
void UnitUtil::updateUnitsCoordLoc(MoveDirection direction, vector<Unit>& units)
{
    int size = units.size();

    QPoint updateDelta;
    UnitUtil::getMoveDelta(direction, updateDelta);

    for (int i = 0; i < size; i++)
    {
        units[i].setX(units[i].x() + updateDelta.x());
        units[i].setY(units[i].y() + updateDelta.y());
    }
}

void UnitUtil::getMoveDelta(MoveDirection direction, QPoint& delta)
{
  switch (direction)
  {
  case MOVE_ON:
      delta.setX(0);
      delta.setY(MOVE_VAL);
      break;
  case MOVE_RIGHT:
      delta.setX(UNIT_WIDTH);
      delta.setY(0);
      break;
  case MOVE_LEFT:
      delta.setX(-UNIT_WIDTH);
      delta.setY(0);
      break;
  default:
      showMsg("getMoveDelta() Error", "Wrong direction value");
      break;
  }
}

/////////////////////////////////
int UnitUtil::getTimerDelayVal(int score)
{
    int settingsSpeed = getSettingsDB()->getSpeed();
    int scoreSpeed = score / 3;
    int delayVal = TTX_TIMER_DELAY - (settingsSpeed + scoreSpeed) * 10;

    return (delayVal > 20) ? delayVal : 20;
}


UnitUtil* getUtil ()
{
    static UnitUtil* sUtil = nullptr;

    if (sUtil == nullptr)
    {
        sUtil = new UnitUtil();
    };

    return sUtil;
}
