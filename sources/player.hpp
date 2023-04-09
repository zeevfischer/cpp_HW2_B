#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

// my includs
#include <vector>
#include "card.hpp"
using namespace std;
namespace ariel
{
    class Player
    {
    private:
        string name;
        vector<card> player_deck;
        int points;
        unsigned long int player_hand;
        bool in_game = false;
    public:
        Player(string name);
        Player(){}
        ~Player();
        // Player(const Player& p);
        int stacksize();
        int cardesTaken();
        int get_points();
        void set_deck(std::vector<card> deck);
        void set_point(int amount);
        string get_name();
        vector<card>& get_deck();
        void set_hand(unsigned long int hand);
        unsigned long int get_hand();
        bool get_state();
        void set_state(bool stat);




    };    
}