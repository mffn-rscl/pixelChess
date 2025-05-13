#include <SFML/Graphics.hpp>

enum class CellType
{
    HIGHLIGHTED,  
    EMPTY, 
    OCCUPIED 
};

class Board 
{
    private:
        //size
        const sf::Vector2f C_BOARD_SIZE;
        const sf::Vector2f C_CELL_SIZE;
        
        //start position
        const sf::Vector2f C_START_BOARD_POS;
        const sf::Vector2f C_START_CELL_POS;
    
        // textures
        sf::Texture c_background_board_t;
        sf::Texture c_dark_cell_t; 
        sf::Texture c_light_cell_t; 

        //sprites  
        sf::Sprite c_background_board_s;
        std::vector<sf::Sprite> c_cells_s;

        CellType c_cell_type;


    public:
        Board(const std::string& BOARD_TEXTURE_PATH, const std::string& DARK_CELL_TEXTURE_PATH, const std::string& LIGHT_CELL_TEXTURE_PATH,
        const sf::Vector2f BOARD_SIZE, const sf::Vector2f CELL_SIZE, const sf::Vector2f START_BOARD_POS, const sf::Vector2f START_CELL_POS);

        void build_field_of_cells();
        
        void draw_board(sf::RenderWindow& window);

        void display_background_board(sf::RenderWindow& window);


};