#include "Background.hpp"

Background::Background(){
    texture.loadFromFile("background.png");
    sprite.setTexture(texture);
    sprite.setPosition(0,0);
}

void Background::update(float deltatime){

}

void Background::draw(sf::RenderWindow &window){

}
