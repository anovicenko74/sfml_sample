#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>
#include <cstdlib>  

int main()
{
    std::system("chcp 1251");

    mt::Game game(600, 600, "GAME!!!");

    game.setup(3);
    game.lifeCycle();

    return 0;
}