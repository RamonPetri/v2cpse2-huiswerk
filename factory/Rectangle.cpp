#include "Rectangle.hpp"

/// Constructor of the class rectangle
/// \param position The position of the rectangle on the screen
/// \param size The size of the displayed rectangle
/// \param color The color of the displayed rectangle
/// \param begin_point The point or origin of the rectangle
Rectangle::Rectangle(sf::Vector2f position, sf::Vector2f size, sf::Color color, sf::Vector2f begin_point):
    screen_object(position, color, size), origin_point(begin_point){};

/// Converts a rectangle object to a string
/// \return a rectangle object which contains all its parameters
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

/// This function will draw a rectangle on the screen
/// \param window a reference to the window were you want to draw the rectangle on
void Rectangle::draw(sf::RenderWindow &window) {
    sf::RectangleShape rectangleShape;
    rectangleShape.setSize(size);
    rectangleShape.setPosition(position);
    rectangleShape.setOrigin(origin_point);
    rectangleShape.setFillColor(col);
    window.draw(rectangleShape);
}




