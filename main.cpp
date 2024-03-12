#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>


int main()
{
    mt::Game game(1200, 1000, "GAME!!!");

    game.setup(5);
    game.lifeCycle();

    return 0;
}