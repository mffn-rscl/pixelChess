
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <SFML/Graphics.hpp>
#include "Types.hpp"

class Figure
{
   protected:
   
        const sf::Vector2f C_CELL_TEXTURE_SIZE; 
        const sf::Vector2f C_START_FIGURE_POS;
        sf::Texture c_figure_t;
        sf::Sprite c_figure_s;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 

        FigureType c_type;
        FigureType c_playing_field[8][8];
        FigureColor c_color;

        bool c_is_alive;



    public:
        Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS, FigureType type, FigureColor color);

        virtual ~Figure();

        void set_board_position(sf::Vector2i board_position);
        void set_pixel_position();
        
        void sam_is_dead();
        void draw(sf::RenderWindow& window);

        //get
        FigureColor get_color() const; 
        FigureType get_figure_type() const;
        sf::Vector2i get_board_pos() const;
        sf::Vector2f get_pixel_pos() const;
        bool is_alive() const;
        
        virtual bool is_current_move(sf::Vector2i mouse_clicked_pos);
        virtual std::vector<sf::Vector2i> get_possible_moves();


        void set_playing_field(const FigureType playing_field[8][8]);
};

#endif // FIGURE_HPP