#ifndef LISTSETUP_H
#define LISTSETUP_H

#include <string>
class ListSetup
{
public:
    ListSetup();
    void makeList(int value);
    std::string file(int number);
    int list[500][4];
    int rows;
   std::string title(int value);
   int getTotalNotes();

};

#endif // LISTSETUP_H
