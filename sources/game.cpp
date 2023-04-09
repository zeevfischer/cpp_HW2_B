#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "game.hpp"
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
using namespace std;
namespace ariel
{
    // still need to add here game logic but main idea worcks!!!!
    void Game::playTurn()
    {
        // cout << "hand = " <<  this->current_hand << endl;
        if(this->current_hand > (this->deck.size()/2)-1)
        {
             throw "the game has ende there are no more cards to play" ;
        }
        if(&this->p1 == &this->p2)
        {
            throw "player can not play agenst himself"; 
        }
        string log;
        //draw 
        if(this->p1.get_deck()[this->current_hand].get_card_num() == this->p2.get_deck()[this->current_hand].get_card_num())
        {
            this->draw_count ++;
            string string_log = p1.get_name() + " played " + this->p1.get_deck()[this->current_hand].print() +" "+
                                        p2.get_name() + " played " + this->p2.get_deck()[this->current_hand].print() + ". " + "Draw. ";
            // add to main log
            this->game_log.push_back(move(string_log));
            //case one draw in the middel of the game the -3 is to make shore there will be one more open card !!
            if(this->current_hand <= (this->deck.size()/2) -3)
            {
                // ++ current_hand
                this->current_hand = this->current_hand + 2;
                //set player hand
                this->p1.set_hand(this->current_hand);
                this->p2.set_hand(this->current_hand);
                //ever draw adds 4 points to a player
                this->point_set = this->point_set + 4;
                playTurn();
            }
            //draw and at the very end no down faced card
            else if(this->current_hand == (this->deck.size()/2) -1)
            {
                this->p1.set_point(this->point_set/2);
                this->p2.set_point(this->point_set/2);

                this->current_hand ++;

                this->p1.set_hand(this->current_hand);
                this->p2.set_hand(this->current_hand);
                return;
            }
            //draw and there is one faced down card at the very end
            else if(this->current_hand == (this->deck.size()/2) -2)
            {
                this->point_set = this->point_set + 2;
                this->p1.set_point(this->point_set/2);
                this->p2.set_point(this->point_set/2);

                this->current_hand +=2;

                this->p1.set_hand(this->current_hand);
                this->p2.set_hand(this->current_hand);
                return;
            }
        }
        else if((this->p1.get_deck()[this->current_hand].get_card_num() > this->p2.get_deck()[this->current_hand].get_card_num() && this->p2.get_deck()[this->current_hand].get_card_num() != 1)
        || (this->p1.get_deck()[this->current_hand].get_card_num() == 1 && this->p2.get_deck()[this->current_hand].get_card_num() != 2)
        || (this->p1.get_deck()[this->current_hand].get_card_num() == 2 && this->p2.get_deck()[this->current_hand].get_card_num() == 1))
        // || (p1_card == 1 && p1_card != 2) ||())
        {
            // update log
            //  Alice played Queen of Hearts Bob played 5 of Spades. Alice wins. //example
            string string_log = p1.get_name() + " played " + this->p1.get_deck()[this->current_hand].print() +" "+
                                     p2.get_name() + " played " + this->p2.get_deck()[this->current_hand].print() + ". " +
                                     p1.get_name() + " wins.";
            // cout << string_log << endl;
            // add to main log
            this->game_log.push_back(move(string_log));
            // ++ current_hand
            this->current_hand = this->current_hand + 1;
            //set player hand
            this->p1.set_hand(this->current_hand);
            this->p2.set_hand(this->current_hand);
            // add points
            this->p1.set_point(this->point_set);
            // if i got here to setting a point that meens that if there was a draw there isnt one 
            if(this->point_set != 2)
            {
                this->point_set = 2;
            }
        }
        // p2 win this turn
        else if((this->p2.get_deck()[this->current_hand].get_card_num() > this->p1.get_deck()[this->current_hand].get_card_num() && this->p1.get_deck()[this->current_hand].get_card_num() != 1)
        || (this->p2.get_deck()[this->current_hand].get_card_num() == 1 && this->p1.get_deck()[this->current_hand].get_card_num() != 2)
        || (this->p2.get_deck()[this->current_hand].get_card_num() == 2 && this->p1.get_deck()[this->current_hand].get_card_num() == 1))
        {
            //update log
            // Alice played Queen of Hearts Bob played 5 of Spades. Alice wins. //example
            string string_log = p1.get_name() + " played " + this->p1.get_deck()[this->current_hand].print() +" "+
                                        p2.get_name() + " played " + this->p2.get_deck()[this->current_hand].print() + ". " +
                                        p2.get_name() + " wins.";
            // cout << string_log << endl;
            //add to main log
            this->game_log.push_back(move(string_log));
            // ++ current_hand
            this->current_hand = this->current_hand + 1;
            //set player hand
            this->p1.set_hand(this->current_hand);
            this->p2.set_hand(this->current_hand);
            // add points
            this->p2.set_point(this->point_set);
            // if i got here to setting a point that meens that if there was a draw there isnt one 
            if(this->point_set != 2)
            {
                this->point_set = 2;
            }
        }
    }
    void Game::printLastTurn()
    {
        // at the end of the log there will always be a win but there might be a draw one before 
        unsigned long int index;
        if(this->game_log.size() == 1)
        {
            index =this->game_log.size()-1;
        }
        if(this->game_log.size() >= 2)
        {
            index =this->game_log.size()-2;
        }
        string log = this->game_log[index];
        while (log.substr(log.length() - 6) == "Draw. " && index > 0)
        {
            index = index-1;
            log = this->game_log[index];
        }
        if (index == 0)
        {
            index --;
        }
        for(unsigned long int i = index+1; i < this->game_log.size(); i++)
        {
            cout << this->game_log[i];
        }
        cout << endl;
    } 
    void Game::playAll()
    {
        while (this->current_hand < (this->deck.size()/2))
        {
            // cout << this->current_hand << "    " << this->deck.size()/2 << endl;
            this->playTurn();
            // cout<< "p1 points " <<this->get_p1().get_points() << endl;
            // cout<< "p2 points " <<this->get_p2().get_points() << endl;
            // this->printLog();
            // cout << endl;
        }
    }
    void Game::printWiner()
    {
        if(this->p1.get_points() < this->p2.get_points())
        {
            cout << this->p2.get_name() << endl;
        }
        else if(this->p1.get_points() > this->p2.get_points())
        {
            cout << this->p1.get_name() << endl;
        }
        else
        {
            cout << "The points are equal there is no winner" << endl;
        }
    }
    void Game::printLog()
    {
        for(unsigned long int i = 0; i < this->game_log.size();i++)
        {
            string log = this->game_log[i];
            if(log.substr(log.length() - 6) == "Draw. ")
            {
                cout << log;
            }
            else
            {
                cout << log << endl;
            }
            if(i == this->game_log.size()-1 && log.substr(log.length() - 6) == "Draw. ")
            {
                cout << endl;
            }
        }
    }
    // for each player prints basic statistics: win rate, cards won, <other stats you want to print>. 
    // Also print the draw rate and amount of draws that happand. 
    // (draw within a draw counts as 2 draws. )
    int round(int i)
    {
        if(i < 0)
        {
            return 0;
        }
        else
        {
            return i;
        }
    }
    void Game::printStats()
    {
        //all hands = current hand +1
        double all_hands = this->current_hand;
        all_hands-=this->draw_count;

        // win rate = point/2 out of all the hands 
        int test =(this->p1.get_points()/2 - this->draw_count);
        cout << this->p1.get_name() << " won: " << round(this->p1.get_points()/2 - this->draw_count) << " hands out of " << all_hands 
        << ", witch is " << (((this->p1.get_points()/2)-this->draw_count)/all_hands)*100 << " persent." << endl;

        cout << this->p2.get_name() << " won: " << round(this->p2.get_points()/2 - this->draw_count) << " hands out of " << all_hands 
        << ", witch is " << (((this->p2.get_points()/2)-this->draw_count)/all_hands)*100 << " persent." << endl;

        //cards won = points
        cout << this->p1.get_name() << " won: " << this->p1.get_points() << " cards" << endl;
        cout << this->p2.get_name() << " won: " << this->p2.get_points() << " cards" << endl;
        //draw rate = draw count out of all hands
        cout << "Draw rate of this game is " << this->draw_count << " out of " << all_hands << " witch is " << 
        this->draw_count/all_hands*100 << " persent" << endl;
        //amount of draw = count
        cout << "Draw count is " << this->draw_count << endl;
    }
    vector<card> test_deck()
    {
        vector<card> deck;
        vector<string> symbols{"Heart", "Diamond", "Spade", "Club"};
        unsigned long int loc = 0;
        // //0
        // deck.push_back(card(2,"Heart"));
        // deck.push_back(card(4,"Club"));
        //1
        deck.push_back(card(5,"Club"));
        deck.push_back(card(5,"Club"));
        //2
        deck.push_back(card(2,"Club"));//
        deck.push_back(card(3,"Club"));//
        //3
        deck.push_back(card(12,"Club"));
        deck.push_back(card(12,"Club"));
        //4
        deck.push_back(card(5,"Club"));//
        deck.push_back(card(13,"Club"));//
        //5
        deck.push_back(card(3,"Club"));
        deck.push_back(card(7,"Club"));
        //6
        deck.push_back(card(3,"Club"));
        deck.push_back(card(6,"Club"));
        //7
        deck.push_back(card(5,"Club"));
        deck.push_back(card(6,"Club"));
        //8
        deck.push_back(card(11,"Club"));
        deck.push_back(card(1,"Club"));
        //9
        deck.push_back(card(10,"Club"));
        deck.push_back(card(8,"Club"));


        //10
        deck.push_back(card(13,"Club"));
        deck.push_back(card(12,"Club"));
        //11
        deck.push_back(card(8,"Club"));
        deck.push_back(card(8,"Club"));
        //12
        deck.push_back(card(13,"Club"));//
        deck.push_back(card(5,"Club"));//
        //13
        deck.push_back(card(10,"Club"));
        deck.push_back(card(13,"Club"));
        //14
        deck.push_back(card(7,"Club"));
        deck.push_back(card(11,"Club"));
        //15
        deck.push_back(card(9,"Club"));
        deck.push_back(card(3,"Club"));
        //16
        deck.push_back(card(2,"Club"));
        deck.push_back(card(1,"Club"));


        //17
        deck.push_back(card(11,"Club"));
        deck.push_back(card(6,"Club"));
        //18
        deck.push_back(card(3,"Club"));
        deck.push_back(card(13,"Club"));
        //19
        deck.push_back(card(2,"Club"));
        deck.push_back(card(9,"Club"));
        //20
        deck.push_back(card(4,"Club"));
        deck.push_back(card(1,"Club"));
        //21
        deck.push_back(card(2,"Club"));
        deck.push_back(card(13,"Club"));
        //22
        deck.push_back(card(9,"Club"));
        deck.push_back(card(6,"Club"));
        //23
        deck.push_back(card(1,"Club"));
        deck.push_back(card(7,"Club"));
        //24
        deck.push_back(card(4,"Club"));
        deck.push_back(card(4,"Club"));
        //25
        deck.push_back(card(5,"Club"));//
        deck.push_back(card(13,"Club"));//
        //26
        deck.push_back(card(12,"Club"));
        deck.push_back(card(10,"Club"));
        return deck;
    }
    vector<card> creat_deck()
    {
        vector<card> deck;
        vector<string> symbols{"Heart", "Diamond", "Spade", "Club"};
        unsigned long int loc = 0;
        for (int i = 1; i <= 13; i++)
        {
            for (const auto &symbol : symbols)
            {
                card temp(i, symbol);
                deck.push_back(card(temp));
                loc++;
                // deck.push_back(temp.copy());
            }
        }
        random_device rd;
        mt19937 g(rd());
        shuffle(deck.begin(), deck.end(), g);
        return deck;
    }
    void devide_cards(Player& p1, Player& p2, std::vector<card>& deck)
    {
        vector<card> deck_p1;
        vector<card> deck_p2;
        for (unsigned long int i = 0; i < deck.size(); i++)
        {
            if (i % 2 == 0)
            {
                deck_p1.push_back(deck[i]);
            }
            else
            {
                deck_p2.push_back(deck[i]);
            }
        }
        p1.set_deck(deck_p1);
        // for(ariel::card& c : p1.get_deck())
        // {
        //     std::cout << c.print() << std::endl;
        // }
        p2.set_deck(deck_p2);
        // for(ariel::card& c : p2.get_deck())
        // {
        //     std::cout << c.print() << std::endl;
        // }
    }
    Game::Game(Player& p1, Player& p2): p1(p1),p2(p2)
    {
        // this->p1 = Player(p1);
        // this->p2 = Player(p2);
        if(this->p1.get_state() == true || this->p2.get_state() == true)
        {
            throw "one of the players is currently playing a game and can not join this one" ;
        }
        this->current_hand = 0;
        this->draw_count = 0;
        this->point_set = 2;
        this->deck = creat_deck();
        // this->deck = test_deck();
        this->p1.set_state(true);
        this->p2.set_state(true);
        devide_cards(this->p1, this->p2, this->deck);
    }
    Game::~Game()
    {
        this->p1.set_state(false);
        this->p2.set_state(false);
    }
    //tidy
    //Copy Constructor
    Game::Game(const Game& other) :
    p1(other.p1),
    p2(other.p2),
    game_log(other.game_log),
    deck(other.deck),
    current_hand(other.current_hand),
    point_set(other.point_set),
    draw_count(other.draw_count)
    {
    }
    //Copy Assignment Operator
    Game& Game::operator=(const Game& other)
    {
        if(this != &other)
        {
            this->p1 = other.p1;
            this->p2 = other.p2;
            this->game_log = other.game_log;
            this->deck = other.deck;
            this->current_hand = other.current_hand;
            this->point_set = other.point_set;
            this->draw_count = other.draw_count;
        }
        return *this;
    }
    //Move Constructor
    Game::Game(Game&& other) noexcept:
    p1(other.p1),
    p2(other.p2),
    game_log(move(other.game_log)),
    deck(move(other.deck)),
    current_hand(other.current_hand),
    point_set(other.point_set),
    draw_count(other.draw_count)
    {
        other.current_hand = 0;
        other.point_set = 0;
        other.draw_count = 0;
    }  
    //Move Assignment Operator
    Game& Game::operator=(Game&& other) noexcept
    {
        if(this != &other)
        {
            this->p1 = other.p1;
            this->p2 = other.p2;
            this->game_log = move(other.game_log);
            this->deck = move(other.deck);
            this->current_hand = other.current_hand;
            this->point_set = other.point_set;
            this->draw_count = other.draw_count;

            other.current_hand = 0;
            other.point_set = 0;
            other.draw_count = 0;
        }
        return *this;
    }
}