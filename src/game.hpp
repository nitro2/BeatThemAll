#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "player.hpp"
class Game
{
public:
    Game();
    ~Game();

    std::shared_ptr<Player> addPlayer(std::string name);
    void update(float deltaTime);
    void draw();
    void run();

private:
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<std::shared_ptr<sf::Drawable>> drawable_obj_list;
    std::vector<std::shared_ptr<Player>> player_list;
};

#endif // _GAME_HPP_
