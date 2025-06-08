#pragma once
#include <cmath>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "core/const_values.hpp"
#include "board/Board.hpp"
#include "Hint/Hint.hpp"
#include "core/Types.hpp"
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
    /*RENDER*/
    sf::RenderWindow c_window;

    std::vector<Figure *> c_figures;
    std::vector<Hint* > c_hint;
   
    /*MOVES*/
    sf::Vector2i c_mouse_clicked;
    std::vector<sf::Vector2i> c_current_figure_moves;
    Board* c_board;
   
    Hint* c_lose;
    Hint* c_draw_l;
    Hint* c_draw_d;
    /*GAME BIHAVIOR*/
    GameState c_state;
    Action c_action;
    FigureColor c_color;
    bool c_is_light_move;
    Figure* c_define_figure = nullptr;
    

public:
    Game();
    ~Game();
    void run();

private:
    /*INITIALIZATION*/
    void initialize_figures();
    void initialize_hints();

    /*GETTERS*/
    sf::Vector2i get_clicked_board_position(float x, float y);
    sf::Vector2i get_mouse_clicked() const;

    /*SETTERS*/
    void set_define_figure(Figure* figure);
    void set_is_light_move(bool set);
    void set_game_state(GameState state);
    void set_action(Action action);
    void set_figure_pos_in_playing_field(const Figure* figure, sf::Vector2i new_position);

    /*RENDER*/
    void clear_hints();
    void figure_beated();
    void render();



    /* EVENTS METHODS */
    void handle_events();
    void left_mouse_clicked(const sf::Event& event);
    void figure_picking();
    void figure_placing();
    
    /*GAME STATE*/
    void normal_state_figure_picking();
    void check_state_figure_picking(Figure* figure);
    bool is_check_mate();
    bool is_draw();


    /*MOVE METHODS*/
    bool is_current_move(std::vector<sf::Vector2i> possible_moves);

    void castling(Figure* king, std::vector<sf::Vector2i>& filtered_moves);
    void castling_checker();


    void pawn_to_queen();

    std::vector<sf::Vector2i> moves_filter(std::vector<sf::Vector2i>& moves, Figure* picked_figure);
    std::vector<sf::Vector2i> king_moves_filter(std::vector<sf::Vector2i>& moves, Figure* king);

    
    /*THE CHECK METHODS*/
    Figure* find_king(); // find king
    std::vector<Figure* > find_attacking_figures(const Figure* king);
    std::vector<sf::Vector2i> find_protective_moves(Figure* figure);
    bool is_figure_protecting();


   
};