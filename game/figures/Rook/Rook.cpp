#include "Rook.hpp"

Rook::~Rook(){}

std::vector<sf::Vector2i> Rook::find_moves(Board& board)
{
    c_current_moves.clear();

    int current_x = c_board_position.x;
    int current_y = c_board_position.y;

    std::vector<sf::Vector2i> directions
    {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1}
    };

    for(auto& direction : directions)
    {
        do
        {
            current_x += direction.x;
            current_y += direction.y;
            if (is_valid_position(current_x, current_y))
            {
                c_current_moves.push_back(sf::Vector2i(current_x, current_y));
            }
            
            
        } while (board.get_figure_type(sf::Vector2i(current_x, current_y)) == FigureType::EMPTY);
        
        current_x = c_board_position.x;
        current_y = c_board_position.y;
    }

    return c_current_moves;
}
