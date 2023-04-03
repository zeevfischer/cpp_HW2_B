#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

namespace ariel
{
    //this is the types of the cards it alsow deturmins color but this is not important
    // enum symbol{Heart, Diamond, Spade, Club};
    class card
    {
    private:
        int card_num;
        std::string symbol;
    public:
        card(int card_num,std::string symbol);
        ~card();
        std::string get_card_symbol();
        int get_card_num();
        std::string print();
    };    
}