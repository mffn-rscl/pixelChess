#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "core/const_values.hpp"
#include "board/Board.hpp"
#include "figures/Types.hpp"
#include "figures/Figure.hpp"
#include "figures/Pawn/Pawn.hpp"
#include "figures/Rook/Rook.hpp"
#include "figures/Bishop/Bishop.hpp"
#include "figures/Knight/Knight.hpp"
#include "figures/King/King.hpp"
#include "figures/Queen/Queen.hpp"

class Game
{
    private:
        sf::RenderWindow c_window;
        std::vector<Figure *> c_figures;

        FigureType c_playing_field[8][8];
        FigureColor c_color;

        bool c_is_light_move;
    public:

        Game();
        ~Game();
        void run();

    private:

        void initialize_playing_field();
        void initialize_figures();
        void set_figure_pos_in_playing_field(const Figure* figure, sf::Vector2i new_position);


        //  use in Game::run():
        sf::Vector2i get_clicked_board_position(float x, float y);

        bool is_light_move() const;

};  
