#include <iostream>
#include <vector>
#include <map>

using namespace std;
#pragma once

// player temp class
class Player
{
private:
    string name;

public:
    Player();
    Player(string);
    ~Player();
    Player(const Player&);
    string getName();
    friend istream & operator >> (istream &in,  Player &p);
    Player &operator=(const Player& p2);
};

//territory class
class Territory
{
private:
    int id;
    string name;
    string continent;
    Player *owner;
    int num_of_armies;

    /* data */
public:
    Territory();
    Territory(int, string, string, Player*, int);
    ~Territory();
    Territory(const Territory& );
    friend istream & operator >> (istream &in,  Territory &t);
    Territory &operator=(const Territory& p2);

    //getters
    int getId();
    int getNum_of_armies();
    string getName();
    string getContinent();
    Player* getPlayer();

    //setters
    void setNum_of_armies(int);
    void setPlayer(Player*);
};
// class map
class Map
{
private:
    map<int, string> continents;
    vector<Territory* > territories;
    vector<vector<int> > borders;
    map<int, vector<Territory* > > subgraphs;

public:
    Map();
    Map(string,Player*);
    ~Map();
    Map(const Map&);
    Map& operator=(const Map &p2);
    friend istream & operator >> (istream &in,  Map &m);    
    void initiating(string,Player*);
    vector<string> gettingwords(char, string);
    bool validate();
    void traverse(int, bool[], vector<vector<int> > borders);
    bool isConnected(vector<vector<int> > borders);
    

    //getters
    vector<vector<int> >& getBorders();
    vector<Territory* >& getTerritories();


};
