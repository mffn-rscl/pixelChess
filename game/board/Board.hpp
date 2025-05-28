#ifndef BOARD_HPP
#define BOARD_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include "Types.hpp"

class Board 
{
    private:

        const sf::Vector2f C_BOARD_SIZE;
        const sf::Vector2f C_START_BOARD_POS;
        sf::Texture c_background_board_t;
        sf::Sprite c_background_board_s;

        FigureType c_playing_field[8][8];


    public:
        Board(const std::string& BOARD_TEXTURE_PATH, const sf::Vector2f BOARD_SIZE,const sf::Vector2f START_BOARD_POS); //for display
        Board(); // for c_playing_field
       
        void draw(sf::RenderWindow& window);
        
        FigureType get_figure_type(sf::Vector2i pos);
        void set_figure_type(sf::Vector2i pos, FigureType& type);
        
        void display_playing_field();

    private:
        void initialize_playing_field();

};

#endif