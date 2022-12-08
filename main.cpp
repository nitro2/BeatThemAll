#include <iostream>

#include "player.hpp"

int main()
{
    std::cout << "BeatThemAll" << std::endl;
    Player p1 = Player(Player::CHARACTER_TYPE::WARRIOR);
    Player p2 = Player(Player::CHARACTER_TYPE::WIZARD);
    // p1.printStat();
    // p1.takeDamage(p1.getAttack());
    // p1.printStat();
    p1.test();
    return 0;
}