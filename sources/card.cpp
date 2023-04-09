#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "card.hpp"
using namespace std;
namespace ariel
{
    card::card(int card_num, string symbol)
    {
        this->card_num = card_num;
        this->symbol = symbol;
    }
    
    card::~card()
    {
    }
    card::card(const card& c)
    {
        this->card_num = c.card_num;
        this->symbol = c.symbol;
    }

    int card::get_card_num()
    {
        return this->card_num;
    }
    string card::get_card_symbol()
    {
        return this->symbol;
    }
    string card::print()
    {
        string symbol = card::get_card_symbol();
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
        stringstream temp;
        temp << card_num;
        string str = temp.str();
        return str + " of " + symbol;
    }
}