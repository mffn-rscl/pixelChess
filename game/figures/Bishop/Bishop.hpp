#include "Figure.hpp"



class Bishop : public Figure
{
    public:
        using Figure::Figure;
        ~Bishop();

        virtual std::vector<sf::Vector2i> get_possible_moves() =0;
        virtual bool is_current_move(sf::Vector2f mouse_clicked_pos) =0;

};  