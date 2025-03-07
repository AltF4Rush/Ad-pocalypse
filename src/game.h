#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <optional>

class Game{
  public:
    Game();
  public:
    void init();
    void update();
    void render();
    void run();
  private:
    sf::RenderWindow window;
};
