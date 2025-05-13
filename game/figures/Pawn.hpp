#include "Figure.hpp"



class Pawn : public Figure
{
    private:
    
        bool c_is_moved;
    
    public:

        Pawn(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
        sf::Vector2i board_position, FigureType type, FigureColor color)
        
        : Figure(FIGURE_PATH, CELL_TEXTURE_SIZE,START_FIGURE_POS, board_position, type, color)
        {
            c_is_moved = false;
            set_pixel_position();
        }

        void draw(sf::RenderWindow& window);
        void set_board_position(int x, int y);
        void set_pixel_position();

        //get
        FigureColor get_color() const;
        FigureType get_figure_type() const;
        sf::Vector2i get_board_pos() const;
        sf::Vector2f get_pixel_pos() const;

       
};  