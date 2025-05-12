#include <SFML/Graphics.hpp>

#include "const_values.cpp"



int main() 
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Chess");

    // Board board(BOARD_TEXTURE_PATH,LIGHT_CELL_TEXTURE_PATH,DARK_CELL_TEXTURE_PATH,CELL_TEXTURE_SIZE,BOARD_TEXTURE_SIZE,SCREEN_RESOLUTION);

    while (window.isOpen()) 
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) window.close();
        }
        window.clear(sf::Color(200,230,247));

        // board.display_background_board(window);
        // board.draw_board(window);




        

        window.display();

    }

  

    return 0;
}
