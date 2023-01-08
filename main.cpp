#include <iostream>
#include <memory>

#include "game.hpp"
#include "select_character_screen.hpp"

int main(int argc, char *argv[])
{
    std::cout << "BeatThemAll" << std::endl;

    std::cout << __FUNCTION__ << " at line " << __LINE__ << std::endl;
    std::cout << argv[0] << std::endl;

    //Game game = Game();
    //game.run();

    SelectCharacterScreen scs = SelectCharacterScreen();
    scs.init();
    scs.run();

    //std::unique_ptr<SelectCharacterScreen> scs = std::make_unique<SelectCharacterScreen>();
    //scs->init();
    //scs->run();

    return 0;
}