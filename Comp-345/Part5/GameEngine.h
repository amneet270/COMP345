#pragma once

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class GameEngine{
    
    public:
    //default construction
    GameEngine();
    //copy constuction
    GameEngine(const GameEngine& g);
    GameEngine& operator = (const GameEngine& g);
    friend std::ostream& operator<<(std::ostream& stream, const GameEngine& g);
    std::string input;
    int currentSteps;
    int numberOfMaps;
    int numberOfPlayers;
    bool partSwitch;
    /*
    * CurrentSteps 0 = Start();
    *       1 = MapLoaded();
    *       2 = MapValidated();
    *       3 = PlayersAdded();
    *       4 = AssignReinforcement();
    *       5 = IssueOrders();
    *       6 = ExecuteOrders();
    *       7 = Win();
    * 
    * partSwitch = false -> startUp
    * partSwitch = true -> play
    */


   
    void Start();
    void MapLoaded();
    void MapValidated();
    void PlayersAdded();
    void AssignReinforcement();
    void IssueOrders();
    void ExecuteOrders();
    void Win();
    void StartUp();
    void Play();
    void GameLoop();
    

};
 