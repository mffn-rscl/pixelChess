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
        sf::RenderWindow c_window;
        
        //render elements
        std::vector<Figure *> c_figures;
        std::vector<Hint> c_hint;

        //moves
        sf::Vector2i c_mouse_clicked;
        std::vector<sf::Vector2i> c_current_figure_moves;
        Board* c_board = new Board;
        
        //game behavior
        Action c_action;
        FigureColor c_color;
        bool c_is_light_move;

        Figure* c_define_figure = nullptr;

    public:

        Game();
        ~Game();
        void run();

    private:
     
        void initialize_figures();
        void initialize_hints();


        sf::Vector2i get_clicked_board_position(float x, float y);
        sf::Vector2i get_mouse_clicked() const;     


        bool is_current_move(std::vector<sf::Vector2i> possible_moves);
        void set_figure_pos_in_playing_field(const Figure* figure, sf::Vector2i new_position);
        std::vector<sf::Vector2i> moves_filter(std::vector<sf::Vector2i>& moves, Figure* picked_figure);
       
       
        void figure_beated();
       
        void render();

        void handle_events();
        void left_mouse_clicked(const sf::Event& event);
        void figure_picking();
        void figure_placing();

        //setters
        void set_define_figure(Figure* figure);
        void set_is_light_move(bool set);
        void set_action(Action action);
};
