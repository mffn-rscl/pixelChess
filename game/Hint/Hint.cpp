#include "Hint.hpp"

Hint::Hint(const std::string HINT_PATH, sf::Vector2f SIZE, sf::Vector2f START_FIGURE_POS, sf::Vector2i position) 
: C_SIZE(SIZE), c_position(position), C_START_FIGURE_POS(START_FIGURE_POS)
{
    if (!c_texture_t.loadFromFile(HINT_PATH)) 
    throw std::runtime_error ("Can't load file from " + HINT_PATH + ". Check the correct file name.");

    c_hint_s.setTexture(c_texture_t);

}
void Hint::draw(sf::RenderWindow& window)
{
    window.draw(c_hint_s);   
}

void Hint::set_hint_position()
{
    c_hint_s.setPosition(C_START_FIGURE_POS.x + C_SIZE.x * c_position.x, C_START_FIGURE_POS.y + C_SIZE.y * c_position.y);
}

void Hint::set_hint_position(sf::Vector2i pos)
{
    c_hint_s.setPosition(C_START_FIGURE_POS.x + C_SIZE.x * pos.x, C_START_FIGURE_POS.y + C_SIZE.y * pos.y);
}