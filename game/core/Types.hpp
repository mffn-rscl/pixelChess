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

enum class GameState //draft
{
    NORMAL,
    CHECK,
    CHECKMATE,
};

enum class Action
{
    ACTION_EXPECTED,
    FIGURE_PICKING,
    FIGURE_PLACING
};

enum class FigureColor
{
    LIGHT,
    DARK
};
