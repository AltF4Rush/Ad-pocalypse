#include "player.h"
#include "platform.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <chrono>

void Player::init(){
  player.setSize(sf::Vector2f(25,25));
  player.setPosition(sf::Vector2f(0.0f,0.0f));
  player.setFillColor(sf::Color::Blue);
}

void Player::gravity(float dt){
  if (!isGrounded){  
        velocity.y += g * dt;
        if (velocity.y > max_g) {
            velocity.y = max_g;
        }
    }

    player.move(velocity * dt);
}

void Player::collision(const Platform& platform, float dt){  
    sf::FloatRect PlayerBounds = player.getGlobalBounds();
    sf::FloatRect PlatformBounds = platform.platform.getGlobalBounds();    
    if (PlayerBounds.findIntersection(PlatformBounds )) {
      sf::Vector2f pevPosition = player.getPosition();
      if(velocity.y > 0 and pevPosition.y + PlatformBounds.position.y <= PlatformBounds.size.y){
        player.setPosition(sf::Vector2f(player.getPosition().x, PlatformBounds.position.y - PlayerBounds.size.y));
        velocity.y = 0;
        isGrounded = true; 
      }
    }
    else{
      isGrounded = false;
    }
}

void Player::move(float dt){
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
    velocity.x = -speed;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
    velocity.x = speed;
  }
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) and sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)){
    velocity.x = 0;
  }
  else{
    velocity.x = 0;
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) and isGrounded){
    velocity.y = -jump_height;
    isGrounded = false;
  }
  else{
    isGrounded = true;
  }
  player.move(velocity * dt);
}


void Player::draw(sf::RenderWindow& window){
  window.draw(player);
}
