#include "player.h"

void Player::init(){
  player.setSize(sf::Vector2f(50,50));
  player.setPosition(sf::Vector2f(0.0f,0.0f));
  player.setFillColor(sf::Color::Blue);
  player.setOutlineColor(sf::Color::White);
  player.setOutlineThickness(5.0f);
}

void Player::gravity(float dt){
  velocity.y += g * dt;
  if(velocity.y > max_g){
    velocity.y = max_g;
  }
  player.move(velocity * dt);
}

void Player::move(float dt){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
    velocity.x = -speed;
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
    velocity.x = speed;
  }
  else{
    velocity.x = 0;
  }
  player.move(velocity * dt);
}

void Player::draw(sf::RenderWindow& window){
  window.draw(player);
}
