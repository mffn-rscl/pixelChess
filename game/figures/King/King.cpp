#include "King.hpp"

King::~King(){}


std::vector<sf::Vector2i> King::find_moves(Board& board)
{
     c_current_moves.clear();

    int current_x = c_board_position.x;
    int current_y = c_board_position.y;

    std::vector<sf::Vector2i> directions
    {
        {-1, -1},
        {0, -1},
        {1, -1},
        {1, 0},
        {1, 1},
        {0, 1},
        {-1, 1},
        {-1, 0}
    };

    for(auto& direction : directions)
    {
        current_x += direction.x;
        current_y += direction.y;
        if (is_valid_position(current_x, current_y))
        {
            c_current_moves.push_back(sf::Vector2i(current_x, current_y));
        }
            
        current_x = c_board_position.x;
        current_y = c_board_position.y;
    }

    return c_current_moves;
}
