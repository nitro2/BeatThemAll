#ifndef _GRID_HPP_
#define _GRID_HPP_

#include <SFML/Graphics.hpp>
#include "gameobject.hpp"
/* Create a grid of lines */
class Grid : public sf::Drawable, public sf::Transformable, public GameObject
{
public:
    Grid(sf::Vector2f position, int row_lines, int col_lines, float distance, sf::Color color);
    ~Grid();

    void render(std::shared_ptr<sf::RenderWindow> window);

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};

#endif // _GRID_HPP_
