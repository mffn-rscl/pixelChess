#include "Board.hpp"



Board::Board(const std::string& BOARD_TEXTURE_PATH, const std::string& DARK_CELL_TEXTURE_PATH, const std::string& LIGHT_CELL_TEXTURE_PATH,
            sf::Vector2f BOARD_SIZE,sf::Vector2f CELL_SIZE,const sf::Vector2f START_BOARD_POS, const sf::Vector2f START_CELL_POS)
            : C_BOARD_SIZE(BOARD_SIZE), C_CELL_SIZE(CELL_SIZE), C_START_BOARD_POS(START_BOARD_POS), C_START_CELL_POS(START_CELL_POS)
{

    if (!c_background_board_t.loadFromFile(BOARD_TEXTURE_PATH)) 
    throw std::runtime_error ("Can't load file from " + BOARD_TEXTURE_PATH + ". Check the correct file name.");
    if (!c_dark_cell_t.loadFromFile(DARK_CELL_TEXTURE_PATH))
    throw std::runtime_error("Can't load file from " + DARK_CELL_TEXTURE_PATH + ". Check the correct file name.");
    if (!c_light_cell_t.loadFromFile(LIGHT_CELL_TEXTURE_PATH))
    throw std::runtime_error("Can't load file from " + LIGHT_CELL_TEXTURE_PATH + ". Check the correct file name.");
        
    build_field_of_cells();

         
}

void Board::build_field_of_cells()
{
    c_cells_s.clear();
    for (int rows = 0; rows < 8; rows++)
    {
        for (int cols = 0; cols < 8; cols++)
        {
            sf::Sprite cell_sprite;
                    
            bool  layout_board = (rows + cols) % 2 == 0; 


            cell_sprite.setTexture((layout_board) ? c_light_cell_t : c_dark_cell_t);
            cell_sprite.setPosition(cols * C_START_CELL_POS.x, rows * C_START_CELL_POS.y);

            c_cells_s.push_back(cell_sprite);   
        }
                
    }
}

void Board::display_background_board(sf::RenderWindow& window)
{
    c_background_board_s.setTexture(c_background_board_t);
    c_background_board_s.setPosition(C_START_BOARD_POS);
    window.draw(c_background_board_s);   
}


void Board::draw_board(sf::RenderWindow& window)
{
    for(const auto& cell : c_cells_s)
    {
        window.draw(cell);
    }                        
}



