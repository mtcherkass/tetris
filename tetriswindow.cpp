#include <tetriswindow.h>
#include <ui_tetriswindow.h>
#include <iostream>
#include <settingsdlg.h>
#include <aboutdialog.h>
#include <fstream>

QColor TetrisWindow::sBrushColor = Qt::green;
QColor TetrisWindow::sPenColor = Qt::darkGreen;
const char* BobSpogImgName = "yesSmall";
const char* SETTINGS_DATA_FILE = "settings.dat";

/////////////////////////////////
TetrisWindow::TetrisWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TetrisWindow), mMovingShape(NULL), mScore(0),
    mGameIsRunning(false), mBobSpogShown(false)
{
    ui->setupUi(this);

    mScene = new QGraphicsScene(ui->graphicsView);
    ui->graphicsView->setScene(mScene);
    mScene->setSceneRect(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    loadSettings();
    initMenu();

    // show icons for buttons
    setBtnIcon("start.png",ui->newGamePB);
    setBtnIcon("settings.png", ui->settingsPB);

    // set Timer
    mTimer = new QTimer(this);
    connect(mTimer, SIGNAL(timeout()), this, SLOT(nextMoveCB()));
}

/////////////////////////////////
TetrisWindow::~TetrisWindow()
{
    delete mMovingShape;
    delete mScene;
    delete ui;
}

/////////////////////////////////
void TetrisWindow::setBtnIcon(const char* iconName, QPushButton* pb)
{
    QPixmap pix(iconName);
    QIcon icon(pix);
    pb->setIcon(icon);
}

/////////////////////////////////
void TetrisWindow::initMenu()
{
    connect(ui->actionAbout, &QAction::triggered, this,
            &TetrisWindow::on_About_clicked);

    connect(ui->actionExit, &QAction::triggered, this,
            &TetrisWindow::on_Exit_clicked);

    connect(ui->actionNew_game, &QAction::triggered, this,
            &TetrisWindow::on_newGamePB_clicked);

    connect(ui->actionSettings, &QAction::triggered, this,
            &TetrisWindow::on_settingsPB_clicked);
}

/////////////////////////////////
void TetrisWindow::loadSettings()
{
    ifstream settingsFile(SETTINGS_DATA_FILE);

    if (settingsFile)
    {
        // get length of file:
        settingsFile.seekg (0, settingsFile.end);
        int length = settingsFile.tellg();
        settingsFile.seekg (0, settingsFile.beg);

        char *buffer = new char [length];
        settingsFile.read (buffer,length);

        if (settingsFile)
        {
            getSettingsDB()->fromString(buffer);
        }

        delete[] buffer;
    }
}

/////////////////////////////////
void TetrisWindow::saveSettings()
{
    ofstream settingsFile;
    settingsFile.open (SETTINGS_DATA_FILE, ios::out | ios::trunc );
    string data;
    getSettingsDB()->toString(data);
    settingsFile << data;
}

/////////////////////////////////
bool TetrisWindow::isUnitPosOutOfScreen(const Unit& unitPos)
{
    if (unitPos.x() < 0 ||
        unitPos.x() + UNIT_WIDTH > SCREEN_WIDTH ||
        unitPos.y() < 0 ||
        unitPos.y() + UNIT_HEIGHT > SCREEN_HEIGHT)
        return true;

    return false;
}

/////////////////////////////////
bool TetrisWindow::isLegalLocation(vector<Unit>& unitsArr)
{
    int size = unitsArr.size();
    for (int i = 0; i < size; i++)
    {
      if (isUnitPosOutOfScreen(unitsArr[i]))
          return false;

      if (mUManager.isUnitCollapse(unitsArr[i]))
          return false;
    }

    return true;
}

/////////////////////////////////
/// Callback for move down
/////////////////////////////////
void TetrisWindow::nextMoveCB()
{
    moveAction(MOVE_ON);
}

/////////////////////////////////
void TetrisWindow::moveDownBottom()
{
    while (moveAction(MOVE_ON)) { }
}

/////////////////////////////////
/// Move the shape to some direction (not rotation)
/////////////////////////////////
bool TetrisWindow::moveAction(MoveDirection direction)
{
    if (!mGameIsRunning)
        return false;

    bool actionDone = false;
    vector<Unit> unitsArr;
    mMovingShape->getUnitsCoord (unitsArr);
    getUtil()->updateUnitsCoordLoc(direction, unitsArr);

    if (isLegalLocation(unitsArr))
    {
        mMovingShape->move(direction);
        actionDone = true;
    }
    else if (direction == MOVE_ON) // reached bottom, need to restart the Shape
    {
        mUManager.addMovingShapeToDB(mMovingShape);
        showBobSpogImg(false);

        // In case we have full row/rows we need to remove it and
        // move down the rows in top
        int fullRowHeight = mUManager.getFullRowHeight();
        while (fullRowHeight > 0)
        {
            if (getSettingsDB()->shouldChangeColor())
            {
                randUnitColor();
                mUManager.updateUnitsColor();
            }

            mUManager.removeFullRow(fullRowHeight);
            mUManager.moveOnRemovedFullRow(fullRowHeight);

            fullRowHeight = mUManager.getFullRowHeight();
            ++mScore;

            showScore();
            showBobSpogImg(true);
        }

        // restart the shape
        mMovingShape->generateShape();
        showNextShapeImg();

        // check for end of game
        vector<Unit> generatedUnitsArr;
        mMovingShape->getUnitsCoord (generatedUnitsArr);

        if (!isLegalLocation(generatedUnitsArr))
        {
            endGame();
        }
    }

    this->repaint();
    qApp->processEvents();
    return actionDone;
}

/////////////////////////////////
void TetrisWindow::endGame()
{
    mTimer->stop();
    mGameIsRunning = false;
    showMsg("Game Over", "Thank you for playing");
}

/////////////////////////////////
/// Rotate the shape
/////////////////////////////////
void TetrisWindow::rotateAction()
{
    vector<Unit> unitsArr;
    mMovingShape->rotateData();
    mMovingShape->getUnitsCoord (unitsArr);
    mMovingShape->rotateDataBack();

    if (isLegalLocation(unitsArr))
    {
        mMovingShape->rotateUI();
        mMovingShape->rotateData();
    }

    this->repaint();
    qApp->processEvents();
}

/////////////////////////////////
void TetrisWindow::keyReleaseEvent( QKeyEvent *key )
{
    if (!mGameIsRunning)
        return;

    switch (key->key())
    {
    case Qt::Key_Right:
        moveAction(MOVE_RIGHT);
        break;
    case Qt::Key_Left:
        moveAction(MOVE_LEFT);
        break;
    case Qt::Key_Up:
        rotateAction();
        break;
    case Qt::Key_Down:
        moveDownBottom();
        break;
    }
}

/////////////////////////////////
void TetrisWindow::keyPressEvent( QKeyEvent *key )
{
    switch (key->key())
    {
    case Qt::Key_Escape:
        pause();
        break;
    }
}

/////////////////////////////////
void TetrisWindow::pause()
{
    if (!mGameIsRunning) // continue game
    {
        mGameIsRunning = true;
        mTimer->start(getUtil()->getTimerDelayVal(mScore));
    }
    else  // pause
    {
        mGameIsRunning = false;
        mTimer->stop();
    }
}

/////////////////////////////////
void TetrisWindow::cleanScreen()
{
    mUManager.clean();
    delete mMovingShape;
    mMovingShape = NULL;
    mScore = 0;
    showScore();
}

/////////////////////////////////
void TetrisWindow::on_newGamePB_clicked()
{
    if (mMovingShape != NULL) // if not start of game
    {
        cleanScreen();
    }

    mGameIsRunning = true;
    mMovingShape = new ShapeUI(mScene);
    mTimer->start(getUtil()->getTimerDelayVal(mScore));
    showNextShapeImg();
}

/////////////////////////////////
void TetrisWindow::showNextShapeImg()
{
    string img_name;
    mMovingShape->getNextShapeTypeImage(img_name);
    QPixmap image(img_name.c_str());

    ui->nextShapeImgLbl->setPixmap(image);

    if (!ui->nextShapeLbl->isVisible())
        ui->nextShapeLbl->setVisible(true);
}

/////////////////////////////////
void TetrisWindow::showBobSpogImg(bool show)
{
    if (show && !mBobSpogShown)
    {
        mBobSpogShown = true;
        QPixmap bobSpogImage(BobSpogImgName);
        ui->bobSpogLbl->setPixmap(bobSpogImage);
    }

    if (!show && mBobSpogShown)
    {
        mBobSpogShown = false;
        QPixmap bobSpogImage("");
        ui->bobSpogLbl->setPixmap(bobSpogImage);
    }
}

/////////////////////////////////
void TetrisWindow::showScore()
{
    string scoreLabel = "Score: " + to_string(mScore);
    ui->scoreLable->setText(scoreLabel.c_str());
}

/////////////////////////////////
void TetrisWindow::changeUnitsColor()
{
    mTimer->stop();
    randUnitColor();
    mUManager.updateUnitsColor();
    mTimer->start(getUtil()->getTimerDelayVal(mScore));
}

/////////////////////////////////
void TetrisWindow::on_settingsPB_clicked()
{
    bool shouldPause = (mMovingShape != NULL) && mTimer->isActive();
    if (shouldPause)
        pause(); // set pause

    SettingsDlg settingsDlg;
    settingsDlg.setModal(true);
    settingsDlg.exec();

    if (shouldPause)
        pause(); // release pause
}

/////////////////////////////////
void TetrisWindow::on_About_clicked()
{
    AboutDialog aboutDlg;
    aboutDlg.setModal(true);
    aboutDlg.exec();
}

/////////////////////////////////
void TetrisWindow::on_Exit_clicked()
{
    close();
}

/////////////////////////////////
void TetrisWindow::randUnitColor()
{
    static QColor color_arr[5][2] = { {Qt::green, Qt::darkGreen},
                           {Qt::red, Qt::darkRed},
                           {Qt::gray, Qt::darkGray},
                           {Qt::blue, Qt::darkBlue},
                           {Qt::magenta, Qt::darkMagenta} };

    int idx = rand() % 5;
    sBrushColor = color_arr[idx][0];
    sPenColor = color_arr[idx][1];
}

//////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////
/// class UnitUI
///
UnitUI::UnitUI(const Unit& coord, QGraphicsScene *scene) : mScene(scene)
{
    QBrush rectBrush(TetrisWindow::getBrushColor());
    QPen   rectPen(TetrisWindow::getPenColor());

    mGraphRect = scene->addRect(coord.x(), coord.y(),
                                UNIT_WIDTH, UNIT_HEIGHT, rectPen, rectBrush);
}

UnitUI::~UnitUI()
{
    mScene->removeItem(mGraphRect);
}

void UnitUI::moveUnit(const QPoint& updateDelta)
{
    mGraphRect->moveBy(updateDelta.x(), updateDelta.y());
}

void UnitUI::updateColor()
{
    QBrush brush(TetrisWindow::getBrushColor());
    QPen   pen(TetrisWindow::getPenColor());

    mGraphRect->setBrush(brush);
    mGraphRect->setPen(pen);
    mGraphRect->update();
}

///////////////////////////////////////////////////////////////////
/// class UnitEntity
///
UnitEntity::~UnitEntity()
{
    delete mUnitUi;
}

///////////////////////////////////////////////////////////////////
/// class ShapeUIUnitsManager
///
ShapeUI::ShapeUI(QGraphicsScene *scene) : mScene(scene)
{
    mNextShapeType = Shape::getRandomShapeType();
    mCurrShapeType = mNextShapeType;
    generateShape();
}

//////////////////////////////////////
/// Generate new Shape location in the top,
/// after it finished its run down
///
void ShapeUI::generateShape()
{
    mXPos = SCREEN_WIDTH/2 - UNIT_WIDTH/2 - UNIT_WIDTH;
    mYPos = 0;

    mCurrShapeType = mNextShapeType;
    mNextShapeType = Shape::getRandomShapeType();

    Shape shape(mCurrShapeType);

    for (int yI = 0; yI < 3; yI++)
    {
        for (int xI = 0; xI < 3; xI++)
        {
            if (shape.hasUnitInPos(xI, yI))
            {
                Unit coord;
                getCoord(xI, yI, coord);
                mUnits[yI][xI] = new UnitUI(coord, mScene);
            }
            else
            {
                mUnits[yI][xI] = NULL;
            }
        }
    }
}

void ShapeUI::cleanUnits()
{
    for (int yI = 0; yI < 3; yI++)
    {
        for (int xI = 0; xI < 3; xI++)
        {
            if (mUnits[yI][xI] != NULL)
            {
                delete mUnits[yI][xI];
            }
        }
    }
}

ShapeUI::~ShapeUI()
{
    cleanUnits();
}

void ShapeUI::getNextShapeTypeImage(string& img_name)
{
    img_name = "shape_";
    img_name += to_string(mNextShapeType);
}

/////////////////////////////////////////
/// Move units array to given direction
///
void ShapeUI::move(MoveDirection direction)
{
    // Move in UI
    for (int yI = 0; yI < 3; yI++)
    {
        for (int xI = 0; xI < 3; xI++)
        {
            if (mUnits[yI][xI] != NULL)
            {
                QPoint updateDelta;
                getUtil()->getMoveDelta(direction, updateDelta);
                mUnits[yI][xI]->moveUnit(updateDelta);
            }
        }
    }

    // Move in data
    switch (direction)
    {
    case MOVE_ON:
        mYPos += MOVE_VAL;
        break;
    case MOVE_RIGHT:
        mXPos += UNIT_WIDTH;
        break;
    case MOVE_LEFT:
        mXPos -= UNIT_WIDTH;
        break;
    }
}

void ShapeUI::rotateUI()
{
    QPoint deltaArr[3][3];

    // [00] [01] [02]
    // [10] [11] [12]
    // [20] [21] [22]

    deltaArr[0][0].setX(UNIT_WIDTH * 2);   deltaArr[0][0].setY(0);
    deltaArr[0][1].setX(UNIT_WIDTH);       deltaArr[0][1].setY(UNIT_HEIGHT);
    deltaArr[0][2].setX(0);                deltaArr[0][2].setY(UNIT_HEIGHT * 2);

    deltaArr[1][0].setX(UNIT_WIDTH);       deltaArr[1][0].setY(-UNIT_HEIGHT);
    deltaArr[1][1].setX(0);                deltaArr[1][1].setY(0);
    deltaArr[1][2].setX(-UNIT_WIDTH);      deltaArr[1][2].setY(UNIT_HEIGHT);

    deltaArr[2][0].setX(0);                deltaArr[2][0].setY(-UNIT_HEIGHT * 2);
    deltaArr[2][1].setX(-UNIT_WIDTH);      deltaArr[2][1].setY(-UNIT_HEIGHT);
    deltaArr[2][2].setX(-UNIT_WIDTH * 2);  deltaArr[2][2].setY(0);

    for (int yI = 0; yI < 3; yI++)
        for (int xI = 0; xI < 3; xI++)
        {
            if (mUnits[yI][xI] != NULL)
            {
                mUnits[yI][xI]->moveUnit(deltaArr[yI][xI]);
            }
        }
}

void ShapeUI::rotateData()
{
    UnitPtr rotatedMap[3][3];
    // [00] [01] [02]
    // [10] [11] [12]
    // [20] [21] [22]

    rotatedMap[0][0] = mUnits[2][0];
    rotatedMap[0][1] = mUnits[1][0];
    rotatedMap[0][2] = mUnits[0][0];
    rotatedMap[1][0] = mUnits[2][1];
    rotatedMap[1][1] = mUnits[1][1];
    rotatedMap[1][2] = mUnits[0][1];
    rotatedMap[2][0] = mUnits[2][2];
    rotatedMap[2][1] = mUnits[1][2];
    rotatedMap[2][2] = mUnits[0][2];

    // Copy back rotated data
    for (int y = 0; y < 3; y++)
        for (int x = 0; x < 3; x++)
        {
            mUnits[y][x] = rotatedMap[y][x];
        }
}

void ShapeUI::getCoord(int xPos, int yPos, Unit& coord)
{
    coord.set(mXPos + UNIT_WIDTH * xPos,
              mYPos + UNIT_HEIGHT * yPos);
}

void ShapeUI::getUnitsCoord(vector<Unit>& unitsCoordArr)
{
    unitsCoordArr.clear();
    for (int yI = 0; yI < 3; yI++)
    {
        for (int xI = 0; xI < 3; xI++)
        {
            if (mUnits[yI][xI] != NULL)
            {
                Unit coord;
                getCoord(xI, yI, coord);
                unitsCoordArr.push_back(coord);
            }
        }
    }
}

void ShapeUI::addScreenUnits(vector<UnitEntity*>& unitsArr)
{
    for (int yI = 0; yI < 3; yI++)
    {
        for (int xI = 0; xI < 3; xI++)
        {
            if (mUnits[yI][xI] != NULL)
            {
                Unit coord;
                getCoord(xI, yI, coord);

                if (coord.x() < 0 || coord.x() > 1000 ||
                    coord.y() < 0 || coord.y() > 1000)
                {
                    showMsg("Bad coordinates", "...");
                }

                UnitEntity* unit_entity = new UnitEntity(mUnits[yI][xI], coord);
                unitsArr.push_back(unit_entity);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////
/// class UnitsManager
///
void UnitsManager::addMovingShapeToDB(ShapeUI* shape)
{
    shape->addScreenUnits(mScreenUnits);
}

bool UnitsManager::isUnitCollapse(const Unit& unit) const
{
    bool inside = false;
    int size = mScreenUnits.size();

    for (int i = 0; i < size; i++)
    {
        if (mScreenUnits[i]->mUnitCoord.isInside(unit))
        {
            inside = true;
            break;
        }
    }

    return inside;
}

int UnitsManager::getFullRowHeight ()
{
    const int ScreenArrSize = SCREEN_HEIGHT/UNIT_HEIGHT;
    int *arr = new int[ScreenArrSize];
    int i = 0;

    // Set zero for all the values
    for (i = 0; i < ScreenArrSize; i++) arr[i] = 0;

    int unitsArrSize = mScreenUnits.size();
    int idx = 0;

    // set array values
    for (i = 0; i < unitsArrSize; i++)
    {
        idx = mScreenUnits[i]->mUnitCoord.y() / UNIT_HEIGHT;
        arr[idx]++;
    }

    int retVal = -1;
    for (i = 0; i < ScreenArrSize; i++)
    {
        if (arr[i] == SCREEN_WIDTH/UNIT_WIDTH)
        {
            retVal = (i * UNIT_HEIGHT);
            break;
        }
    }

    delete [] arr;
    return retVal;
}

bool UnitsManager::removeFirstInArr (int height_val)
{
    bool done = false;

    vector<UnitEntity*>::iterator It;
    for (It = mScreenUnits.begin(); It != mScreenUnits.end(); It++)
    {
        UnitEntity* unit = *It;

//int i = 0;
//        cout << i++ << "  x=" << unit->getCoord().x() << ", y=" << unit->getCoord().y() << endl;
        if (height_val == unit->getCoord().y())
        {
            delete unit;
            mScreenUnits.erase(It);
            done = true;
            break;
        }
    }
    return done;
}

void UnitsManager::removeFullRow(int fullRowHeight)
{
    int counter = 0;
    while (removeFirstInArr(fullRowHeight)) ++counter;

    if (counter != SCREEN_WIDTH/UNIT_WIDTH)
    {
        string msg = "Counted only ";
        msg += counter;
        msg += " times";
        showMsg ("removeFullRow() Error", msg.c_str());
    }
}

void UnitsManager::moveOnRemovedFullRow(int fullRowHeight)
{
    int size = mScreenUnits.size();
    int yCoord = 0;

    for (int i = 0; i < size; i++)
    {
        yCoord = mScreenUnits[i]->mUnitCoord.y();
        if (yCoord < fullRowHeight)
        {
            QPoint delta(0, UNIT_HEIGHT);
            mScreenUnits[i]->mUnitUi->moveUnit(delta);
            mScreenUnits[i]->mUnitCoord.setY(yCoord + UNIT_HEIGHT);
        }
    }
}

void UnitsManager::clean()
{
    int size = mScreenUnits.size();

    for (int i = 0; i < size; i++)
    {
        delete mScreenUnits[i];
    }

    mScreenUnits.clear();
}

void UnitsManager::updateUnitsColor()
{
    for (UnitEntity* unit : mScreenUnits)
    {
        {
            unit->mUnitUi->updateColor();
        }
    }
}

void TetrisWindow::closeEvent(QCloseEvent *)
{
    saveSettings();
}

