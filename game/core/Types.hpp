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

enum class Action
{
    ACTION_EXPECTED,
    FIGURE_PICKING,
    FIGURE_PLACING,
    LOCKED_OUT
};

enum class GameState
{
    NORMAL,
    CHECK,
    CHECKMATE,
    DRAW
};

enum class FigureColor
{
    LIGHT,
    DARK
};
