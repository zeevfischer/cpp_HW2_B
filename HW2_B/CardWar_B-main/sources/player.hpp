#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

// my includs
#include <vector>
#include "card.hpp"

namespace ariel
{
    class Player
    {
    private:
        std::string name;
        std::vector<card> player_deck;
    public:
        Player(std::string name);
        Player(){}
        int stacksize();
        int cardesTaken();
        ~Player();
    };    
}