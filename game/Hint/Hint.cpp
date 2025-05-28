#include "Hint.hpp"

Hint::Hint(const std::string HINT_PATH, sf::Vector2f SIZE, sf::Vector2i position, sf::Vector2f START_FIGURE_POS) 
: C_SIZE(SIZE), c_position(position), C_START_FIGURE_POS(START_FIGURE_POS)
{
    if (!c_texture_t.loadFromFile(HINT_PATH)) 
    throw std::runtime_error ("Can't load file from " + HINT_PATH + ". Check the correct file name.");

    c_hint_s.setTexture(c_texture_t);
    c_hint_s.setPosition(c_position.x * C_SIZE.x + START_FIGURE_POS.x, c_position.y * C_SIZE.y + START_FIGURE_POS.y);
}
void Hint::draw(sf::RenderWindow& window)
{
    window.draw(c_hint_s);   
}