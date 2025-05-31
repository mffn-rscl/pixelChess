#include "Figure.hpp"



class Queen : public Figure
{
    
    public:
        using Figure::Figure;
        ~Queen();


        virtual std::vector<sf::Vector2i> find_moves(Board& board);

};  