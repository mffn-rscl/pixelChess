#pragma once
#include <SFML/Graphics.hpp>
#include "core/const_values.hpp"
#include "board/Board.hpp"
#include "figures/Pawn.hpp"
#include "figures/Types.hpp"

class Game
{
    private:
        sf::RenderWindow c_window;
        std::vector<Pawn *> c_pawns;

        FigureType c_playing_field[8][8];
        FigureColor c_color;

    public:

        Game();
        ~Game();
        void run();

    private:
        void initialize_playing_field();

        void initialize_light_figures();
        void initialize_dark_figures();

};
