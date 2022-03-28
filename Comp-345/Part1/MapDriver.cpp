#include <iostream>
#include <fstream>
#include "Map.h"
#include "Player.h"
#include <vector>
#include "Order.h"
#include "Cards.h"
using namespace std;

// driver file to run the program
// the commented code is there to show that it can read invalid files and also is able to recognize invalid files

int main()
{
    cout << "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa" << endl;
    const int STARTING_ARMY = 50;
    const int INITIAL_NUM_OF_CARDS = 2;
    const int COUNTRIES_TO_ATTACK = 5;
    const int COUNTRIES_TO_Defend = 5;
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
            int max = all_countries.size() - 1;

            for (int j = 0; j < remaining_counteries; j++)
            {
                players[i]->add_country_to_owned(all_countries[max]);
                all_countries[max]->setPlayer(players[i]);
                max--;
                cout << "---------------------------------------------" << endl;
            }
        }
        players[i]->setNumof_army(STARTING_ARMY);
    }

    for (int i = 0; i < all_countries.size(); i++)
    {
        cout << "country: " << all_countries[i]->getName() << "------ belong to :" << all_countries[i]->getPlayer()->getId() << endl;
    }
    cout << "-=-=--=-=-=-=-==-=-" << endl;

    for (int i = 0; i < players.size(); i++)
    {
        cout << players[i]->getId() << endl;
        for (int j = 0; j < players[i]->countries_owned().size(); j++)
        {
            cout << players[i]->countries_owned()[j]->getId() << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << "---------------------------------------------" << endl;
    Deck *simple_deck_of_cards = new Deck(players.size() * 6);
    for (int i = 0; i < players.size(); i++)
    {
        for (int j = 0; j < INITIAL_NUM_OF_CARDS; j++)
        {
            players[i]->add_to_hand(simple_deck_of_cards->draw());
            // cout << players[i]->getHand()->getcard(j)->getCardType() << endl;
            cout << "-=-=--=-=-=-=-==-=-" << endl;
        }
    }
    cout << "-=-=--=-=-=-=-==-=-" << endl;
    // reinforcement
    bool found;
    for (int i = 0; i < players.size(); i++)
    {
        int increase_army = 0;

        for (int ii = 0; ii < m1->getContients().size(); ii++)
        {
            for (int j = 0; j < m1->getContients()[ii]->belonging_to_contient.size(); j++)
            {
                found = false;

                for (int k = 0; k < players[i]->countries_owned().size(); k++)
                {
                    if (m1->getContients()[ii]->belonging_to_contient[j] == players[i]->countries_owned()[k]->getId())
                    {
                        found = true;
                    }
                }

                if (found == false)
                {
                    break;
                }
            }
            if (found == true)
            {
                increase_army += m1->getContients()[ii]->belonging_to_contient.size() / 2;
                cout << "*******************" << endl;
                cout << "player ID: " << players[i]->getId() << "     adding army: " << (m1->getContients()[ii]->belonging_to_contient.size() / 2) << endl;
                cout << "*******************" << endl
                     << endl;
            }
        }

        increase_army += players[i]->countries_owned().size() / 3;

        if (increase_army < 3)
        {
            players[i]->addarmy(3);
        }
        else
        {
            players[i]->addarmy(increase_army);
        }
        cout << "-=-=--=-=-=-=-==-=-" << players[i]->getNumof_army() << endl;
    }

    // issuing order phase
    srand(time(0));
    int j = 0;
    int current_country;
    vector<int> countries_to_attack;
    for (int i = 0; i < players.size(); i++)
    {
        // listing some counteries to attack
        for (int j = 0; j < COUNTRIES_TO_ATTACK; j++)
        {
            int indexx = rand() % players[i]->countries_owned().size();
            current_country = players[i]->countries_owned()[indexx]->getId();

            cout << "border: ";
            for (int j = 0; j < m1->getTerritories().size(); j++)
            {
                if (m1->getBorders()[current_country][j] == 1)
                {
                    countries_to_attack.push_back(j);
                    cout << j << " ";
                }
            }

            countries_to_attack.clear();
        }

        // LISTING COUNTERIES TO DEFEND
        int starting_index = rand() % players[i]->countries_owned().size();

        for (int j = 0; j < COUNTRIES_TO_Defend; j++)
        {
            players[i]->add_country_to_defend(players[i]->countries_owned()[starting_index]);
            starting_index = rand() % players[i]->countries_owned().size();
        }

        // issuing order
        players[i]->issueOrder(new DiployeOrder());

        int randoms = rand() % 8;
        for (int j = 0; j < randoms; j++)
        {
            players[i]->issueOrder(new AdvanceOrder());
        }

        int random_card = rand() % players[i]->getHand()->getcard().size();

        if (players[i]->getHand()->getcard()[random_card]->getCardType() == "airlift")
        {
            players[i]->issueOrder(new airliftOrder());
        }
        else if (players[i]->getHand()->getcard()[random_card]->getCardType() == "bomb")
        {
            players[i]->issueOrder(new bombOrder());
        }
        else if (players[i]->getHand()->getcard()[random_card]->getCardType() == "blockade")
        {
            players[i]->issueOrder(new blockadeOrder());
        }
        else if (players[i]->getHand()->getcard()[random_card]->getCardType() == "diplomacy")
        {
            players[i]->issueOrder(new negociationOrder());
        }
    }

    for (int i = 0; i < players.size(); i++)
    {
        cout << "player id: " << players[i]->getId() << endl;
        cout << "   player cards: " << endl;
        for (int j = 0; j < players[i]->getHand()->getcard().size(); j++)
        {
            cout << "       card: " << players[i]->getHand()->getcard()[j]->getCardType() << endl;
        }
    }
    for (int i = 0; i < players.size(); i++)
    {
        cout << "player id: " << players[i]->getId() << endl;
        cout << "   orders: " << players[i]->getOrderList()->getlist().size() << endl;
        cout << "*******************" << endl;
        for (int j = 0; j < players[i]->getOrderList()->getlist().size(); j++)
        {
            cout << "       order: " << players[i]->getOrderList()->getlist()[j]->gettype() << endl;
        }
    }

    


    delete m1;
}