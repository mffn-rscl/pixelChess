#include "Figure.hpp"



class Pawn : public Figure
{
    private:
    
        bool c_is_first_move = true;
    
    public:
        using Figure::Figure;
        ~Pawn();
        bool get_is_first_move()const;
        void is_not_first_move();

        virtual bool is_current_move(sf::Vector2i mouse_clicked_pos);
        virtual std::vector<sf::Vector2i> get_possible_moves(const FigureType playing_field[8][8]);

};  