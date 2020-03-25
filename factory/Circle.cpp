#include "Circle.hpp"

Circle::Circle(sf::Vector2f position, sf::Color color, float size):
    screen_object(position, color, sf::Vector2f{size,0}){};

void Circle::draw(sf::RenderWindow &window) {
    sf::CircleShape CircleShape;
    CircleShape.setRadius(size.x);
    CircleShape.setOrigin(sf::Vector2f{size.x, size.x});
    CircleShape.setPosition(position);
    CircleShape.setFillColor(col);
    window.draw(CircleShape);
}
void Circle::jump(sf::Vector2f target) {
    position = target;
}

void Circle::jump(sf::Vector2i target) {
    jump(sf::Vector2f(
            static_cast< float >( target.x ),
            static_cast< float >( target.y )
    ));
}

void Circle::move(sf::Vector2f delta) {
    position += delta;
}

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