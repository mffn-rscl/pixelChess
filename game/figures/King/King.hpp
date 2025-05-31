#include "Figure.hpp"



class King : public Figure
{
    
    public:
        using Figure::Figure;
        ~King();
        
        virtual std::vector<sf::Vector2i> find_moves(Board& board);

};  