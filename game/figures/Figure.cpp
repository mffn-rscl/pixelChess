#include "Figure.hpp"

Figure::Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
       FigureType type, FigureColor color)
      : C_CELL_TEXTURE_SIZE(CELL_TEXTURE_SIZE),C_START_FIGURE_POS(START_FIGURE_POS), c_type(type),
         c_color(color)      
{
    if (!c_figure_t.loadFromFile(FIGURE_PATH)) 
    throw std::runtime_error ("Can't load file from " + FIGURE_PATH + ". Check the correct file name.");
    c_figure_s.setTexture(c_figure_t);

    set_is_moved(false);

}

Figure::~Figure() {}

    

void Figure::set_figure_position(sf::Vector2i board_position)
{
    c_board_position.x = board_position.x;
    c_board_position.y = board_position.y;
   
    c_pixel_position.x = C_START_FIGURE_POS.x + C_CELL_TEXTURE_SIZE.x * c_board_position.x;
    c_pixel_position.y = C_START_FIGURE_POS.y + C_CELL_TEXTURE_SIZE.y * c_board_position.y;

    c_figure_s.setPosition(c_pixel_position.x, c_pixel_position.y);
}

void Figure::set_current_moves(std::vector<sf::Vector2i> moves) { c_current_moves = moves; }

bool Figure::is_valid_position(int x, int y) const { return x >= 0 && x < 8 && y >= 0 && y < 8; }

void Figure::draw(sf::RenderWindow& window)
{
    window.draw(c_figure_s);
}


void Figure::set_is_moved(bool set) { c_is_moved = set; }



//get
std::vector<sf::Vector2i> Figure::get_current_moves() const { return c_current_moves; } 
FigureColor Figure::get_color() const { return c_color; } 
FigureType Figure::get_figure_type() const { return c_type; }
sf::Vector2i Figure::get_board_pos() const { return c_board_position; }
sf::Vector2f Figure::get_pixel_pos() const { return  c_pixel_position; } 



