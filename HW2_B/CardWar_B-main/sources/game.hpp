#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "player.hpp"

//my includs
#include <vector>
#include "card.hpp"

namespace ariel
{
    class Game
    {
    private:
        Player p1;
        Player p2;

        std::vector<card> deck_of_card;
    public:
        Game(Player p1, Player p2);
        void playTurn();
        void playAll();
        void printWiner();
        void printLog();
        void printStats();
        void printLastTurn();
        ~Game();

        //my functions
        std::vector<card> creat_deck_of_card()
        {
            
        }

    };
}