#include <iostream>
#include <fstream>
#include <vector>
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
    cout<< "    " << endl;
    cout<< "<<welcome to play Warzone>>" << endl;
    cout<< "    " << endl;
    cout<< "warning! any command you enter should be all <lower-case> !!!!"<<endl;
    cout<< "please enter (load) to load map and play the game" << endl;
    cout<< "there is a default map will be automatic loaded if you start to play" <<endl;
    cin >> this->input;
    if (input == "load"){
        currentSteps = 1;
    }
    else if (input != "load"){
        cout<< "wrong command! reset this step" << endl;
        currentSteps = 0;
    }
    partSwitch = false;
    cout<< "    " << endl;
}

void GameEngine::MapLoaded(){
    numberOfMaps = numberOfMaps + 1;
    cout<< "map has been loaded" << endl;
    cout<< "currently you have " << numberOfMaps << " map(s)" <<endl;
    cout<< "if you want to load other map, Please enter(yes)" << endl;
    cout<< "if you want to validated map, Please enter(validated)" << endl;
    cin >> this->input;
    if (input == "yes"){
        currentSteps = 1;
    }
    else if (input == "validated"){
        currentSteps = 2; 
    }
    else if (input != "validated" && input != "yes"){
        currentSteps = 1;
        numberOfMaps = numberOfMaps - 1;
        cout << "wrong command! reset this step" << endl;
    }
    cout<< "    " << endl;
}

void GameEngine::MapValidated(){
    cout<< "there are total "<<numberOfMaps<< " map(s) have been validated" << endl;
    currentSteps = 3;
    cout<< "    " << endl;
}

void GameEngine::PlayersAdded(){
    cout<<"now you have to add player"<<endl;
    cout<<"enter (yes) to add a player" <<endl;
    cout<<"enter (no) to finish add" <<endl;
    cin >> this->input;

    if (input == "yes"){
        numberOfPlayers = numberOfPlayers + 1;
        cout<<"now a new player has been added, you have "<< numberOfPlayers << " player(s) right now" <<endl;
        currentSteps = 3;
        partSwitch = false;
    }
    if(input == "no"){
        currentSteps = 4;
        partSwitch = true;
    }
    if (numberOfPlayers == 0){
        cout<<"you can not play the game without players, go back to add one"<<endl;
        currentSteps = 3;
    }
    if (input != "yes" && input !="no"){
        currentSteps = 3;
        cout << "wrong command! reset this step" << endl;
    }
    cout<< "    " << endl;
}
void GameEngine::AssignReinforcement(){
    cout << "assign reinforcement right now" <<endl;
    cout << "assign reinforcement has been finished" << endl;
    cout << "going to issue orders" << endl;
    currentSteps = 5;
    cout<< "    " << endl;
}

void GameEngine::IssueOrders(){
    cout << "now your order has been issued" <<endl;
    cout << "enter (yes) for re-issue the order" <<endl;
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
            cout << "wrong command! reset this step" << endl;
        }
    }
    else if (input == "no"){
        cout << "comfirmed!" << endl;
        cout << "going excuted order" << endl;
        currentSteps = 6;
    }
    else if (input != "yes" && input !="no"){
        currentSteps = 5;
        cout << "wrong command! reset this step" << endl;
    }
    cout<< "    " << endl;
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
        currentSteps = 4;
    }
    else if (input != "win" && input !="excute" && input !="assignreinforce"){
        currentSteps = 6;
        cout << "wrong command! reset this step" << endl;
    }
    cout<< "    " << endl;
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
        currentSteps = 8; 
    }
    partSwitch = false;
    cout<< "    " << endl;
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
            while(partSwitch == true && currentSteps == 4){
            Play();
        }
    }


}
