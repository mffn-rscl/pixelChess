#include "Game.hpp"
Game::Game() : c_window(sf::VideoMode(1920, 1080), "Chess")
{
    initialize_figures();

    c_is_light_move = true;
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

    //move figure
        Figure* define_figure = nullptr;
        bool figure_found= false;
        
        sf::Vector2i current_figure_board_pos;

    while (c_window.isOpen()) 
    {
      
        sf::Event event;
        while (c_window.pollEvent(event))
        {
                if (event.type == sf::Event::Closed) c_window.close();
              
           
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if(event.mouseButton.button == sf::Mouse::Left)
                    {
                         if (!figure_found)
                        {
                            
                            sf::Vector2i mouse_clicked = get_clicked_board_position(event.mouseButton.x,event.mouseButton.y);

                            for(auto figure : c_figures)
                            {
                                      //--------------------------------

                                        std::cout << "TRYING TO FIND CURRENT FIGURE ON THIS POS..." << std::endl;
                                      //--------------------------------
                                
                                current_figure_board_pos = figure->get_board_pos();
                            
                                c_color = figure->get_color();

                                if(current_figure_board_pos.x == mouse_clicked.x && current_figure_board_pos.y == mouse_clicked.y)
                                {
                                    if ((c_is_light_move && (c_color == FigureColor::LIGHT)) || (!c_is_light_move && (c_color == FigureColor::DARK)))
                                    {
                                         if(!figure->is_alive()) continue;

                                        define_figure = figure;
                                        figure_found = true;

                                      //--------------------------------
                                        sf::Vector2i debug_pos = define_figure->get_board_pos();
                                        std::cout << "FIGURE FOUND" << std::endl;
                                        std::cout << "( "<< debug_pos.x << ";" << debug_pos.y << ")." << std::endl;
                                      //--------------------------------


                                        //print move points
                                    
                                        break;
                                    }
                                    else break;
                                   
                                }                        
                           
                             std::cout << "FIGURE NOT FOUND. " << std::endl;
                           
                            }
                        }
                        else
                        {
                            if(define_figure != nullptr)
                            {
                                sf::Vector2i mouse_clicked = get_clicked_board_position(event.mouseButton.x,event.mouseButton.y);
                                std::vector<sf::Vector2i> possible_moves = define_figure->get_possible_moves(*c_board);                                
                              
                                if(is_current_move(mouse_clicked,possible_moves)) 
                                {
                                   
                                    

                                    set_figure_pos_in_playing_field(define_figure, mouse_clicked);

                                    define_figure->set_figure_position(mouse_clicked);
                                   
                                    c_is_light_move = !c_is_light_move;

                                }
                                figure_found = false;
                                define_figure = nullptr;
                            }
                          
                           
                            
                        }

                
                    }
                  
                }
        }
        c_window.clear(sf::Color(200,230,247));

        board.draw(c_window);

        render(); // print figures

        c_window.display();
    }
}





bool Game::is_current_move(sf::Vector2i mouse_clicked, std::vector<sf::Vector2i> possible_moves)
{
    for(const auto& move : possible_moves)
    {
        if (move == mouse_clicked) return true;
    }
    return false;
}

sf::Vector2i Game::get_clicked_board_position(float x, float y)
{
    int board_x = floor( (x - START_FIGURE_POS.x) / CELL_TEXTURE_SIZE.x );
    int board_y = floor( (y - START_FIGURE_POS.y) / CELL_TEXTURE_SIZE.y );

    return sf::Vector2i(board_x, board_y);
}

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

void Game::render()
{
    for(auto figure : c_figures)
    {
            if(figure->is_alive()) figure->draw(c_window);
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
    
