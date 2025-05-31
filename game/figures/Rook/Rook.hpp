#include "Figure.hpp"



class Rook : public Figure
{
    
    public:
        using Figure::Figure;
        ~Rook();

         virtual std::vector<sf::Vector2i> find_moves(Board& board);

        
};  