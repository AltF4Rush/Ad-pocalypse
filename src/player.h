#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "platform.h"

class Player{
  public:
    void init();
    void gravity(float dt);
    void move(float dt);
    void draw(sf::RenderWindow& window);
    void collision(const Platform& platform, float dt);
  private:
    const float g = 980.0f;
    const float max_g = 1000.0f;
    float speed = 5.0f;
    sf::Vector2f velocity;
  private:
    sf::RectangleShape player;
};
