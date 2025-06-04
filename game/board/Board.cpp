#include "Board.hpp"



Board::Board(const std::string& BOARD_TEXTURE_PATH, const sf::Vector2f BOARD_SIZE,const sf::Vector2f START_BOARD_POS)
            : C_BOARD_SIZE(BOARD_SIZE), C_START_BOARD_POS(START_BOARD_POS)
{

    if (!c_background_board_t.loadFromFile(BOARD_TEXTURE_PATH)) 
    throw std::runtime_error ("Can't load file from " + BOARD_TEXTURE_PATH + ". Check the correct file name.");
   
    c_background_board_s.setTexture(c_background_board_t);
    c_background_board_s.setPosition(C_START_BOARD_POS);
         
}

Board::Board() 
{
    initialize_playing_field();
}

void Board::initialize_playing_field()
{
    c_playing_field[0][0] = FigureType::ROOK;
    c_playing_field[0][1] = FigureType::KNIGHT;
    c_playing_field[0][2] = FigureType::BISHOP;
    c_playing_field[0][3] = FigureType::QUEEN;
    c_playing_field[0][4] = FigureType::KING;
    c_playing_field[0][5] = FigureType::BISHOP;
    c_playing_field[0][6] = FigureType::KNIGHT;
    c_playing_field[0][7] = FigureType::ROOK;

    c_playing_field[7][0] = FigureType::ROOK;
    c_playing_field[7][1] = FigureType::KNIGHT;
    c_playing_field[7][2] = FigureType::BISHOP;
    c_playing_field[7][3] = FigureType::QUEEN;
    c_playing_field[7][4] = FigureType::KING;
    c_playing_field[7][5] = FigureType::BISHOP;
    c_playing_field[7][6] = FigureType::KNIGHT;
    c_playing_field[7][7] = FigureType::ROOK;

    for (int cols = 0; cols < 8; cols++) 
    { 
        c_playing_field[1][cols] = FigureType::PAWN; 
        c_playing_field[6][cols] = FigureType::PAWN; 
    }
    for (int rows = 2; rows < 6; rows++)
    {
        for (int cols = 0; cols < 8; cols++)
        {
            c_playing_field[rows][cols] = FigureType::EMPTY;
        }
    }
}

// logs
void Board::display_playing_field()
{
    for (int  i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            std::cout << static_cast<int>(c_playing_field[i][j]) << " ";
        }
        std::cout << std::endl;
    }
    
}


FigureType Board::get_figure_type(sf::Vector2i pos)
{
    return c_playing_field[pos.y][pos.x];
}

void Board::set_figure_type(sf::Vector2i pos, FigureType type)
{
    c_playing_field[pos.y][pos.x] = type; 
}


void Board::draw(sf::RenderWindow& window)
{
    window.draw(c_background_board_s);   
}




