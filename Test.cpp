#include "Test.h"
#include <iostream>
#include <fstream>
using namespace std;
Test::Test()
{
    track = 0;
    for(int i = 0; i < 500; i++){
         for(int j = 0; j < 4; j++){
            testList[i][j] = 0;
         }
    }
}

void Test::raiseTrack()
{
    track++;
}

void Test::changeValue()
{
    testList[track][0] = 1;
}

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
