#include "game.h"

Game::Game() : window(sf::VideoMode({800,600}), "Ad-pocalypse", sf::Style::Default){
  init();
}

void Game::init(){
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);
  player.init();
  platform.init();
}

void Game::update(){
  float dt = clock.restart().asSeconds();
  while(const std::optional event = window.pollEvent()){
    if(event->is<sf::Event::Closed>()){
      window.close();
    }
  }
  player.gravity(dt);
  player.move(dt);
}

void Game::render(){
  window.clear(sf::Color::Black);
  player.draw(window);
  platform.draw(window);
  window.display();
}

void Game::run(){
  while(window.isOpen()){
    update();
    render();
  }
}

