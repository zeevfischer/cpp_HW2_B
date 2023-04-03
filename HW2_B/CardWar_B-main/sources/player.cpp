#include <iostream>
#include "player.hpp"
#include "card.hpp"

namespace ariel
{
    Player::Player(std::string name)
    {
        this->name = name;
    }
    int Player::stacksize()
    {
        return 0;
    }

    int Player::cardesTaken()
    {
        return 0;
    }
    Player::~Player()
    {
        for card& c :
    }
}