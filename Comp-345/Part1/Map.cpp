#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <sstream>
#include "Map.h"
using namespace std;

// consstructors and distructors
Territory::Territory()
{
}

Territory::Territory(int id, string name, string continent, int num_of_armies)
{
    this->id = id;
    this->name = name;
    this->continent = continent;
    this->num_of_armies = num_of_armies;
    this->owner = nullptr;
}
Territory::~Territory()
{
    owner = NULL;
}

// copy constructors
Territory::Territory(const Territory &new_territory)
{
    this->id = new_territory.id;
    this->name = new_territory.name;
    this->continent = new_territory.continent;
    this->num_of_armies = new_territory.num_of_armies;
    // this->owner = new Player(*(new_territory.owner));
}

// getters
int Territory::getId()
{
    return id;
}

int Territory::getNum_of_armies()
{
    return num_of_armies;
}

string Territory::getName()
{
    return name;
}

string Territory::getContinent()
{
    return continent;
}

Player *Territory::getPlayer()
{
    return owner;
}

// setters
void Territory::setNum_of_armies(int new_num_of_armies)
{
    this->num_of_armies = new_num_of_armies;
}

void Territory::setPlayer(Player *new_player)
{
    this->owner = new_player;
}
Continents::Continents(string continent_name)
{
    this->continent_name = continent_name;
}

// constructors and distructors
Map::Map()
{
    // Player *player1 = new Player("amnet");
    initiating("solar.map");
    // delete player1;
}

Map::Map(string mapName)
{
    initiating(mapName);
}

Map::Map(const Map &new_map)
{
    this->continents = new_map.continents;
    this->borders = new_map.borders;
    this->territories.reserve(new_map.territories.size());
    for (int i = 0; i < new_map.territories.size(); i++)
    {
        territories.push_back(new Territory(*(territories[i])));
    }
}

// reading from the file and storing data
void Map ::initiating(string mapName)
{
    ifstream reader;
    reader.open(mapName);
    string line;
    bool bool_continent, bool_country, bool_borders = false;
    int j = 0;
    if (reader.is_open())
    {
        while (getline(reader, line))
        {
            if (line.length() < 2)
            {
                continue;
            }

            if (line.find("[continents]") != std::string::npos)
            {
                bool_continent = true;
                continue;
            }
            else if (line.find("[countries]") != std::string::npos)
            {
                bool_continent = false;
                bool_country = true;
                continue;
            }
            else if (line.find("[borders]") != std::string::npos)
            {
                borders.resize(territories.size(), vector<int>(territories.size(), 0));
                bool_country = false;
                bool_borders = true;
                continue;
            }

            vector<string> words = gettingwords(' ', line);

            if (bool_continent)
            {
                continents[continents.size()] = words[0];
            }
            else if (bool_country)
            {
                territories.push_back(new Territory((stoi(words[0]) - 1), words[1], continents[stoi(words[2]) - 1], 0));
                j++;
            }
            else if (bool_borders)
            {
                for (int i = 0; i < words.size(); i++)
                {
                    if (i == 0)
                    {
                        borders[stoi(words[0]) - 1][stoi(words[0]) - 1] = 1;
                        continue;
                    }
                    borders[stoi(words[0]) - 1][stoi(words[i]) - 1] = 1;
                }
            }
        }
        for (int i = 0; i < borders.size(); i++)
        {

            for (int k = 0; k < borders.size(); k++)
            {

                cout << borders[i][k] << " ";
            }
            cout << endl;
        }
        reader.close();
    }
}

// validate method that check if it is a connected graph,
// continents are subgraphs and a territory belong to single continent
bool Map ::validate()
{

    // check if the full map is connected
    if (isConnected(borders))
    {
        cout << "The map is connected!!!" << endl;
    }
    else
    {
        cout << "the map NOT connected!!!" << endl;
        return false;
    }

    // check if each continent is a subconnected graph
    int start, end;
    string current, next;
    start = 0;
    for (int j = 0; j < territories.size(); j++)
    {

        if (j != territories.size() - 1)
        {
            if (territories[j]->getContinent() == territories[j + 1]->getContinent())
            {
                continue;
            }
        }

        // using adjency matrix to chech if subgraphs are connected(getting data of continent from subgraphs)
        end = territories[j]->getId();
        vector<vector<int> > continent_border;
        continent_border.resize(((end - start) + 1), vector<int>(((end - start) + 1), 0));
        int start1, start2 = start;

        cout << endl;
        cout << endl;

        for (int i = 0; i < continent_border.size(); i++)
        {
            start1 = start2;
            for (int k = 0; k < continent_border.size(); k++)
            {
                continent_border[i][k] = borders[start][start1];
                start1++;
                cout << continent_border[i][k] << " ";
            }
            start++;
            cout << endl;
        }

        if (isConnected(continent_border))
        {
            cout << territories[start2]->getContinent() << ": is connected" << endl;
        }
        else
        {
            cout << territories[start2]->getContinent() << ": is NOT connected" << endl;
            return false;
        }
        if (j != territories.size() - 1)
        {
            start = territories[j + 1]->getId();
        }
    }

    // checks if a contry belongs to single continent
    for (int i = 0; i < territories.size(); i++)
    {
        for (int j = 0; j < territories.size(); j++)
        {
            if (i != j && territories[i]->getName() == territories[j]->getName() && territories[i]->getContinent() != territories[j]->getContinent())
            {
                cout << territories[i]->getName() << " belongs to more than one continent" << endl;
                return false;
            }
        }
    }
    add_countries_to_continent();
    return true;
}
void Map ::add_countries_to_continent()
{
    string previous = territories[0]->getContinent();
    int ix = 0;
    all_contients.push_back(new Continents(previous));
    all_contients[ix]->belonging_to_contient.push_back(territories[0]->getId());
    for (int i = 1; i < territories.size(); i++)
    {
        if (previous == territories[i]->getContinent())
        {
            all_contients[ix]->belonging_to_contient.push_back(territories[i]->getId());
            continue;
        }
        previous = territories[i]->getContinent();
        all_contients.push_back(new Continents(previous));
        ix++;
        all_contients[ix]->belonging_to_contient.push_back(territories[i]->getId());
    }

    for (int i = 0; i < all_contients.size(); i++)
    {
        cout << all_contients[i]->continent_name << endl;
        for (int j = 0; j < all_contients[i]->belonging_to_contient.size(); j++)
        {
            cout << all_contients[i]->belonging_to_contient[j] << endl;
        }
        cout << endl;
        cout << endl;
    }
}
// traversing the matrix
void Map ::traverse(int u, bool visited[], vector<vector<int> > borderss)
{
    visited[u] = true;
    for (int v = 0; v < borderss.size(); v++)
    {
        if (borderss[u][v])
        {
            if (!visited[v])
                traverse(v, visited, borderss);
        }
    }
}
// https://www.tutorialspoint.com/cplusplus-program-to-check-the-connectivity-of-undirected-graph-using-dfs used to check connectivity
bool Map ::isConnected(vector<vector<int> > aborders)
{
    bool *vis = new bool[borders.size()];
    vector<vector<int> > borderss = aborders;
    // for all vertex u as start point, check whether all nodes are visible or not
    for (int u; u < borderss.size(); u++)
    {
        for (int i = 0; i < borderss.size(); i++)
            vis[i] = false; // initialize as no node is visited
        traverse(u, vis, borderss);
        for (int i = 0; i < borderss.size(); i++)
        {
            if (!vis[i]) // if there is a node, not visited by traversal, graph is not connected
                return false;
        }
    }
    return true;
}

// separate the line into words
vector<string> Map ::gettingwords(char delimitor, string line)
{
    vector<string> words;
    string buf;
    stringstream ss(line);

    while (ss >> buf)
    {
        words.push_back(buf);
    }
    return words;
}

Map::~Map()
{
    for (int i = 0; i < territories.size() - 5; i++)
    {
        delete territories[i];
    }
}

vector<vector<int> > &Map ::getBorders()
{
    return borders;
}
vector<Territory *> &Map ::getTerritories()
{
    return territories;
}

// strems insersion operators
istream &operator>>(istream &in, Player &p)
{
    // return in >> p.name;
}

istream &operator>>(istream &in, Territory &t)
{
    return in >> t.id >> t.name >> t.continent >> t.num_of_armies >> *t.owner;
}

istream &operator>>(istream &in, Map &m)
{
    return in;
}

// assignemnt operators

Territory &Territory::operator=(const Territory &p2)
{
    if (this == &p2)
    {
        return *this; // self assignment
    }
    this->id = p2.id;
    this->name = p2.name;
    this->continent = p2.continent;
    this->num_of_armies = p2.num_of_armies;
    this->owner = p2.owner;

    return *this;
}


Map &Map::operator=(const Map &p2)
{
    for (int i = 0; i < p2.territories.size(); i++)
    {
        this->territories[i] = p2.territories[i];
    }
    this->continents = p2.continents;
    this->borders = p2.borders;
}