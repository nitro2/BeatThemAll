#include "grid.hpp"

/*
    Eg: width = 3 tiles, height = 1 tile
    | | | |
*/
Grid::Grid(sf::Vector2f position, int row_lines, int col_lines, float distance, sf::Color color)
{
    m_vertices.setPrimitiveType(sf::Lines);
    m_vertices.resize((row_lines + col_lines) * 2); // Each line has 2 point

    auto width = (col_lines - 1) * distance;
    auto height = (row_lines - 1) * distance;

    // Draw row lines
    for (auto i = 0; i < row_lines; i++)
    {
        /*
            For a line AB:  A --------- B
        */
        // Point A of line
        m_vertices[i * 2].color = color;
        m_vertices[i * 2].position = sf::Vector2f(position.x, position.y + i * distance);
        // Point B of line
        m_vertices[i * 2 + 1].color = color;
        m_vertices[i * 2 + 1].position = sf::Vector2f(position.x + width, position.y + i * distance);
    }

    // Draw column lines
    for (auto i = 0; i < col_lines; i++)
    {
        /*
            For a line AB:
             A
             |
             |
             B
        */
        // Point A of line
        m_vertices[row_lines * 2 + i * 2].color = sf::Color::Black;
        m_vertices[row_lines * 2 + i * 2].position = sf::Vector2f(position.x + i * distance, position.y);
        // Point B of line
        m_vertices[row_lines * 2 + i * 2 + 1].color = sf::Color::Black;
        m_vertices[row_lines * 2 + i * 2 + 1].position = sf::Vector2f(position.x + i * distance, position.y + height);
    }
}

Grid::~Grid()
{
}

void Grid::render(std::shared_ptr<sf::RenderWindow> window)
{
    window->draw(*this);
}

void Grid::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // apply the transform
    states.transform *= getTransform();

    // apply the tileset texture
    states.texture = &m_tileset;

    // draw the vertex array
    target.draw(m_vertices, states);
}