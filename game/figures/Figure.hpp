#include <SFML/Graphics.hpp>
#include "core/Types.hpp"

class Figure
{
   protected:
        const sf::Vector2f C_CELL_TEXTURE_SIZE; 
        const sf::Vector2f C_START_FIGURE_POS;
        sf::Texture c_figure_t;
        sf::Sprite c_figure_s;

        sf::Vector2i c_board_position; 
        sf::Vector2f c_pixel_position; 

        FigureType c_type;
        FigureColor c_color;



    public:
        Figure(const std::string& FIGURE_PATH, const sf::Vector2f CELL_TEXTURE_SIZE,const sf::Vector2f START_FIGURE_POS,
     sf::Vector2i board_position, FigureType type, FigureColor color)
       
        : C_CELL_TEXTURE_SIZE(CELL_TEXTURE_SIZE),c_board_position(board_position), c_type(type),
         c_color(color), C_START_FIGURE_POS(START_FIGURE_POS)
        
        {
            if (!c_figure_t.loadFromFile(FIGURE_PATH)) 
            throw std::runtime_error ("Can't load file from " + FIGURE_PATH + ". Check the correct file name.");
            c_figure_s.setTexture(c_figure_t);
        }

        virtual ~Figure() = default;

        void set_board_position(int x, int y);
        void set_pixel_position();

        void draw(sf::RenderWindow& window);

        //get
        FigureColor get_color() const; 
        FigureType get_figure_type() const;
        sf::Vector2i get_board_pos() const;
        sf::Vector2f get_pixel_pos() const;
        


       
};
