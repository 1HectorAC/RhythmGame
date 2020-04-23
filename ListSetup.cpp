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

//Setup array with specfied track based on integer value passed.
void ListSetup::makeList(int value)
{

    string choice = file(value);
    fstream input(choice);
    int t0, t1, t2, t3;

    //Add values from file to array.
    while(!input.eof()){
        input >> t0 >> t1 >> t2 >> t3;
        list[rows][0] = t0;
        list[rows][1] = t1;
        list[rows][2] = t2;
        list[rows][3] = t3;
        rows++;
    }
    input.close();
    rows = 0;
}

//Get file name based on integer value passed.
std::string ListSetup::file(int number)
{
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

//Get track name based on integer value passed.
std::string ListSetup::title(int value)
{
    if(value == 1)
        return "Song 1";
    else if(value == 2)
        return "Song 2";
    else if(value == 3)
        return "Song 3";
    else if(value == 4)
        return "nothing";
    else
        return "nothing";
}

//Get total number of notes in the current track.
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
