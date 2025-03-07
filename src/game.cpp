#include "game.h"

Game::Game() : window(sf::VideoMode({800,600}), "Ad-pocalypse", sf::Style::Close | sf::Style::Titlebar){
  init();
  window.setFramerateLimit(60);
  window.setKeyRepeatEnabled(false);
}

void Game::init(){
}

void Game::update(){
  while(const std::optional event = window.pollEvent()){
    if(event->is<sf::Event::Closed>()){
      window.close();
    }
  }
}

void Game::render(){
  window.clear(sf::Color::Black);
  window.display();
}

void Game::run(){
  while(window.isOpen()){
    update();
    render();
  }
}
