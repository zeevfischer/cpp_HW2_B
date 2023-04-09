#include <iostream>
#include "player.hpp"
#include "card.hpp"
using namespace std;
namespace ariel
{
    Player::Player(string name)
    {
        this->name = name;
        this->points = 0;
    }
    // Player::Player(const Player& p)
    // {
    //     this->name = p.name;
    //     this->player_deck = p.player_deck;
    //     this->points = p.points;
    // }
    int Player::stacksize()
    {
        return this->player_deck.size()-this->player_hand;
    }

    int Player::cardesTaken()
    {
        return this->points;
    }
    Player::~Player()
    {
    }
    void Player::set_deck(std::vector<card> deck)
    {

        //we need a hard copy not a pointer
        for(ariel::card& c : deck)
        {
            this->player_deck.push_back(card(c));
        }
    }
    int Player::get_points()
    {
        return this->points;
    }
    void Player::set_point(int amount)
    {
        this->points = this->points + amount;
    }
    string Player::get_name()
    {
        return this->name;
    }
    vector<card>& Player::get_deck()
    {
        return this->player_deck;
    }
    void Player::set_hand(unsigned long int hand)
    {
        this->player_hand = hand;
    }
    unsigned long int Player::get_hand()
    { 
        return this->player_hand;
    }
    bool Player::get_state()
    {
        return this->in_game;
    }
    void Player::set_state(bool stat)
    {
        this->in_game = stat;
    }
}