#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Player{
  public:
    void init();
    void gravity(float dt);
    void move(float dt);
    void draw(sf::RenderWindow& window);
  private:
    const float g = 9.8f;
    const float max_g = 10.0f;
    float speed = 5.0f;
    sf::Vector2f velocity;
  private:
    sf::RectangleShape player;
};
