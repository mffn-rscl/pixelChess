#include "Figure.hpp"



class Pawn : public Figure
{
    public:
        using Figure::Figure;
        ~Pawn();
        virtual std::vector<sf::Vector2i> find_moves(Board& board);

};  