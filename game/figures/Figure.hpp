
#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <SFML/Graphics.hpp>
#include "core/Types.hpp"
#include "board/Board.hpp"

class Figure
{
   protected:
   
        const sf::Vector2f C_CELL_TEXTURE_SIZE; 
        const sf::Vector2f C_START_FIGURE_POS;
        sf::Texture c_figure_t;
        sf::Sprite c_figure_s;

        bool c_is_moved;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 
        std::vector<sf::Vector2i> c_current_moves;
        FigureType c_type;
        FigureColor c_color;




    public:
        Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS, FigureType type, FigureColor color);

        virtual ~Figure();

        void set_is_moved(bool set);
        void set_figure_position(sf::Vector2i board_position);
        void set_current_moves(std::vector<sf::Vector2i> moves);
        void draw(sf::RenderWindow& window);
        virtual std::vector<sf::Vector2i> find_moves(Board& board) = 0;
        
        
        //get
        
        FigureColor get_color() const; 
        FigureType get_figure_type() const;
        sf::Vector2i get_board_pos() const;
        sf::Vector2f get_pixel_pos() const;
        std::vector<sf::Vector2i> get_current_moves() const; 
        bool is_valid_position(int x, int y) const;
        


};

#endif