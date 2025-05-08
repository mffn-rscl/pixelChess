#include <SFML/Graphics.hpp>

enum class CellType
{
    HIGHLIGHTED,
    EMPTY,
    OCCUPIED
};

class Board 
{
    protected:
        std::vector<sf::Sprite> c_cells_s;
        sf::Sprite c_background_board_s;
        sf::Texture c_light_cell_t;
        sf::Texture c_dark_cell_t;
        sf::Texture c_board_t;
        sf::Vector2f c_pos;
        sf::Vector2f c_board_size;
        sf::Vector2u c_window_size;
        float c_cell_size;
        bool c_user_figure_color; // 1 - light, 0 - dark

    public:
        Board(const std::string& BOARD_PATH, const std::string& LIGHT_CELL_PATH ,const std::string& DARK_CELL_PATH, const float CELL_SIZE, sf::Vector2f BOARD_SIZE, sf::Vector2u  window_size, bool user_figure_color);

        void build_field_of_cells();
        
        void draw_board(sf::RenderWindow& window);

        void display_background_board(sf::RenderWindow& window);

        sf::Vector2f set_central_position();

};