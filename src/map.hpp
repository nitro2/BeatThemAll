#ifndef _MAP_HPP_
#define _MAP_HPP_

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"
#include "wall.hpp"

class Map : public GameObject
{
public:
    Map(float width, float height);
    ~Map();

    void loadMap(const std::string mapFile, bool visibleWall);
    void render(std::shared_ptr<sf::RenderWindow> window);

private:
    sf::Texture texture;
    std::shared_ptr<sf::Sprite> background;
    std::vector<std::shared_ptr<Wall>> wallList;
};

#endif // _MAP_HPP_
