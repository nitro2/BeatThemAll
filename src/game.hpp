#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Game
{
public:
    Game();
    ~Game();

    void update();
    void draw();
    void run();

private:
    std::shared_ptr<sf::RenderWindow> window;
    std::vector<std::shared_ptr<sf::Drawable>> drawable_obj_list;
};

#endif // _GAME_HPP_
