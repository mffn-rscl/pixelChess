#include "figure.hpp"



class Pawn : public Figure
{
    private:
    
        bool c_is_moved;
    
    public:

        Pawn(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,
         sf::Vector2f pixel_position, sf::Vector2i board_position, FigureType type, FigureColor color)
        
        : Figure(FIGURE_PATH, CELL_TEXTURE_SIZE, pixel_position, board_position, type, color)
        {
            c_is_moved = true;
        }

        void draw(sf::RenderWindow& window)
        {
            window.draw(c_figure_s);
        }

       
};  