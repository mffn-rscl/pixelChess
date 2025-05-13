#include "Game.hpp"

Game::Game() : c_window(sf::VideoMode(1920, 1080), "Chess")
{
    initialize_playing_field();
    initialize_light_figures();
    initialize_dark_figures();
}

Game::~Game()
{
    for(auto pawns : c_pawns)
    {
        delete pawns;
    }
}

void Game::run()
{
    Board board(BOARD_TEXTURE_PATH,DARK_CELL_TEXTURE_PATH,LIGHT_CELL_TEXTURE_PATH,BOARD_TEXTURE_SIZE,CELL_TEXTURE_SIZE,START_BOARD_POS, START_FIGURE_POS);
    while (c_window.isOpen()) 
    {

        sf::Event event;
        while (c_window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed) c_window.close();
        }
        c_window.clear(sf::Color(200,230,247));

        board.display_background_board(c_window);
        board.draw_board(c_window);


        for(auto pawn : c_pawns)
        {
            pawn->draw(c_window);
        }

                    

        c_window.display();
    }
}

void Game::initialize_playing_field()
{

    c_playing_field[0][0] = FigureType::ROOK;
    c_playing_field[0][1] = FigureType::KNIGHT;
    c_playing_field[0][2] = FigureType::BISHOP;
    c_playing_field[0][3] = FigureType::QUEEN;
    c_playing_field[0][4] = FigureType::KING;
    c_playing_field[0][5] = FigureType::BISHOP;
    c_playing_field[0][6] = FigureType::KNIGHT;
    c_playing_field[0][7] = FigureType::ROOK;

    c_playing_field[7][0] = FigureType::ROOK;
    c_playing_field[7][1] = FigureType::KNIGHT;
    c_playing_field[7][2] = FigureType::BISHOP;
    c_playing_field[7][3] = FigureType::QUEEN;
    c_playing_field[7][4] = FigureType::KING;
    c_playing_field[7][5] = FigureType::BISHOP;
    c_playing_field[7][6] = FigureType::KNIGHT;
    c_playing_field[7][7] = FigureType::ROOK;

    for (int cols = 0; cols < 8; cols++) 
    { 
        c_playing_field[1][cols] = FigureType::PAWN; 
        c_playing_field[6][cols] = FigureType::PAWN; 
    }
    for (int rows = 2; rows < 6; rows++)
    {
        for (int cols = 0; cols < 8; cols++)
        {
            c_playing_field[rows][cols] = FigureType::EMPTY;
        }
    }


}

void Game::initialize_light_figures()
{   
    // PAWNS
    for (int cols = 0; cols < 8; cols++)
    {
        c_color = FigureColor::LIGHT;

        Pawn* pawn = new Pawn(LIGHT_FIGURE_PAWN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, sf::Vector2i(cols,6) , c_playing_field[cols][7], c_color);
        c_pawns.push_back(pawn);
    }
    
}
void Game::initialize_dark_figures()
{
    // PAWNS
    for (int cols = 0; cols < 8; cols++)
    {
        c_color = FigureColor::DARK;

        Pawn* pawn = new Pawn(DARK_FIGURE_PAWN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, sf::Vector2i(cols,1) , c_playing_field[cols][1], c_color);
        c_pawns.push_back(pawn);
    }
    
}

