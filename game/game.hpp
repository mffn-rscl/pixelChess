#pragma once
#include <SFML/Graphics.hpp>
#include "const_values.cpp"
#include "board/board.hpp"
#include "figures/pawn.cpp"



enum class GameStatus //think
{
    MATE,
    CHECK,
    DRAW
};

class Game
{
    private:
        
        

        FigureType c_figure_type_board[8][8];

        //coordinations by px and cell
    public:

    Game()
    {

 
    }

    
};





       // FigureType board[8][8] = 
        // {
        //     {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
        //     {PAWN, PAWN,   PAWN,   PAWN,  PAWN,  PAWN,   PAWN,   PAWN},
        //     {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        //     {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        //     {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        //     {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        //     {PAWN, PAWN,   PAWN,   PAWN,  PAWN,  PAWN,   PAWN,   PAWN},
        //     {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}

        // };
