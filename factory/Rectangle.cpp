#include "Rectangle.hpp"

Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Vector2f begin_point):
    screen_object(position, color, size), origin_point(begin_point){}


std::string Rectangle::convert_object_to_string() {
    std::string stringify_position = "(" + std::to_string(int16_t(position.x)) + "," +
                                     std::to_string(int16_t(position.y)) + ") ";
    std::string object_name     = "RECTANGLE";
    std::string stringify_color = " " + color_to_string(col) + " ";
    std::string stringify_size  = "(" + std::to_string(int16_t(size.x)) + "," +
            std::to_string(int16_t(size.y)) + ")" + "\n";
    std::string stringify_object;
    stringify_object.append(stringify_position + object_name + stringify_color + stringify_size);
    return stringify_object;
}

void Rectangle::draw(sf::RenderWindow &window) {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(size);
    rectangleShape.setPosition(position);
    rectangleShape.setOrigin(origin_point);
    rectangleShape.setFillColor(col);
    window.draw(rectangleShape);
}




