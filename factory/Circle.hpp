#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <SFML/System.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "screen_object.hpp"

/// This class can draw circles to the screen
class Circle : public screen_object {
public:
    Circle(sf::Vector2f position, sf::Color color, float size=30.0);
    void draw(sf::RenderWindow &window) override;
    std::string convert_object_to_string() override;
};

#endif