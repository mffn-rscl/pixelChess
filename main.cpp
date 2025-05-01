#include <SFML/Graphics.hpp>
#include "board.hpp"



int main() 
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chess");
  
    sf::Texture board_t;
    sf::Texture dark_cell_t;
    sf::Texture light_cell_t;
   
   
     if (!dark_cell_t.loadFromFile("textures/board/dark.png")) 
    throw std::runtime_error ("Can't load file from textures/board/dark.png. Check the correct file name.");
    if (!light_cell_t.loadFromFile("textures/board/light.png")) 
    throw std::runtime_error ("Can't load file from textures/board/light.png. Check the correct file name.");
     if (!board_t.loadFromFile("textures/board/board.png")) 
    throw std::runtime_error ("Can't load file from textures/board/board.png. Check the correct file name.");
   

    sf::Sprite board(board_t);  
    Board cell_field_board(light_cell_t, dark_cell_t, 100);    
    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        
        }
        window.clear(sf::Color(200,230,247));
        


        //board
          board.setScale(6.5f, 6.5f);
        
        board.setPosition(500, 27);
        window.draw(board);
        
      

        window.display();
    }

  

    return 0;
}
