#include "ListSetup.h"
#include "Game.h"
#include <fstream>
#include <String>

extern Game * game;
using namespace std;
ListSetup::ListSetup()
{
    rows = 0;
}

void ListSetup::makeList(int value)
{
    string choice = file(value);
    fstream input(choice);
    int test, t1, t2, t3;
    while(!input.eof()){
        input >> test >> t1 >> t2 >> t3;
        list[rows][0] = test;
        list[rows][1] = t1;
        list[rows][2] = t2;
        list[rows][3] = t3;
        rows++;
    }
    rows = 0;
}

std::string ListSetup::file(int number)
{
    //change num 3 to three.txt later
    if(number == 0)
        return "tracks/test.txt";
    else if(number == 1)
        return "tracks/one.txt";
    else if(number == 2)
        return "tracks/two.txt";
    else if(number == 3)
        return "tracks/test.txt";
    else
        return "tracks/test.txt";
}

std::string ListSetup::title(int value)
{
    if(value == 1)
        return "Veiled in Black";
    else if(value == 2)
        return "Battle of Oblivion";
    else if(value == 3)
        return "Waltzing Gallop";
    else if(value == 4)
        return "nothing";
    else
        return "nothing";
}

int ListSetup::getTotalNotes()
{
    int total = 0;
    for(int i =0; i < 500; i++){
        for(int j = 0; j < 4; j++){
            if (list[i][j] == 1)
                total++;
            else if(list[i][j] == 2)
                return total;
        }
    }
    return total;
}
