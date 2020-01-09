#include "tetriswindow.h"
#include <QApplication>
#include <QMessageBox>

static TetrisWindow* get_set_wnd(TetrisWindow* wnd)
{
    static TetrisWindow* sWnd= NULL;

    if (wnd)
    {
        sWnd = wnd;
    }

    return sWnd;
}


void showMsg(const char* title, const char* msg)
{
    QWidget* wnd = get_set_wnd(NULL);
    QMessageBox::information(wnd, title, msg, QMessageBox::Ok);
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TetrisWindow w;
    get_set_wnd(&w);
    w.show();

    return a.exec();
}
