#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "player.hpp"

//my includs
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Game
    {
    private:
        Player& p1;
        Player& p2;

        vector<string> game_log;
        vector<card> deck;
        unsigned long int current_hand;

        int point_set;
        int draw_count;
    public:
        Game(Player& p1, Player& p2);
        ~Game();
        void playTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        Player get_p1();
        Player get_p2();
    };
}