#include <iostream>

#include "game.hpp"

int main(int argc, char *argv[])
{
    std::cout << "BeatThemAll" << std::endl;
    // Player p1 = Player(Player::CHARACTER_TYPE::WARRIOR);
    // Player p2 = Player(Player::CHARACTER_TYPE::WIZARD);
    // p1.printStat();
    // p1.takeDamage(p1.getAttack());
    // p1.printStat();
    // p1.test();

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    std::cout << argv[0] << std::endl;

    Game game = Game();
    game.run();

    return 0;
}