#include <SFML/Graphics.hpp>

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
        bool c_figure_color;

        sf::Texture c_light_figure_t;
        sf::Texture c_dark_figure_t;
        sf::Sprite c_light_figure_s;
        sf::Sprite c_dark_figure_s;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 
        FigureType c_type;


    public:
        Figure(const std::string& LIGHT_FIGURE_PATH,const std::string& DARK_FIGURE_PATH, const float FIGURE_SIZE,
        bool figure_color, sf::Vector2f pixel_position, sf::Vector2i board_position, FigureType type)
       
        : C_FIGURE_SIZE(FIGURE_SIZE),c_figure_color(figure_color), c_pixel_position(pixel_position),c_board_position(board_position), c_type(type){}

        virtual ~Figure() = default;

        virtual void draw(sf::RenderWindow& window);
        virtual void update_position();
        virtual void start_position();
        int move_counter();

        //get
        virtual void get_possible_moves();
        sf::Vector2i getBoardPosition() const { return c_board_position; }
        sf::Vector2f getPixelPosition() const { return c_pixel_position; }
        bool is_alive();

        //to another class 
        bool is_white_move();
       
};
