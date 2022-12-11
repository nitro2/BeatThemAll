#include <iostream>

#include "game.hpp"

int main(int argc, char *argv[])
{
    std::cout << "BeatThemAll" << std::endl;

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    std::cout << argv[0] << std::endl;

    Game game = Game();
    game.run();

    return 0;
}