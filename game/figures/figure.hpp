#include <SFML/Graphics.hpp>
#include "const_values.cpp"



enum class FigureType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

class Figure
{
   protected:
        const float C_FIGURE_SIZE;

        sf::Texture c_light_figure_t;
        sf::Texture c_dark_figure_t;
        sf::Sprite c_light_figure_s;
        sf::Sprite c_dark_figure_s;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 

        FigureType c_type;




    public:
        Figure(const std::string& LIGHT_FIGURE_PATH,const std::string& DARK_FIGURE_PATH, const float FIGURE_SIZE,
         sf::Vector2f pixel_position, sf::Vector2i board_position, FigureType type)
       
        : C_FIGURE_SIZE(FIGURE_SIZE), c_pixel_position(pixel_position),c_board_position(board_position), c_type(type)
        {

        }

        virtual ~Figure() = default;

        void draw(sf::RenderWindow& window);
        virtual void update_position() = 0;
        virtual sf::Vector2f set_start_position();
        int move_counter();

        //get
        virtual void get_possible_moves() = 0;
        sf::Vector2i get_board_position() const { return c_board_position; }
        sf::Vector2f get_pixel_position() const { return c_pixel_position; }
        bool is_alive();

       
};
