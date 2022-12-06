#include <iostream>

#include "player.hpp"

int main()
{
    std::cout << "BeatThemAll" << std::endl;
    Player p1 = Player(Player::CHARACTER_TYPE::WARRIOR);
    Player p2 = Player(Player::CHARACTER_TYPE::WIZARD);
    return 0;
}