#include "Figure.hpp"



class Knight : public Figure
{
    
    public:
        using Figure::Figure;
        ~Knight();

          virtual std::vector<sf::Vector2i> find_moves(Board& board);


};  