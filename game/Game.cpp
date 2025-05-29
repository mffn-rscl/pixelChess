#include "Game.hpp"
Game::Game() : c_window(sf::VideoMode(1920, 1080), "Chess")
{
    initialize_figures();
    set_is_light_move(true);
    set_action(Action::ACTION_EXPECTED);
}

Game::~Game()
{
    for(auto figure : c_figures)
    {
        delete figure;
    }
    delete c_board;
}

void Game::run()
{
    Board board(BOARD_TEXTURE_PATH,BOARD_TEXTURE_SIZE,START_BOARD_POS);

    while (c_window.isOpen()) 
    {
        c_window.clear(sf::Color(200,230,247));

        handle_events();

        board.draw(c_window); // move to render()
        render(); 

        c_window.display();
    }
}

//initialization
void Game::initialize_hints()
{
    for(auto& hint_pos : c_current_figure_moves)
    {
        Hint hint(HINT_PATH, CELL_TEXTURE_SIZE, hint_pos,START_FIGURE_POS); 
        c_hint.push_back(hint);
    }
}

void Game::initialize_figures()
{   
    // PAWNS
    for (int cols = 0; cols < 8; cols++)
    {
        c_color = FigureColor::LIGHT;

        Pawn* light_figure = new Pawn(LIGHT_FIGURE_PAWN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::PAWN, c_color);
        light_figure->set_figure_position(sf::Vector2i(cols, 6));
        c_figures.push_back(light_figure);

        c_color = FigureColor::DARK;

        Pawn* dark_figure = new Pawn(DARK_FIGURE_PAWN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::PAWN, c_color);
        dark_figure->set_figure_position(sf::Vector2i(cols, 1));
        c_figures.push_back(dark_figure);
    }
   
    // //ROOKS
    // for (int cols = 0; cols < 2; cols++)
    // {
    //     c_color = FigureColor::LIGHT;

    //     Rook* light_figure =new Rook(LIGHT_FIGURE_ROOK_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols*7][7], c_color);
    //     light_figure->set_board_position(sf::Vector2i(cols*7, 7));
    //     c_figures.push_back(light_figure);

    //     c_color = FigureColor::DARK;

    //     Rook* dark_figure =new Rook(DARK_FIGURE_ROOK_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols*7][0], c_color);
    //     dark_figure->set_board_position(sf::Vector2i(cols*7, 0));
    //     c_figures.push_back(dark_figure);
    // }

    // //BISHOPS
    // for (int cols = 2; cols <= 5; cols+=3)
    // {
    //     c_color = FigureColor::LIGHT;

    //     Bishop* light_figure =new Bishop(LIGHT_FIGURE_BISHOP_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols][7], c_color);
    //     light_figure->set_board_position(sf::Vector2i(cols, 7));
    //     c_figures.push_back(light_figure);

    //     c_color = FigureColor::DARK;

    //     Bishop* dark_figure =new Bishop(DARK_FIGURE_BISHOP_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols][0], c_color);
    //     dark_figure->set_board_position(sf::Vector2i(cols, 0));
    //     c_figures.push_back(dark_figure);
    // }
    
    // //KNIGHTS
    // for (int cols = 1; cols <= 6; cols+=5)
    // {
    //     c_color = FigureColor::LIGHT;

    //     Knight* light_figure =new Knight(LIGHT_FIGURE_KNIGHT_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols][7], c_color);
    //     light_figure->set_board_position(sf::Vector2i(cols, 7));
    //     c_figures.push_back(light_figure);

    //     c_color = FigureColor::DARK;

    //     Knight* dark_figure =new Knight(DARK_FIGURE_KNIGHT_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[cols][0], c_color);
    //     dark_figure->set_board_position(sf::Vector2i(cols, 0));
    //     c_figures.push_back(dark_figure);
    // }

    // //KING 
    //  c_color = FigureColor::LIGHT;

    // King* light_figure =new King(LIGHT_FIGURE_KING_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[4][7], c_color);
    // light_figure->set_board_position(sf::Vector2i(4, 7));
    // c_figures.push_back(light_figure);

    // c_color = FigureColor::DARK;

    // King* dark_figure =new King(DARK_FIGURE_KING_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[4][0], c_color);
    // dark_figure->set_board_position(sf::Vector2i(4, 0));
    // c_figures.push_back(dark_figure);

    //  //QUEEN 
    //  c_color = FigureColor::LIGHT;

    // Queen* light_figure_q =new Queen(LIGHT_FIGURE_QUEEN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[3][7], c_color);
    // light_figure_q->set_board_position(sf::Vector2i(3, 7));
    // c_figures.push_back(light_figure_q);

    // c_color = FigureColor::DARK;

    // Queen* dark_figure_q =new Queen(DARK_FIGURE_QUEEN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, c_playing_field[3][0], c_color);
    // dark_figure_q->set_board_position(sf::Vector2i(3, 0));
    // c_figures.push_back(dark_figure_q);
    


}

//setters
void Game::set_is_light_move(bool set){ c_is_light_move = set; }

void Game::set_action(Action action){ c_action = action; }

void Game::set_define_figure(Figure* figure) {c_define_figure = figure;}

//events
void Game::handle_events()
{
     sf::Event event;
        while (c_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) c_window.close();
            
        
            if (event.type == sf::Event::MouseButtonPressed)
            {
                left_mouse_clicked(event);
            }
        }
               
}

void Game::left_mouse_clicked(const sf::Event& event)
{
    if(event.mouseButton.button != sf::Mouse::Left)return;
    
    c_mouse_clicked = get_clicked_board_position(event.mouseButton.x,event.mouseButton.y);

    switch(c_action)
    {
        case Action::ACTION_EXPECTED:
            set_action(Action::FIGURE_PICKING);
            [[fallthrough]]; 

        case Action::FIGURE_PICKING:
        figure_picking();
        break;

        case Action::FIGURE_PLACING:
        figure_placing();
        break;


    }

}


//picking/placing figure
sf::Vector2i Game::get_clicked_board_position(float x, float y)
{
    int board_x = floor( (x - START_FIGURE_POS.x) / CELL_TEXTURE_SIZE.x );
    int board_y = floor( (y - START_FIGURE_POS.y) / CELL_TEXTURE_SIZE.y );

    return sf::Vector2i(board_x, board_y);
}

void Game::figure_picking()
{
    for(auto figure : c_figures)
    {
        sf::Vector2i figure_board_pos = figure->get_board_pos();
    
        c_color = figure->get_color();

        if(figure_board_pos.x == c_mouse_clicked.x && figure_board_pos.y == c_mouse_clicked.y) //define if the figure is on clicked pos 
        {
            if ((c_is_light_move && (c_color == FigureColor::LIGHT)) || (!c_is_light_move && (c_color == FigureColor::DARK)))
            {


                set_define_figure(figure);

                c_current_figure_moves = c_define_figure->find_moves(*c_board);  //finds all moves on board 

                c_define_figure->set_current_moves(moves_filter(c_current_figure_moves, c_define_figure)); // defines current moves                                   
                
                c_current_figure_moves = c_define_figure->get_current_moves(); // save current moves
                
                initialize_hints();                            

                set_action(Action::FIGURE_PLACING);
                break;
            }
            else // if figure color != color move turn
            {
                set_action(Action::ACTION_EXPECTED);
                break;
            } 
        }                        
    }
}

void Game::figure_placing()
{
    c_hint.clear();
    c_current_figure_moves = c_define_figure->get_current_moves();                                
    
    if(is_current_move(c_current_figure_moves)) 
    {
           
        figure_beated();
        set_figure_pos_in_playing_field(c_define_figure, c_mouse_clicked);

        c_define_figure->set_figure_position(c_mouse_clicked);
        
        set_is_light_move(!c_is_light_move);

    }
    c_define_figure = nullptr;
    set_action(Action::ACTION_EXPECTED);

}


//update playing board
void Game::set_figure_pos_in_playing_field(const Figure* figure, sf::Vector2i new_position) 
{
    FigureType type;
    
    sf::Vector2i current_position = figure->get_board_pos();

    type = figure->get_figure_type();
    c_board->set_figure_type(new_position, type);

    type = FigureType::EMPTY;
    c_board->set_figure_type(current_position, type);

    c_board->display_playing_field();
    
}

//display
void Game::render()
{
   
    for(auto figure : c_figures)
    {
            if(figure->is_alive()) figure->draw(c_window);
    }
    for(auto& hint : c_hint)
    {
        hint.draw(c_window);
    }

}


// move methods
std::vector<sf::Vector2i> Game::moves_filter(std::vector<sf::Vector2i>& moves, Figure* picked_figure)
{
    std::vector<sf::Vector2i> filtered_moves;

    for(auto& move : moves)
    {
        bool can_move = true;
        bool found_figure = false;
        
        for(auto& figure : c_figures)
        {
            if (move == figure->get_board_pos())
            {
                found_figure = true;
                
                if(picked_figure->get_color() == figure->get_color())
                {
                    can_move = false;
                }
                break;
            }
            
        }
        if (can_move) filtered_moves.push_back(move);
    }
    return filtered_moves;
}

bool Game::is_current_move(std::vector<sf::Vector2i> possible_moves)
{
    for(const auto& move : possible_moves)
    {
        if (move == c_mouse_clicked) return true;
    }
    return false;
}

void Game::figure_beated()
{
    for(auto figure = c_figures.begin(); figure != c_figures.end(); figure++)
    {
        if ((*figure)->get_board_pos() == c_mouse_clicked)
        {
            delete *figure;
            c_figures.erase(figure);
            break;
        }
        
    }
}

