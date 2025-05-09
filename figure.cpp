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

// for another class(relocate latter)
        virtual sf::Vector2f set_start_position(sf::RenderWindow& window)
        {
            sf::Vector2u window_size = window.getSize();
            float pos_x = (window_size.x - c_board_size.x) / 2;
            float pos_y = (window_size.y - c_board_size.y) / 4; 

            return sf::Vector2f(pos_x, pos_y);            

        }


};  