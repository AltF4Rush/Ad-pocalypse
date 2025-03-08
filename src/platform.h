#pragma once
#include <SFML/Graphics.hpp>

class Platform{
  public:
    void init();
    void draw(sf::RenderWindow& window);
  private:
    sf::RectangleShape platform;
};
