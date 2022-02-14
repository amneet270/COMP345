#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

// driver file to run the program
// the commented code is there to show that it can read invalid files and also is able to recognize invalid files
int main()
{
    Player *player1= new Player("amneet");
    Map *m1=new Map("solar.map",player1);
    //Map *m1=new Map("invalid_solar.map",player1);
    //Map *m1=new Map("invalid_continent_solar.map",player1);
    if((*m1).validate()){
        cout <<  "The map is valid" << endl;
    }
    else {
        cout <<  "The map is NOT valid" << endl;
    }

    delete m1;
    delete player1;
}
