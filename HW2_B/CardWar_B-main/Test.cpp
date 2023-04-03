#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include "sources/player.hpp"
#include "sources/card.hpp"
#include "sources/game.hpp"
#include "doctest.h"

using namespace ariel;
using namespace std;

TEST_CASE("INIT CHECK")
{
    CHECK_NOTHROW(Player p1("zeev")); //1
    CHECK_THROWS(Player {"123"});//2

    Player p1("zeev");
    Player p2("fischer");
    CHECK_NOTHROW(Game game(p1,p2));//3
}
TEST_CASE("PLAYER PLAYING 2 GAMES")
{
    Player p1("one fish");
    Player p2("tew fish");
    Player p3("red fish");
    CHECK_NOTHROW(Game game(p1,p2));//4
    CHECK_THROWS(Game {p1,p2});//5
    CHECK_THROWS(Game {p1,p1});//6
}

TEST_CASE("GMAE FUNCTIONS")
{
    Player p1("HEVEN");
    Player p2("HELL");
    Game game(p1,p2);
    CHECK_NOTHROW(game.playAll());//7
    CHECK_NOTHROW(game.playTurn());//8
    CHECK_NOTHROW(game.printLastTurn());//9
    CHECK_NOTHROW(game.printLog());//10
    CHECK_NOTHROW(game.printStats());//11
    CHECK_NOTHROW(game.printWiner());//12
}
TEST_CASE("PLAYER CARDS")
{
    Player p1("one fisifisi");
    Player p2("tew fisifisi");
    int cards = p1.cardesTaken() + p2.cardesTaken();
    CHECK(cards == 52);//13
    cards = p1.stacksize()+p2.stacksize();
    CHECK(cards == 52);//14
}
TEST_CASE("WINER BEFORE END OF GAME")
{
    Player p1("timon");
    Player p2("pumba");
    Game game(p1,p2);
    CHECK_THROWS(game.printWiner());//15
    game.playAll();
    CHECK_NOTHROW(game.printWiner());//16
}
TEST_CASE("PRINT TURN BEFORE ANY MVOE WAS MADE")
{
    Player p1("mofasa");
    Player p2("scar");
    Game game(p1,p2);
    CHECK_THROWS(game.printLastTurn());//17
    game.playTurn();
    CHECK_NOTHROW(game.printLastTurn());//18
}
TEST_CASE("PRINT LOG BEFORE ANY MOVE WAS MADE")
{
    Player p1("oby one canoby");
    Player p2("darth vader");
    Game game(p1,p2);
    CHECK_THROWS(game.printLog());//19
    game.playAll();
    CHECK_NOTHROW(game.printLog());//20
}

