#include "Pawn.hpp"


Pawn::~Pawn(){}



std::vector<sf::Vector2i> Pawn::find_moves(Board& board)
{
    //cleaning up previous moves
    c_current_moves.clear();

    int direction = (get_color() == FigureColor::LIGHT) ? -1 : 1;
    int start_row_pos = (get_color() == FigureColor::LIGHT) ? 6 : 1;
    int current_x = c_board_position.x;
    int current_y = c_board_position.y;

    int next_move_y = current_y + direction;

    if (is_valid_position(current_x , next_move_y) && board.get_figure_type(sf::Vector2i(current_x, next_move_y)) == FigureType::EMPTY)
    {
        c_current_moves.push_back(sf::Vector2i(current_x, next_move_y));

        if (current_y == start_row_pos)
        {
           int next_double_move_y = current_y + 2 * direction;   

           if (is_valid_position(current_x , next_double_move_y) 
           && board.get_figure_type(sf::Vector2i(current_x, next_double_move_y)) == FigureType::EMPTY
           && board.get_figure_type(sf::Vector2i(current_x, next_move_y)) == FigureType::EMPTY)
           {
                c_current_moves.push_back(sf::Vector2i(current_x, next_double_move_y));
           }
        }
    }

    //beating figure

    
    if (is_valid_position(current_x-1 , next_move_y))
    {
        c_current_moves.push_back(sf::Vector2i(current_x-1, next_move_y));
    }
    if (is_valid_position(current_x+1 , next_move_y))
    {
        c_current_moves.push_back(sf::Vector2i(current_x+1, next_move_y));
    }
    
    
    
    
    return c_current_moves;
}


