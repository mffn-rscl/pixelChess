#include "Pawn.hpp"

Pawn::Pawn(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
    sf::Vector2i board_position, FigureType type, FigureColor color)
    : Figure(FIGURE_PATH, CELL_TEXTURE_SIZE,START_FIGURE_POS, board_position, type, color)
{
            c_is_moved = false;
            set_pixel_position();
}


void Pawn::set_board_position(int x, int y)
{
    c_board_position.x = x;
    c_board_position.y = y;
}
void Pawn::set_pixel_position()
{
    c_figure_s.setPosition(C_START_FIGURE_POS.x + C_CELL_TEXTURE_SIZE.x * c_board_position.x, C_START_FIGURE_POS.y + C_CELL_TEXTURE_SIZE.y * c_board_position.y);
}

void Pawn::draw(sf::RenderWindow& window)
{
    window.draw(c_figure_s);
}

//get
FigureColor Pawn::get_color() const { return c_color; } 
FigureType Pawn::get_figure_type() const { return c_type; }
sf::Vector2i Pawn::get_board_pos() const { return c_board_position; }
sf::Vector2f Pawn::get_pixel_pos() const { return  c_pixel_position; } 