#include "Pawn.hpp"


Pawn::~Pawn(){}

bool Pawn::get_is_first_move() const { return c_is_first_move; }

void Pawn::is_not_first_move() { c_is_first_move = false; }

bool Pawn::is_current_move(sf::Vector2i mouse_clicked_pos)
{
    std::vector<sf::Vector2i> possible_moves = get_possible_moves();
    for(auto moves : possible_moves)
    {
        if (moves == mouse_clicked_pos) 
        {
            c_is_first_move = false;
            return true;
        }
    }
    return false;
} 

std::vector<sf::Vector2i> Pawn::get_possible_moves()
{
    std::vector<sf::Vector2i> moves;

    int direction = (get_color() == FigureColor::LIGHT) ? -1 : 1;
    int start_row_pos = (get_color() == FigureColor::LIGHT) ? 6 : 1;
    int current_x = c_board_position.x;
    int current_y = c_board_position.y;

    int next_move_y = current_y + direction;

    if (is_valid_position(current_x , next_move_y) && c_playing_field[current_x][next_move_y] == FigureType::EMPTY)
    {
        moves.push_back(sf::Vector2i(current_x, next_move_y));

        if (current_y == start_row_pos)
        {
           int next_double_move_y = current_y + 2 * direction;   

           if (is_valid_position(current_x , next_double_move_y) && c_playing_field[current_x][next_double_move_y] == FigureType::EMPTY)
           {
                moves.push_back(sf::Vector2i(current_x, next_double_move_y));
           }
        }
    }
    
    
    return moves;
}


