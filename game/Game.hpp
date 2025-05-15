#pragma once
#include <SFML/Graphics.hpp>
#include "core/const_values.hpp"
#include "figures/Types.hpp"
#include "board/Board.hpp"
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

    public:

        Game();
        ~Game();
        void run();

    private:
        void initialize_playing_field();

        void initialize_figures();

};
