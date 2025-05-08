#include "figure.hpp"

class Pawn : public Figure
{
    private:
        bool c_is_first_move;
    
    public:

        Pawn(const std::string& LIGHT_PAWN_PATH,const std::string& DARK_PAWN_PATH, const float FIGURE_SIZE,
        bool figure_color, sf::Vector2f pixel_position, sf::Vector2i board_position, FigureType type, bool is_first_move = true)
        
        : Figure(LIGHT_PAWN_PATH,DARK_PAWN_PATH, FIGURE_SIZE,figure_color, pixel_position, board_position, type), c_is_first_move(is_first_move)
        {
            if (!c_light_figure_t.loadFromFile(LIGHT_PAWN_PATH)) 
            throw std::runtime_error ("Can't load file from " + LIGHT_PAWN_PATH + ". Check the correct file name.");

            if (!c_dark_figure_t.loadFromFile(DARK_PAWN_PATH)) 
            throw std::runtime_error ("Can't load file from " + DARK_PAWN_PATH + ". Check the correct file name.");

            c_light_figure_s.setTexture(c_light_figure_t);
            c_dark_figure_s.setTexture(c_dark_figure_t);
        }



};  