#include <SFML/Graphics.hpp>


//board
const std::string BOARD_TEXTURE_PATH = "textures/board/board.png";
const std::string HINT_PATH = "textures/hints/hint.png";
const std::string LOSE_HINT_PATH = "textures/hints/lose.png";
const std::string DRAW_HINT_PATH = "textures/hints/draw.png";


//light figures


const std::string LIGHT_FIGURE_PAWN_PATH = "textures/figures/light/Pawn.png";
const std::string LIGHT_FIGURE_BISHOP_PATH = "textures/figures/light/Bishop.png";
const std::string LIGHT_FIGURE_KING_PATH = "textures/figures/light/King.png";
const std::string LIGHT_FIGURE_KNIGHT_PATH = "textures/figures/light/Knight.png";
const std::string LIGHT_FIGURE_QUEEN_PATH = "textures/figures/light/Queen.png";
const std::string LIGHT_FIGURE_ROOK_PATH = "textures/figures/light/Rook.png";

//dark figures

const std::string DARK_FIGURE_PAWN_PATH = "textures/figures/dark/Pawn.png";
const std::string DARK_FIGURE_BISHOP_PATH = "textures/figures/dark/Bishop.png";
const std::string DARK_FIGURE_KING_PATH = "textures/figures/dark/King.png";
const std::string DARK_FIGURE_KNIGHT_PATH = "textures/figures/dark/Knight.png";
const std::string DARK_FIGURE_QUEEN_PATH = "textures/figures/dark/Queen.png";
const std::string DARK_FIGURE_ROOK_PATH = "textures/figures/dark/Rook.png";


//size

const sf::Vector2f SCREEN_RESOLUTION(1920.f,1080.f);
const sf::Vector2f BOARD_TEXTURE_SIZE(828.f, 864.f);
const sf::Vector2f CELL_TEXTURE_SIZE (96.f,96.f);


//add start position
const sf::Vector2f START_BOARD_POS((SCREEN_RESOLUTION.x - BOARD_TEXTURE_SIZE.x) / 2 , (SCREEN_RESOLUTION.y - BOARD_TEXTURE_SIZE.y) / 4);
const sf::Vector2f START_FIGURE_POS(START_BOARD_POS.x + 30, START_BOARD_POS.y + 30);