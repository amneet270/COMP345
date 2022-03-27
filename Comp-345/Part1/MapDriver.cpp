#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include <vector>

using namespace std;

// driver file to run the program
// the commented code is there to show that it can read invalid files and also is able to recognize invalid files
int main()
{
    const int STARTING_ARMY=50;
    const int INITIAL_NUM_OF_CARDS=2;
    vector<Player *> players;
    int player_id = 0;

    Map *m1;
    while (true)
    {
        // Map *m1=new Map("solar.map",player1);
        m1 = new Map("solar.map");
        // Map *m1=new Map("invalid_continent_solar.map",player1);
        if ((*m1).validate())
        {
            cout << "The map is valid" << endl;
            break;
        }
        else
        {
            cout << "The map is NOT valid" << endl;
        }
    }

    for (int i = 0; i < 4; i++)
    {
        string name;
        cin >> name;
        players.push_back(new Player(player_id++, name));
    }
    vector<int> playing_order(players.size(), -1);
    vector<int> checking;
    srand(time(0));
    int random_value = rand() % players.size();
    for (int i = 0; i < players.size(); i++)
    {
        playing_order[i] = random_value;
        random_value = ++random_value % players.size();
    }
    vector<Territory *> all_countries = m1->getTerritories();
    int country_per_player = all_countries.size() / players.size();
    int remaining_counteries = all_countries.size() % players.size();

    for (int i = 0; i < players.size(); i++)
    {
        for (int j = 0; j < country_per_player; j++)
        {
            players[i]->add_country_to_owned(all_countries[i * country_per_player + j]);
            all_countries[i * country_per_player + j]->setPlayer(players[i]);
        }

        if (i == players.size() - 1)
        {
            int max=all_countries.size()-1;

            for(int j=0;j<remaining_counteries;j++){
                players[i]->add_country_to_owned(all_countries[max]);
                all_countries[max]->setPlayer(players[i]);
                max--;
            }
        }
        players[i]->setNumof_army(STARTING_ARMY);
    }

    for (int i=0;i<all_countries.size();i++){
        cout << "country: "<<all_countries[i]->getName()<< "------ belong to :" << all_countries[i]->getPlayer()->getId()<<endl;
    }

    for(int i=0;i<players.size();i++)
    {
        cout<<players[i]->getId()<<endl;
        for(int j=0;j<players[i]->countries_owned().size();j++)
        {
         cout<<players[i]->countries_owned()[j]->getId()<<endl;   
        }
        cout<<endl;
        cout<<endl;

    }
    Deck *simple_deck_of_cards= new Deck(players.size()*6);
    for(int i = 0; i<players.size();i++)
    {
        for(int j =0;j<INITIAL_NUM_OF_CARDS;j++)
        {
            players[i]->add_to_hand(simple_deck_of_cards->draw());
            cout<< players[i]->getHand()->getcard(j)->getCardType()<<endl;
        }
    }


    

    delete m1;
}
