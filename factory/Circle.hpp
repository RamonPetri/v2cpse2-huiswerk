#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "screen_object.hpp"
class Circle : public screen_object {
public:
    Circle(sf::Vector2f position, sf::Color color, float size=30.0);
    void draw(sf::RenderWindow &window) override;
    void jump(sf::Vector2f target);
    void jump(sf::Vector2i target);
    void move(sf::Vector2f delta);
    std::string convert_object_to_string() override;
};

#endif