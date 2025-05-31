#include "Figure.hpp"



class Bishop : public Figure
{
    public:
        using Figure::Figure;
        ~Bishop();

        virtual std::vector<sf::Vector2i> find_moves(Board& board);


};  