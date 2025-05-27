#include "Figure.hpp"



class King : public Figure
{
    
    public:
        using Figure::Figure;
        ~King();
        
        virtual std::vector<sf::Vector2i> get_possible_moves();
        virtual bool is_current_move(sf::Vector2f mouse_clicked_pos);

};  