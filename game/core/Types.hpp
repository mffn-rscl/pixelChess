#pragma once

enum class FigureType
{
    EMPTY,
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
    
};



enum class GameState
{
    ACTION_EXPECTED,
    FIGURE_PICKING,
    FIGURE_PLACING,
    CHECK,
    CHECKMATE,
    DRAW
};

enum class FigureColor
{
    LIGHT,
    DARK
};
