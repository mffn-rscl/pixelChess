#include <SFML/Graphics.hpp>
#include "const_values.cpp"



enum class FigureType
{
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING,
};

enum class FigureColor
{
    LIGHT,
    DARK
};

class Figure
{
   protected:
        const sf::Vector2f C_CELL_TEXTURE_SIZE; 
        sf::Texture c_figure_t;
        sf::Sprite c_figure_s;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 

        FigureType c_type;

        FigureColor c_color;



    public:
        Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,
         sf::Vector2f pixel_position, sf::Vector2i board_position, FigureType type, FigureColor color)
       
        : C_CELL_TEXTURE_SIZE(CELL_TEXTURE_SIZE), c_pixel_position(pixel_position),c_board_position(board_position), c_type(type), c_color(color)
        {

            if (!c_figure_t.loadFromFile(FIGURE_PATH)) 
            throw std::runtime_error ("Can't load file from " + FIGURE_PATH + ". Check the correct file name.");
            c_figure_s.setTexture(c_figure_t);
        }

        virtual ~Figure() = default;

        void set_start_position(int x, int y);
        
        void draw(sf::RenderWindow& window);

        


       
};
