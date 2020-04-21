#ifndef MANAGESIDEBARS_H
#define MANAGESIDEBARS_H
#include "SideBar.h"
#include "sideGoal.h"
#include <QLabel>
class ManageSideBars
{
public:
    ManageSideBars();
    void moveUp();
    void moveUp2();
    void moveDown();
    void moveDown2();
    void WinCheck();

    SideBar * leftBar;
    SideBar * rightBar;
    SideGoal * leftGoal;
    SideGoal * rightGoal;
    bool goalHit1;
    bool goalHit2;
};

#endif // MANAGESIDEBARS_H
