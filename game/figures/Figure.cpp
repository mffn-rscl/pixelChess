#include "Figure.hpp"

Figure::Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
       FigureType type, FigureColor color)
      : C_CELL_TEXTURE_SIZE(CELL_TEXTURE_SIZE),C_START_FIGURE_POS(START_FIGURE_POS), c_type(type),
         c_color(color)      
{
    if (!c_figure_t.loadFromFile(FIGURE_PATH)) 
    throw std::runtime_error ("Can't load file from " + FIGURE_PATH + ". Check the correct file name.");
    c_figure_s.setTexture(c_figure_t);

    c_is_alive = true;
}


Figure::~Figure() {}
    

void Figure::set_board_position(sf::Vector2i board_position)
{
    c_board_position.x = board_position.x;
    c_board_position.y = board_position.y;
    set_pixel_position();
}


void Figure::set_pixel_position()
{   
    c_pixel_position.x = C_START_FIGURE_POS.x + C_CELL_TEXTURE_SIZE.x * c_board_position.x;
    c_pixel_position.y = C_START_FIGURE_POS.y + C_CELL_TEXTURE_SIZE.y * c_board_position.y;

    c_figure_s.setPosition(c_pixel_position.x, c_pixel_position.y);
}

void Figure::sam_is_dead() { c_is_alive = false; }



void Figure::draw(sf::RenderWindow& window)
{
    window.draw(c_figure_s);
}

void Figure::set_playing_field(const FigureType playing_field[8][8]) {c_playing_field = playing_field;} // !


//get
FigureColor Figure::get_color() const { return c_color; } 
FigureType Figure::get_figure_type() const { return c_type; }
sf::Vector2i Figure::get_board_pos() const { return c_board_position; }
sf::Vector2f Figure::get_pixel_pos() const { return  c_pixel_position; } 
bool Figure::is_alive() const { return c_is_alive;}

