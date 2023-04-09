#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;
namespace ariel
{
    class card
    {
    private:
        int card_num;
        string symbol;
    public:
        card(int card_num,string symbol);
        card(const card& c);
        ~card();
        card(){}
        string get_card_symbol();
        int get_card_num();
        string print();
    };    
}