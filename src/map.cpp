#include <fstream>
#include <sstream>
#include "map.hpp"

Map::Map(float width, float height)
    : GameObject(0, 0, width, height)
{
    this->background = std::make_shared<sf::Sprite>();
}

Map::~Map()
{
}

/*
    Map file format:
        path-to-background-image (image inside assets/background)
        2 (Number of walls)
        800 800 500 400    (x,y,width,height of a wall)
        100 200 500 400    (x,y,width,height of a wall)
*/
void Map::loadMap(const std::string mapFile, bool visibleWall)
{
    std::ifstream file(mapFile);
    if (file.is_open())
    {
        std::string line;

        // Load background image
        if (!std::getline(file, line))
        {
            throw std::runtime_error("Invalid map file - background");
        }
        this->texture.loadFromFile(line);
        this->background->setTexture(texture);
        this->background->setScale(this->width / this->texture.getSize().x, this->height / this->texture.getSize().y);

        // Load number of walls
        if (!std::getline(file, line))
        {
            throw std::runtime_error("Invalid map file - num walls");
        }
        std::istringstream iss(line);
        int N = 0;
        if (!(iss >> N))
        {
            throw std::runtime_error("Invalid map file - num walls");
        }

        for (int i = 0; i < N; i++)
        {
            if (!std::getline(file, line))
            {
                throw std::runtime_error("Invalid map file - wall parameters");
            }
            std::istringstream iss(line);
            int x, y, w, h;
            if (!(iss >> x >> y >> w >> h))
            {
                throw std::runtime_error("Invalid map file - wall parameters");
            }
            sf::Color color;
            if (visibleWall)
            {
                color = sf::Color(sf::Color::Green);
            }
            else
            {
                color = sf::Color(sf::Color::Transparent);
            }
            auto wall = std::make_shared<Wall>(static_cast<float>(x), static_cast<float>(y), static_cast<float>(w), static_cast<float>(h), color);
            this->wallList.push_back(wall);
        }
        file.close();
    }
}

void Map::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*this->background);
    for (auto &w : wallList)
    {
        w->render(window);
    }
}

std::vector<std::shared_ptr<Wall>> Map::getWallList()
{
    return this->wallList;
}