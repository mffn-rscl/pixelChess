#include "Figure.hpp"

Figure::Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
     sf::Vector2i board_position, FigureType type, FigureColor color)
      : C_CELL_TEXTURE_SIZE(CELL_TEXTURE_SIZE),C_START_FIGURE_POS(START_FIGURE_POS), c_board_position(board_position), c_type(type),
         c_color(color)
        
        {
            if (!c_figure_t.loadFromFile(FIGURE_PATH)) 
            throw std::runtime_error ("Can't load file from " + FIGURE_PATH + ". Check the correct file name.");
            c_figure_s.setTexture(c_figure_t);
        }



void Figure::set_board_position(int x, int y)
{
    c_board_position.x = x;
    c_board_position.y = y;
}
void Figure::set_pixel_position()
{
    c_figure_s.setPosition(C_START_FIGURE_POS.x + C_CELL_TEXTURE_SIZE.x * c_board_position.x, C_START_FIGURE_POS.y + C_CELL_TEXTURE_SIZE.y * c_board_position.y);
}

void Figure::draw(sf::RenderWindow& window)
{
    window.draw(c_figure_s);
}


//get
FigureColor Figure::get_color() const { return c_color; } 
FigureType Figure::get_figure_type() const { return c_type; }
sf::Vector2i Figure::get_board_pos() const { return c_board_position; }
sf::Vector2f Figure::get_pixel_pos() const { return  c_pixel_position; } 