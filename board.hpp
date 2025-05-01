#include <SFML/Graphics.hpp>


class Board
{
    private:
        std::vector<sf::Sprite> c_cells;
        sf::Texture c_light_cell_t;
        sf::Texture c_dark_cell_t;
        float c_cell_size;
        sf::Vector2f c_pos;


    public:
        Board(sf::Texture light_cell_t , sf::Texture dark_cell_t, float cell_size) 
        : c_light_cell_t(light_cell_t), c_dark_cell_t(dark_cell_t), c_cell_size(cell_size)
        {
            display_field_of_cells();
        }

        void display_field_of_cells()
        {
            c_cells.clear();

            for (int rows = 0; rows < 8; rows++)
            {
                for (int cols = 0; cols < 8; cols++)
                {
                    sf::Sprite cell_sprite;
                    bool is_light = (rows + cols) % 2 == 0;
                    //size and pos
                }
                
            }
            
                        
        }
        
        float get_size() const { return c_cell_size;};



};