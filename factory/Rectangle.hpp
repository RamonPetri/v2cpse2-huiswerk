#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP


#include "screen_object.hpp"

class Rectangle : public screen_object{
private:
    sf::Vector2f origin_point;
public:
    Rectangle(sf::Vector2f position, sf::Vector2f size,
              sf::Color color, sf::Vector2f begin_point = {0,0});
    void draw(sf::RenderWindow &window) override;
    std::string convert_object_to_string() override;
};


#endif