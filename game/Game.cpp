#include "Game.hpp"
Game::Game() : c_window(sf::VideoMode(1920, 1080), "Chess")
{
    c_board = new Board;

    initialize_figures();
    set_is_light_move(true);
    set_game_state(GameState::NORMAL);
    set_action(Action::ACTION_EXPECTED);
    c_lose = new Hint(LOSE_HINT_PATH, CELL_TEXTURE_SIZE ,START_FIGURE_POS); 
    c_draw_l = new Hint(DRAW_HINT_PATH, CELL_TEXTURE_SIZE ,START_FIGURE_POS); 
    c_draw_d = new Hint(DRAW_HINT_PATH, CELL_TEXTURE_SIZE ,START_FIGURE_POS); 
}

Game::~Game()
{
    for(auto figure : c_figures)
    {
        delete figure;
    }
    delete c_board;
    delete c_lose;
    delete c_draw_d;
    delete c_draw_l;

}

//initialization
void Game::initialize_hints()
{
    for(auto& hint_pos : c_current_figure_moves)
    {
        Hint* hint = new Hint(HINT_PATH, CELL_TEXTURE_SIZE ,START_FIGURE_POS, hint_pos); 
        hint->set_hint_position();
        c_hint.push_back(hint);
    }
   
}

void Game::clear_hints() 
{
    for(auto& hint : c_hint)
    {
        delete hint;
    }
    c_hint.clear();
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

void Game::render()
{   

    if (is_draw())
    {
        for(auto& figure :c_figures)
        {
            if (figure->get_figure_type() == FigureType::KING)
            {
                
               if (figure->get_color() == FigureColor::LIGHT)
               {
                    c_draw_l->set_hint_position(figure->get_board_pos());
                    c_draw_l->draw(c_window);
               }
               else
               {
                    c_draw_d->set_hint_position(figure->get_board_pos());
                    c_draw_d->draw(c_window);
               }
               
            }
            
        }

    }
    else if (is_check_mate())
    {
        Figure* king = find_king();
        c_lose->set_hint_position(king->get_board_pos());
        c_lose->draw(c_window);

    }
    
    for(auto& hint : c_hint)
    {
        hint->draw(c_window);
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


//events
void Game::handle_events()
{
     sf::Event event;
        while (c_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) c_window.close();
            
        
            if (event.type == sf::Event::MouseButtonPressed && !is_check_mate() && !is_draw())
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

                    case GameState::CHECKMATE:
                        return;

                    case GameState::DRAW:
                        return;
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
    clear_hints();
    
    if(is_current_move(c_current_figure_moves)) 
    {
        castling_checker();
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

void Game::normal_state_figure_picking()
{
    c_current_figure_moves = c_define_figure->find_moves(*c_board);

    if (c_define_figure->get_figure_type() == FigureType::KING)
    {
        c_current_figure_moves = king_moves_filter(c_current_figure_moves, c_define_figure);
    }
    else
    {
    
        c_current_figure_moves = moves_filter(c_current_figure_moves, c_define_figure);
        
        if (is_figure_protecting()) 
        {
            set_action(Action::ACTION_EXPECTED);
            c_define_figure = nullptr;
            c_current_figure_moves.clear();
            return;
        }
        
    }    
   

    c_define_figure->set_current_moves(c_current_figure_moves);
    
    set_action(Action::FIGURE_PLACING);
}

void Game::castling_checker()
{
    if(c_define_figure->get_figure_type() != FigureType::KING) return;
    sf::Vector2i king_pos = c_define_figure->get_board_pos();
    Figure* rook = nullptr;
    
    if (abs(c_mouse_clicked.x - king_pos.x) == 2 && c_mouse_clicked.y == king_pos.y)
    {
        if(c_mouse_clicked.x > king_pos.x)
        {
            for(auto& figure : c_figures)
            {
                if (figure->get_figure_type() == FigureType::ROOK && 
                    figure->get_color() == c_define_figure->get_color() &&
                    figure->get_board_pos() == sf::Vector2i(7, king_pos.y))
                {
                    rook = figure;
                    break;
                }
            } 
            
            if (rook != nullptr)
            {
                sf::Vector2i rook_new_pos = sf::Vector2i(c_mouse_clicked.x - 1, c_mouse_clicked.y);
                
                set_figure_pos_in_playing_field(rook, rook_new_pos);
                rook->set_figure_position(rook_new_pos);
                rook->set_is_moved(true);
            }
        }
        else if(c_mouse_clicked.x < king_pos.x)
        {
            for(auto& figure : c_figures)
            {
                if (figure->get_figure_type() == FigureType::ROOK && 
                    figure->get_color() == c_define_figure->get_color() &&
                    figure->get_board_pos() == sf::Vector2i(0, king_pos.y))
                {
                    rook = figure;
                    break;
                }
            } 
            
            if (rook != nullptr)
            {
                sf::Vector2i rook_new_pos = sf::Vector2i(c_mouse_clicked.x + 1, c_mouse_clicked.y);
                
                set_figure_pos_in_playing_field(rook, rook_new_pos);
                rook->set_figure_position(rook_new_pos);
                rook->set_is_moved(true);
            }
        }
    }
}


void Game::castling(Figure* king, std::vector<sf::Vector2i>& filtered_moves)
{
    std::vector<sf::Vector2i> permissible_castling;
    sf::Vector2i king_pos = king->get_board_pos();
    sf::Vector2i right_cell_from_pos = sf::Vector2i(king_pos.x + 1, king_pos.y);
    sf::Vector2i left_cell_from_pos = sf::Vector2i(king_pos.x - 1, king_pos.y);

    for(auto& move : filtered_moves)
    {
        Figure* rook;
        if (move == right_cell_from_pos)
        {
            for(auto& figure : c_figures)
            {
                if (figure->get_figure_type() == FigureType::ROOK && figure->get_color() == king->get_color())
                {
                    if (!figure->get_is_moved())
                    {
                       
                        rook = figure;
                        break;
                        
                    }
                    
                }
                rook = nullptr;
            }            
            sf::Vector2i castling_right = sf::Vector2i(king_pos.x + 2, king_pos.y);
            if (c_board->get_figure_type(castling_right) == FigureType::EMPTY && rook !=nullptr)
            {
                c_board->set_figure_type(castling_right, king->get_figure_type());
                c_board->set_figure_type(king_pos, FigureType::EMPTY);

                std::vector<Figure* > attacked_figures = find_attacking_figures(king);
                if (attacked_figures.empty())
                {
                    filtered_moves.push_back(castling_right);
                }
                c_board->set_figure_type(castling_right,FigureType::EMPTY);
                c_board->set_figure_type(king_pos, king->get_figure_type());
            }
            
            
        }
        else if(move == left_cell_from_pos)
        {
            for(auto& figure : c_figures)
            {
                if (figure->get_figure_type() == FigureType::ROOK && figure->get_color() == king->get_color())
                {
                    if (!figure->get_is_moved())
                    {
                        rook = figure;
                        break;
                    }
                    
                }
                rook = nullptr;
            }            
            sf::Vector2i castling_left = sf::Vector2i(king_pos.x - 2, king_pos.y);
            if (c_board->get_figure_type(castling_left) == FigureType::EMPTY && rook !=nullptr)
            {
                c_board->set_figure_type(castling_left, king->get_figure_type());
                c_board->set_figure_type(king_pos, FigureType::EMPTY);

                std::vector<Figure* > attacked_figures = find_attacking_figures(king);
                if (attacked_figures.empty())
                {
                    filtered_moves.push_back(castling_left);
                }

                c_board->set_figure_type(castling_left,FigureType::EMPTY);
                c_board->set_figure_type(king_pos, king->get_figure_type());
            }
            
        }
           
    }
}

std::vector<sf::Vector2i> Game::king_moves_filter(std::vector<sf::Vector2i>& moves, Figure* king)
{
    std::vector<sf::Vector2i> filtered_moves;
    sf::Vector2i king_pos = king->get_board_pos();

    for(auto& move : moves)
    {
        

        bool occupied_by_own_figure = false;
        for(auto& figure : c_figures)
        {
            if (figure->get_board_pos() == move && figure->get_color() == king->get_color())
            {
                occupied_by_own_figure = true;
                break;
            }
        }
        
        if (occupied_by_own_figure) {
            continue;
        }

        FigureType temp = c_board->get_figure_type(move);
        FigureType original_king_type = c_board->get_figure_type(king_pos);
        
        Figure* captured_figure = nullptr;
        auto captured_it = c_figures.end();
        
        for(auto it = c_figures.begin(); it != c_figures.end(); ++it)
        {
            if ((*it)->get_board_pos() == move && (*it)->get_color() != king->get_color())
            {
                captured_figure = *it;
                captured_it = it;
                c_figures.erase(it);
                break;
            }
        }

        c_board->set_figure_type(move, king->get_figure_type());
        c_board->set_figure_type(king_pos, FigureType::EMPTY);
        
        sf::Vector2i original_king_pos = king->get_board_pos();
        king->set_figure_position(move);

        std::vector<Figure*> attacking_figures = find_attacking_figures(king);
        
        if (attacking_figures.empty())
        {
            filtered_moves.push_back(move);
        }

        king->set_figure_position(original_king_pos);
        c_board->set_figure_type(move, temp);
        c_board->set_figure_type(king_pos, original_king_type);
        
        if (captured_figure != nullptr)
        {
            c_figures.insert(captured_it, captured_figure);
        }
    }
    //castling
    if (!king->get_is_moved() && c_state == GameState::NORMAL)
    {
        castling(king, filtered_moves);
    }
    
    return filtered_moves;
}


std::vector<Figure* > Game::find_attacking_figures(const Figure* king)
{
    std::vector<Figure* > attacking_figures;

    sf::Vector2i king_pos  = king->get_board_pos(); 
    
    for(auto& figure : c_figures)
    {
        if (king->get_color() != figure->get_color())
        {
            std::vector<sf::Vector2i> figure_moves = figure->find_moves(*c_board);
            for(auto& figure_move : figure_moves)
            {
                if(king_pos == figure_move)
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
    all_moves = moves_filter(all_moves, c_define_figure);
    
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
    if (picked_figure->get_figure_type() == FigureType::PAWN)
    {
        sf::Vector2i pawn_pos = picked_figure->get_board_pos();
        int direction = (picked_figure->get_color()==FigureColor::DARK) ? 1 : -1;
        sf::Vector2i beating_left = sf::Vector2i(pawn_pos.x-1, pawn_pos.y+ direction);
        sf::Vector2i beating_right = sf::Vector2i(pawn_pos.x+1, pawn_pos.y+direction);
        for(auto& move : moves)
        {
            if ((beating_right == move || beating_left == move))
            {
                
                if (c_board->get_figure_type(move) != FigureType::EMPTY)
                {
                    for(auto& figure : c_figures)
                    {
                        if (figure->get_board_pos() == move)
                        {
                            if (figure->get_color() != picked_figure->get_color())
                            {
                                filtered_moves.push_back(move);
                            }
                            
                        }
                        
                    }
                    
                }
                
            }
            else
            {
                filtered_moves.push_back(move);
            }
        
        }  
    }
    else
    {
        for(auto& move : moves)
        {
            for(auto& figure : c_figures)
            {
                if(figure->get_board_pos() == move || c_board->get_figure_type(move) == FigureType::EMPTY)
                {
                    if(figure->get_color() != picked_figure->get_color())
                    {
                        filtered_moves.push_back(move);
                        break;
                    }
                }
                

                
            }    
        }
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
        protective_moves = king_moves_filter(king_moves, figure); 
    }
   
    else
    {
        Figure* king = find_king();
        sf::Vector2i king_pos = king->get_board_pos();

        auto figure_moves = figure->find_moves(*c_board);
        figure_moves = moves_filter(figure_moves,figure);
        
        auto figures_attacked = find_attacking_figures(king);

        if (figures_attacked.size() > 1) return protective_moves; // double check can only be resolved by king

        for(auto& figure_attacked :  figures_attacked)
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
                        FigureType temp = c_board->get_figure_type(move);

                        c_board->set_figure_type(move, figure->get_figure_type());
                        c_board->set_figure_type(figure->get_board_pos(), FigureType::EMPTY);

                        Figure* king = find_king();
                        std::vector<Figure*> after_move_checker = find_attacking_figures(king);

                        if (after_move_checker.empty())
                        {
                            protective_moves.push_back(move);
                        }

                        c_board->set_figure_type(move, temp);
                        c_board->set_figure_type(figure->get_board_pos(), figure->get_figure_type());
                    }
                }
            }     
        }
        
    }   
    return protective_moves;
}

bool Game::is_check_mate()
{
    if (c_state == GameState::CHECKMATE) return true;
    
    else if (c_state == GameState::CHECK)
    {
        for(auto& figure : c_figures)
        {
            if ((figure->get_color() == FigureColor::LIGHT && c_is_light_move ) || (figure->get_color() == FigureColor::DARK && !c_is_light_move ))
            {
                
                auto figure_protective_moves = find_protective_moves(figure);
                if (!figure_protective_moves.empty())
                {
                    return false;
                }
                
            }
            
        }
        
        set_game_state(GameState::CHECKMATE);
        std::cout << "Game state: CHECKMATE" << std::endl;
        return true;
    }
    
    
    return false;    
}

bool Game::is_draw()
{
    if (c_state != GameState::CHECKMATE && c_state != GameState::CHECK)
    {   
        if (c_figures.size() == 2)
        {
            set_game_state(GameState::DRAW);
            return true;
        }
    
        for(auto& figure : c_figures)
        {
            if ((figure->get_color() == FigureColor::LIGHT && c_is_light_move ) || (figure->get_color() == FigureColor::DARK && !c_is_light_move ))
            {
                std::vector<sf::Vector2i> temp_moves = figure->find_moves(*c_board);
                temp_moves = moves_filter(temp_moves, figure);
                
                if (!temp_moves.empty())
                {
                    return false; 
                }
            }
        }
        
        set_game_state(GameState::DRAW);
        return true;
    }
    
    return false;
}


