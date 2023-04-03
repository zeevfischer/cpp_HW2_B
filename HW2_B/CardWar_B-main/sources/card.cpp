#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "card.hpp"

namespace ariel
{
    card::card(int card_num, std::string symbol)
    {
        this->card_num = card_num;
        this->symbol = symbol;
    }
    
    card::~card()
    {
        delete this;
    }

    int card::get_card_num()
    {
        return this->card_num;
    }
    std::string card::get_card_symbol()
    {
        return this->symbol;
    }
    std::string card::print()
    {
        std::string symbol = card::get_card_symbol();
        int card_num = card::get_card_num();

        if(card_num ==  11)
        {
            return "Jack of " + symbol;
        }
        if(card_num ==  12)
        {
            return "Queen of " + symbol;
        }
        if(card_num ==  13)
        {
            return "King of " + symbol;
        }
    }
}