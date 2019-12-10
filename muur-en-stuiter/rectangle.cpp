//
// Created by ramon on 13-11-2019.
//

#include "rectangle.hpp"
rectangle::rectangle(sf::Vector2f rectPostion, sf::Vector2f rectSize,sf::Color color):
    rectPostion(rectPostion),
    rectSize(rectSize),
    color(color)
{}

sf::Vector2f rectangle::get_pos() {
    return rectPostion;
}

sf::Vector2f rectangle::get_size() {
    return rectSize;
}

void rectangle::move(sf::Vector2f delta) {
    rectPostion += delta;
}

void rectangle::draw(sf::RenderWindow & window) const{
    sf::RectangleShape rectangle;
    rectangle.setPosition(rectPostion);
    rectangle.setSize(rectSize);
    rectangle.setFillColor(color);
    window.draw(rectangle);
}
