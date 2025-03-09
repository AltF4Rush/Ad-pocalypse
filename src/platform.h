#pragma once
#include <SFML/Graphics.hpp>

class Platform{
  public:
    void init();
    void draw(sf::RenderWindow& window);
    sf::RectangleShape platform;
    sf::FloatRect collision();
};
