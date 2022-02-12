#include <iostream>
#include <fstream>
#include "Map.h"

using namespace std;

int main()
{
    Player *player1= new Player("amneet");
    Map *m1=new Map("solar.map",player1);
    if((*m1).validate()){
        cout <<  "The map is valid" << endl;
    }
    else {
        cout <<  "The map is NOT valid" << endl;
    }

    delete m1;
}
