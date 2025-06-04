#include <SFML/Graphics.hpp>


class Hint
{
    private:
        sf::Vector2f C_SIZE;
        sf::Texture c_texture_t;
        sf::Sprite c_hint_s;
        sf::Vector2i c_position;
        sf::Vector2f C_START_FIGURE_POS;

    public:
        
        Hint(const std::string HINT_PATH, sf::Vector2f SIZE,sf::Vector2i position, sf::Vector2f START_FIGURE_POS);
        void draw(sf::RenderWindow& window);
        void set_hint_position();

};