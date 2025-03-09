#include "platform.h"

void Platform::init(){
  platform.setSize(sf::Vector2f(200,500));
  platform.setPosition(sf::Vector2f(0,200));
  platform.setFillColor(sf::Color::White);
}

void Platform::draw(sf::RenderWindow& window){
  window.draw(platform);
}
