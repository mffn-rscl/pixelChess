#include "Game.hpp"
Game::Game() : c_window(sf::VideoMode(1920, 1080), "Chess")
{
    c_board = new Board;

    initialize_figures();
    set_is_light_move(true);
    set_game_state(GameState::NORMAL);
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
   
    //ROOKS
    for (int cols = 0; cols < 2; cols++)
    {
        c_color = FigureColor::LIGHT;

        Rook* light_figure = new Rook(LIGHT_FIGURE_ROOK_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::ROOK, c_color);

        light_figure->set_figure_position(sf::Vector2i(cols*7, 7));
        c_figures.push_back(light_figure);

        c_color = FigureColor::DARK;

        Rook* dark_figure =new Rook(DARK_FIGURE_ROOK_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::ROOK, c_color);
        dark_figure->set_figure_position(sf::Vector2i(cols*7, 0));
        c_figures.push_back(dark_figure);
    }

    //BISHOPS
    for (int cols = 2; cols <= 5; cols+=3)
    {
        c_color = FigureColor::LIGHT;

        Bishop* light_figure =new Bishop(LIGHT_FIGURE_BISHOP_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::BISHOP, c_color);
        light_figure->set_figure_position(sf::Vector2i(cols, 7));
        c_figures.push_back(light_figure);

        c_color = FigureColor::DARK;

        Bishop* dark_figure =new Bishop(DARK_FIGURE_BISHOP_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::BISHOP, c_color);
        dark_figure->set_figure_position(sf::Vector2i(cols, 0));
        c_figures.push_back(dark_figure);
    }
    
    //KNIGHTS
    for (int cols = 1; cols <= 6; cols+=5)
    {
        c_color = FigureColor::LIGHT;

        Knight* light_figure =new Knight(LIGHT_FIGURE_KNIGHT_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::KNIGHT, c_color);
        light_figure->set_figure_position(sf::Vector2i(cols, 7));
        c_figures.push_back(light_figure);

        c_color = FigureColor::DARK;

        Knight* dark_figure =new Knight(DARK_FIGURE_KNIGHT_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::KNIGHT, c_color);
        dark_figure->set_figure_position(sf::Vector2i(cols, 0));
        c_figures.push_back(dark_figure);
    }

    //KING 
     c_color = FigureColor::LIGHT;

    King* light_figure =new King(LIGHT_FIGURE_KING_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::KING, c_color);
    light_figure->set_figure_position(sf::Vector2i(4, 7));
    c_figures.push_back(light_figure);

    c_color = FigureColor::DARK;

    King* dark_figure =new King(DARK_FIGURE_KING_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::KING, c_color);
    dark_figure->set_figure_position(sf::Vector2i(4, 0));
    c_figures.push_back(dark_figure);

     //QUEEN 
     c_color = FigureColor::LIGHT;

    Queen* light_figure_q =new Queen(LIGHT_FIGURE_QUEEN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::QUEEN, c_color);
    light_figure_q->set_figure_position(sf::Vector2i(3, 7));
    c_figures.push_back(light_figure_q);

    c_color = FigureColor::DARK;

    Queen* dark_figure_q =new Queen(DARK_FIGURE_QUEEN_PATH, CELL_TEXTURE_SIZE, START_FIGURE_POS, FigureType::QUEEN, c_color);
    dark_figure_q->set_figure_position(sf::Vector2i(3, 0));
    c_figures.push_back(dark_figure_q);
    


}

//display
void Game::render()
{
    for(auto& hint : c_hint)
    {
        hint.draw(c_window);
    }
    for(auto figure : c_figures)
    {
        figure->draw(c_window);
    }
   

}

//setters
void Game::set_is_light_move(bool set){ c_is_light_move = set; }

void Game::set_game_state(GameState state){ c_state = state; }

void Game::set_define_figure(Figure* figure) {c_define_figure = figure;}
        
void Game::set_action(Action action) {c_action = action;}

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

//events
void Game::handle_events()
{
     sf::Event event;
        while (c_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) c_window.close();
            
        
            if (event.type == sf::Event::MouseButtonPressed && (c_state != GameState::CHECKMATE || c_state != GameState::CHECKMATE))
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
               
                switch (c_state)
                {
                    case GameState::NORMAL:
                        set_define_figure(figure);
                        normal_state_figure_picking();
                        break;
                    
                    case GameState::CHECK:
                        check_state_figure_picking(figure);
                        break;
                }
                initialize_hints();                            

               
               
                
            }
            else // if figure color != color move turn
            {
                c_current_figure_moves.clear();
                set_action(Action::ACTION_EXPECTED);
                break;
            } 
        }                        
    }
}

void Game::figure_placing()
{
    c_hint.clear();
    
    if(is_current_move(c_current_figure_moves)) 
    {
           
        figure_beated();
        set_figure_pos_in_playing_field(c_define_figure, c_mouse_clicked);

        c_define_figure->set_figure_position(c_mouse_clicked);
        c_define_figure->set_is_moved(true);
        set_is_light_move(!c_is_light_move);

    }
    c_define_figure = nullptr;
    c_current_figure_moves.clear();


    //check if c_state == check after move
    Figure* king = find_king();
    std::vector<Figure* > after_move_checker = find_attacking_figures(king);
    set_game_state((after_move_checker.empty()) ? GameState::NORMAL : GameState::CHECK);
    set_action(Action::ACTION_EXPECTED);

    std::cout <<"GAME STATE: " << static_cast<int>(c_state) << std::endl;
}

bool Game::is_current_move(std::vector<sf::Vector2i> possible_moves)
{
    if (possible_moves.empty()) return false;
    
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

sf::Vector2i Game::get_clicked_board_position(float x, float y)
{
    int board_x = floor( (x - START_FIGURE_POS.x) / CELL_TEXTURE_SIZE.x );
    int board_y = floor( (y - START_FIGURE_POS.y) / CELL_TEXTURE_SIZE.y );

    return sf::Vector2i(board_x, board_y);
}

void Game::normal_state_figure_picking()
{
    if (c_current_figure_moves.empty())
    {
        c_current_figure_moves = c_define_figure->find_moves(*c_board);
        
        c_current_figure_moves = moves_filter(c_current_figure_moves, c_define_figure);
        
        if (is_figure_protecting()) 
        {
            set_action(Action::ACTION_EXPECTED);
            c_define_figure = nullptr;
            c_current_figure_moves.clear();
            return;
        }
        
        c_define_figure->set_current_moves(c_current_figure_moves);
    }
    
    set_action(Action::FIGURE_PLACING);
}

Figure* Game::find_king()
{
    for(auto& figure : c_figures)
    {
        if (figure->get_figure_type() == FigureType::KING)
        {
            if (c_is_light_move && figure->get_color() == FigureColor::LIGHT || 
            !c_is_light_move && figure->get_color() == FigureColor::DARK)
            {
                return figure;
            }
        }
        
    }
    return nullptr;
}

std::vector<Figure* > Game::find_attacking_figures(const Figure* picked_figure)
{
    std::vector<Figure* > attacking_figures;

    sf::Vector2i picked_figure_pos  = picked_figure->get_board_pos(); 
    
    for(auto& figure : c_figures)
    {
        if (picked_figure->get_color() != figure->get_color())
        {
            std::vector<sf::Vector2i> attacked_moves;
            
            if (figure->get_figure_type() == FigureType::KING)
            {
                sf::Vector2i king_pos = figure->get_board_pos();
                for (int i = -1; i <= 1; i++)
                {
                    for (int j = -1; j <= 1; j++)
                    {
                        if (i == 0 && j == 0) continue;
                        
                        sf::Vector2i attack_pos(king_pos.x + i, king_pos.y + j);
                        
                        attacked_moves.push_back(attack_pos);
                    }
                }
            }
            else
            {
                attacked_moves = figure->find_moves(*c_board);
            }

            for(auto& move : attacked_moves)
            {
                if (picked_figure_pos == move)
                {
                    attacking_figures.push_back(figure);
                    break;
                }
            }
        }
    }
    return attacking_figures;
}

bool Game::is_figure_protecting()
{
    const Figure* king = find_king();
    sf::Vector2i king_pos = king->get_board_pos();
    sf::Vector2i define_figure_pos = c_define_figure->get_board_pos();
    
    FigureType original_type = c_define_figure->get_figure_type();
    c_board->set_figure_type(define_figure_pos, FigureType::EMPTY);
    
    std::vector<Figure*> danger_figures = find_attacking_figures(king);
    
    c_board->set_figure_type(define_figure_pos, original_type);
    
    if (danger_figures.empty()) return false;
    
    
    std::vector<sf::Vector2i> safe_moves;
    std::vector<sf::Vector2i> all_moves = c_define_figure->find_moves(*c_board);
    
    for (const auto& move : all_moves) 
    {

        FigureType dest_type = c_board->get_figure_type(move);
        Figure* captured_figure = nullptr;
        
        for (auto& figure : c_figures) 
        {
            if (figure->get_board_pos() == move && figure != c_define_figure) 
            {
                captured_figure = figure;
                break;
            }
        }
        
        c_board->set_figure_type(define_figure_pos, FigureType::EMPTY);
        c_board->set_figure_type(move, original_type);
        
        auto it = std::find(c_figures.begin(), c_figures.end(), captured_figure);
       
        if (it != c_figures.end())  c_figures.erase(it);
    
        
        std::vector<Figure*> threats_after_move = find_attacking_figures(king);
        
        if (threats_after_move.empty()) {
            safe_moves.push_back(move);
        }
        
        if (captured_figure) c_figures.push_back(captured_figure);

        c_board->set_figure_type(move, dest_type);
        c_board->set_figure_type(define_figure_pos, original_type);
    }
    
    if (!safe_moves.empty()) 
    {
        c_current_figure_moves = safe_moves;
        return false; 
    }
    
    return true;
}

std::vector<sf::Vector2i> Game::moves_filter(std::vector<sf::Vector2i>& moves, Figure* picked_figure)
{
    std::vector<sf::Vector2i> filtered_moves;
    
    for (auto& move : moves)
    {
        bool can_move = true;

        for (auto& figure : c_figures)
        {
            if (figure->get_board_pos() == move)
            {
                if (figure->get_color() == picked_figure->get_color()) 
                {
                    can_move = false;
                    break;
                }
            }
        }

        if (!can_move) continue;

        if (picked_figure->get_figure_type() == FigureType::KING)
        {

            sf::Vector2i from = picked_figure->get_board_pos();
            FigureType original_dest_type = c_board->get_figure_type(move);

            c_board->set_figure_type(from, FigureType::EMPTY);
            c_board->set_figure_type(move, FigureType::KING);

            Figure* fake_king = picked_figure;
            fake_king->set_figure_position(move); 

            auto attackers = find_attacking_figures(fake_king);

            fake_king->set_figure_position(from);
            c_board->set_figure_type(move, original_dest_type);
            c_board->set_figure_type(from, FigureType::KING);

            if (!attackers.empty()) can_move = false;
        }

        if (can_move) filtered_moves.push_back(move);
    }

    return filtered_moves;
}

void Game::check_state_figure_picking(Figure* figure) 
{
    std::vector<sf::Vector2i> protective_moves = find_protective_moves(figure);
    
    if(protective_moves.empty())
    {
       set_action(Action::ACTION_EXPECTED);
        c_define_figure = nullptr;
        c_current_figure_moves.clear(); 
    } 
    else
    {
        set_define_figure(figure); 
        set_action(Action::FIGURE_PLACING);
        c_current_figure_moves = protective_moves;
    }
}

std::vector<sf::Vector2i> Game::find_protective_moves(Figure* figure)
{
    std::vector<sf::Vector2i> protective_moves;
    
    if (figure->get_figure_type() == FigureType::KING)
    {
        std::vector<sf::Vector2i> king_moves = figure->find_moves(*c_board);
        protective_moves = moves_filter(king_moves, figure); 
    }
    else
    {
        Figure* king = find_king();
        sf::Vector2i king_pos = king->get_board_pos();

        auto figure_moves = figure->find_moves(*c_board);
        
        auto figures_attacked = find_attacking_figures(king);

        if (figures_attacked.size() > 1) return protective_moves; // double check can only be resolved by king

        for(auto& figure_attacked : figures_attacked)
        {
            std::vector<sf::Vector2i> figure_attacked_moves = figure_attacked->find_moves(*c_board);

            for(auto& move : figure_moves)
            {
                if (move == figure_attacked->get_board_pos()) 
                { 
                    protective_moves.push_back(move); 
                }
                
                for(auto& figure_attacked_move : figure_attacked_moves)
                {
                    if (move == figure_attacked_move && figure_attacked_move != king_pos)
                    {
                        FigureType original_dest_type = c_board->get_figure_type(move);

                        c_board->set_figure_type(move, figure->get_figure_type());
                        c_board->set_figure_type(figure->get_board_pos(), FigureType::EMPTY);

                        Figure* king = find_king();
                        std::vector<Figure*> after_move_checker = find_attacking_figures(king);

                        if (after_move_checker.empty())
                        {
                            protective_moves.push_back(move);
                        }

                        c_board->set_figure_type(move, original_dest_type);
                        c_board->set_figure_type(figure->get_board_pos(), figure->get_figure_type());
                    }
                }
            }
        }     
    }
        
    return protective_moves;
}