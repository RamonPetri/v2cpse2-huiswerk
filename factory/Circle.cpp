#include "Circle.hpp"
/// Constructor for the class circle
/// \param position: Represents the draw position of the circle on the screen
/// \param color: Represents the color of the circle
/// \param size: Represents the size of the circle
Circle::Circle(sf::Vector2f position, sf::Color color, float size):
    screen_object(position, color, sf::Vector2f{size,0}){};

/// This function draws a circle on the screen
/// \param window: Represents a reference to a window you wish to draw the circle on
void Circle::draw(sf::RenderWindow &window) {
    sf::CircleShape CircleShape;
    CircleShape.setRadius(size.x);
    CircleShape.setOrigin(sf::Vector2f{size.x, size.x});
    CircleShape.setPosition(position);
    CircleShape.setFillColor(col);
    window.draw(CircleShape);
}

/// This function converts the circle object to string for saving it in a txt file
/// \return a string representation of the circle object
std::string Circle::convert_object_to_string() {
    std::string stringify_position = "(" + std::to_string(int16_t(position.x)) + "," +
            std::to_string(int16_t(position.y)) + ") ";
    std::string object_name     = "CIRCLE ";
    std::string stringify_color = color_to_string(col) + " ";
    std::string stringify_size  = std::to_string(int16_t(size.x)) + "\n";
    std::string stringify_object;
    stringify_object.append(stringify_position + object_name + stringify_color + stringify_size);
    return stringify_object;
}