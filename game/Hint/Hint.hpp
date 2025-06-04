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
        
        Hint(const std::string HINT_PATH, sf::Vector2f SIZE, sf::Vector2f START_FIGURE_POS,sf::Vector2i position = sf::Vector2i(-1,-1));
        void draw(sf::RenderWindow& window);
        void set_hint_position();
        void set_hint_position(sf::Vector2i pos);

};