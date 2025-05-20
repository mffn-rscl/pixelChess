#include "Pawn.hpp"


Pawn::~Pawn(){}

bool Pawn::get_is_first_move() const { return c_is_first_move; }

void Pawn::is_not_first_move() {c_is_first_move = false;}

bool Pawn::is_current_move(sf::Vector2i mouse_clicked_pos)
{
    for(auto moves : get_possible_moves())// !
    {
        if (moves == mouse_clicked_pos)return true;
        
    }
    return false;
}

std::vector<sf::Vector2i> Pawn::get_possible_moves(const FigureType playing_field[8][8])
{
    //add beating figures

    std::vector<sf::Vector2i> moves;
  
    switch (get_color())
    {
    case FigureColor::LIGHT:
        if (playing_field[c_board_position.x][c_board_position.y--] == FigureType::EMPTY && c_board_position.y>1)
            moves.push_back(sf::Vector2i(c_board_position.x, c_board_position.y--));

        if (playing_field[c_board_position.x][c_board_position.y-2] == FigureType::EMPTY && c_is_first_move)
            moves.push_back(sf::Vector2i(c_board_position.x, c_board_position.y-2));

        break; 
        
    case FigureColor::DARK:
        if (playing_field[c_board_position.x][c_board_position.y++] == FigureType::EMPTY && c_board_position.y<8)
            moves.push_back(sf::Vector2i(c_board_position.x, c_board_position.y++));

        if (playing_field[c_board_position.x][c_board_position.y+2] == FigureType::EMPTY && c_is_first_move)
            moves.push_back(sf::Vector2i(c_board_position.x, c_board_position.y+2));
        break;
    }
    
    return moves;
}


