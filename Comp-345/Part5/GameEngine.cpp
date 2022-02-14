#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>
#include <sstream>
#include "GameEngine.h"

GameEngine::GameEngine() : input (""), currentSteps(0), numberOfMaps(0), numberOfPlayers(0), partSwitch(false){
    
}

GameEngine::GameEngine(const GameEngine& g){
    currentSteps = g.currentSteps;
    input = g.input;
    numberOfMaps = g.numberOfMaps;
    numberOfPlayers = g.numberOfPlayers;
    partSwitch = g.partSwitch;
}

GameEngine& GameEngine::operator=(const GameEngine& g) {
    currentSteps = g.currentSteps;
    input = g.input;
    numberOfMaps = g.numberOfMaps;
    numberOfPlayers = g.numberOfPlayers;
    partSwitch = g.partSwitch;
    return *this;
}

void GameEngine::Start(){
    currentSteps = 0;
    cout<< "welcome to play Warzone" << endl;
    cout<< "please enter (load) to load map and play the game" << endl;
    cin >> this->input;
    if (input == "load"){
        currentSteps = 1;
    }
    else if (input != "load"){
        cout<< "wrong Command! reset this step" << endl;
        currentSteps = 0;
    }
    partSwitch = false;
}

void GameEngine::MapLoaded(){
    numberOfMaps = numberOfMaps + 1;
    cout<< "map has been loaded" << endl;
    cout<< "currently you have " << numberOfMaps << " map(s)" <<endl;
    cout<< "if you want to load other map, Please enter(reload)" << endl;
    cout<< "if you want to validated map, Please enter(validated)" << endl;
    cin >> this->input;
    if (input == "reload"){
        cout<< "new map is loading... will you load the other map?" << endl;
        cout<< "enter (yes) for load a new map, enter (no) for validated the map.";
        numberOfMaps = numberOfMaps + 1;
        cin >> this->input;
        if (input == "yes"){
            currentSteps = 1;
        }
        else if (input == "no"){
            currentSteps = 2;
        }
    }
    else if (input == "validated"){
            currentSteps = 2;
            
        }
    else if (input != "validated" && input != "load"){
            currentSteps = 1;
            numberOfMaps = 0;
            cout << "wrong Command! reset this step" << endl;
        }
    
}

void GameEngine::MapValidated(){
    cout<< "map has been validated" << endl;
    currentSteps = 3;
    
}

void GameEngine::PlayersAdded(){
    cout<<"now you have to add player"<<endl;
    cout<<"enter (yes) to add a player" <<endl;
    cout<<"enter (no) to finish add" <<endl;
    cin >> this->input;
    if (input == "yes"){
        numberOfPlayers = numberOfPlayers + 1;
        cout<<"now a new player has been added, you have "<< numberOfPlayers << " right now" <<endl;
        currentSteps = 3;
        partSwitch = false;
    }
    else if (input == "no"){
        currentSteps = 4;
        partSwitch = true;
    }
    else if (input != "yes" && input !="no"){
        currentSteps = 3;
        numberOfPlayers = 0;
        cout << "wrong Command! reset this step" << endl;
    }
    
}
void GameEngine::AssignReinforcement(){
    cout << "Assign reinforcement right now" << endl;
    cout << "Going to issue orders" << endl;
    currentSteps = 5;
}

void GameEngine::IssueOrders(){
    cout << "enter (yes) for issue the order" <<endl;
    cout << "enter (no) for going excuted order" <<endl;
    cin >> this->input;
    if (input == "yes"){
        cout << "comfirmed!" << endl;
        cout << "would you issue other order" << endl;
        cout << "enter (yes) for issue the order, enter (no) for excute" <<endl;
        cin >> this->input;
        if (input == "yes"){
            currentSteps = 5;
        }
        else if (input == "no"){
            currentSteps = 6;
        }
        else if (input != "yes" && input !="no"){
            currentSteps = 5;
            cout << "wrong Command! reset this step" << endl;
        }
    }
    else if (input == "no"){
        cout << "comfirmed!" << endl;
        cout << "going excuted order" << endl;
        currentSteps = 6;
    }
    else if (input != "yes" && input !="no"){
        currentSteps = 5;
        cout << "wrong Command! reset this step" << endl;
    }
}

void GameEngine::ExecuteOrders(){
    cout << "your orders have beed excuted!" <<endl;
    cout << "now you have to choose to win the game or not!" <<endl;
    cout << "enter (win) for win the game!" <<endl;
    cout << "enter (excute) for re-excute order!" <<endl;
    cout << "enter (assignreinforce) for re-assign reinforcement!" <<endl;
    cin >> this->input;
    if (input == "win"){
        currentSteps = 7;
    }
    if (input == "excute"){
        currentSteps = 6;
    }
    if (input == "assignreinforce"){
        currentSteps = 5;
    }
    else if (input != "win" && input !="excute" && input !="assignreinforce"){
        currentSteps = 6;
        cout << "wrong Command! reset this step" << endl;
    }
}

void GameEngine::Win(){
    cout << "Your enermy has beed defeated, You won!" << endl;
    cout << "Do you want to play again ?(new game)" << endl;
    cout << "enter (yes) for play again" << endl;
    cout << "enter any command besides (yes) will determinate" << endl;
    cin >> this->input;
    if (input == "yes"){
        currentSteps = 0;
        cout << "game is resetting!" << endl;
        numberOfMaps = 0;
        numberOfPlayers = 0;
    }

    else {
        cout << "Thank you for playing this game!!!";
        currentSteps = 8; // shut down the loop
    }
    partSwitch = false;
}

void GameEngine::StartUp(){
    while(currentSteps == 0){
        Start();
    }
    while(currentSteps == 1){
        MapLoaded();
    }
    while(currentSteps == 2){
        MapValidated();
    }
    while(currentSteps == 3){
        PlayersAdded();
    }
}

void GameEngine::Play(){
    while(currentSteps == 4){
        AssignReinforcement();
        while(currentSteps == 5){
            IssueOrders();
        }
        while(currentSteps == 6){
            ExecuteOrders();
        }
        while(currentSteps == 7){
            Win();
        }
    }
}

void GameEngine::GameLoop(){
    partSwitch = false;
    currentSteps = 0;
    while(partSwitch == false && currentSteps == 0){
        StartUp();
    }
    while(partSwitch == true && currentSteps == 4){
        Play();
    }

}
