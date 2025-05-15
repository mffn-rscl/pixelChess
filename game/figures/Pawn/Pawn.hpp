#include "Figure.hpp"



class Pawn : public Figure
{
    private:
    
        bool c_is_first_move = true;
    
    public:
        using Figure::Figure;
        ~Pawn();
        bool get_is_first_move()const;
        // virtual void get_moves();

};  