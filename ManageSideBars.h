#ifndef MANAGESIDEBARS_H
#define MANAGESIDEBARS_H
#include "SideBar.h"
#include "sideGoal.h"
#include <QLabel>
class ManageSideBars
{
public:
    ManageSideBars();
    SideBar * leftBar;
    SideBar * rightBar;
    SideGoal * leftGoal;
    SideGoal * rightGoal;
    void moveUp();
    void moveUp2();
    void moveDown();
    void moveDown2();
    bool goalHit1;
    bool goalHit2;
    void WinCheck();
};

#endif // MANAGESIDEBARS_H
