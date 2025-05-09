#include "board.hpp"



Board::Board(const std::string& BOARD_PATH, const std::string& LIGHT_CELL_PATH ,
const std::string& DARK_CELL_PATH, const float CELL_SIZE, sf::Vector2f BOARD_SIZE,sf::Vector2u  window_size, bool user_figure_color)

: c_cell_size(CELL_SIZE), c_user_figure_color(user_figure_color), c_window_size(window_size), c_board_size(BOARD_SIZE)
{
    if (!c_board_t.loadFromFile(BOARD_PATH)) 
    throw std::runtime_error ("Can't load file from " + BOARD_PATH + ". Check the correct file name.");
    if (!c_dark_cell_t.loadFromFile(DARK_CELL_PATH))
    throw std::runtime_error("Can't load file from " + DARK_CELL_PATH + ". Check the correct file name.");
    if (!c_light_cell_t.loadFromFile(LIGHT_CELL_PATH))
    throw std::runtime_error("Can't load file from " + LIGHT_CELL_PATH + ". Check the correct file name.");
        
    build_field_of_cells();

         
}

void Board::build_field_of_cells()
{
    c_cells_s.clear();
    sf::Vector2f current_cell_pos = set_start_position();
    for (int rows = 0; rows < 8; rows++)
    {
        for (int cols = 0; cols < 8; cols++)
        {
            sf::Sprite cell_sprite;
                    
            bool  layout_board =  ((rows + cols) % 2 == 0) ^ c_user_figure_color; 


            cell_sprite.setTexture((layout_board) ? c_light_cell_t : c_dark_cell_t);
            cell_sprite.setPosition(cols*c_cell_size + current_cell_pos.x + 30, rows*c_cell_size+current_cell_pos.y + 30);

            c_cells_s.push_back(cell_sprite);   
        }
                
    }
}

void Board::display_background_board(sf::RenderWindow& window)
{
    c_background_board_s.setTexture(c_board_t);
    c_background_board_s.setPosition(set_start_position());
    window.draw(c_background_board_s);   
}


void Board::draw_board(sf::RenderWindow& window)
{
    for(const auto& cell : c_cells_s)
    {
        window.draw(cell);
    }                        
}
// for another class(relocate latter)
sf::Vector2f Board::set_start_position()
{
    float pos_x = (c_window_size.x - c_board_size.x) / 2;
    float pos_y = (c_window_size.y - c_board_size.y) / 4; 

    return sf::Vector2f(pos_x, pos_y);
    
}



