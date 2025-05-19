#include "Figure.hpp"



class Knight : public Figure
{
    
    public:
        using Figure::Figure;
        ~Knight();

        virtual std::vector<sf::Vector2f> get_possible_moves();
        virtual bool is_current_move(sf::Vector2f mouse_clicked_pos);

};  