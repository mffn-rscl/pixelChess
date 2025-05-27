#include "Knight.hpp"

Knight::~Knight(){}

std::vector<sf::Vector2i> Knight::get_possible_moves() 
{
    std::vector<sf::Vector2i> moves;
    sf::Vector2i current_move;
    for (int i = 0; i < 8; i++)
    {
        if(i < 4)
        {
            if(i % 2 == 0)
            {
                current_move = sf::Vector2i( --c_board_position.x, ((i == 0) ? 2 : -2) + c_board_position.y);
            }
            else
            {
                current_move = sf::Vector2i( ((i == 1) ? 2 : -2) + c_board_position.x, --c_board_position.y);
            }
        }   
        else
        {
            if(i % 2 == 0)
            {
                current_move = sf::Vector2i( ++c_board_position.x, ((i == 4) ? 2 : -2) + c_board_position.y);

            }
            else
            {
                current_move = sf::Vector2i( ((i == 5) ? 2 : -2) + c_board_position.x, ++c_board_position.y);
            }
        }  

    if(current_move.x>0 && current_move.x<=8 && current_move.y>0 && current_move.y<=8) moves.push_back(current_move);
    }
    
    return moves;

}
bool Knight::is_current_move(sf::Vector2i mouse_clicked_pos) 
{
    std::vector<sf::Vector2i> possible_moves = get_possible_moves();
    // if (possible_moves.empty()) return false;
    
    for(auto moves : possible_moves)
    {
        if (moves == mouse_clicked_pos) return true;
    }
    return false;
}