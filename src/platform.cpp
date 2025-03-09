#include "platform.h"
#include <SFML/Graphics/Rect.hpp>

void Platform::init(){
  platform.setSize(sf::Vector2f(200,500));
  platform.setPosition(sf::Vector2f(0,200));
  platform.setFillColor(sf::Color::White);
}

sf::FloatRect Platform::collision() {
    return platform.getGlobalBounds();
}

void Platform::draw(sf::RenderWindow& window){
  window.draw(platform);
}
