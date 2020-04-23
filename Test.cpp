#include "Test.h"
#include <iostream>
#include <fstream>

using namespace std;

//Setup test track 2D array with all 0.
Test::Test()
{
    track = 0;
    for(int i = 0; i < 500; i++){
         for(int j = 0; j < 4; j++){
            testList[i][j] = 0;
         }
    }
}

//Increase track value to signify current row.
void Test::raiseTrack()
{
    track++;
}

//Setup test array value of first column to 1.
void Test::changeValue()
{
    testList[track][0] = 1;
}

//Make test data file to store values.
void Test::setupTextFile()
{
    ofstream inout;
    inout.open("tracks/TestData.txt");
    for(int i = 0; i < 500; i++){
         for(int j = 0; j < 4; j++){
             inout << testList[i][j] << " ";
         }
         inout << endl;
    }
    inout.close();

}
