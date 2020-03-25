#ifndef SCREEN_OBJECT_HPP
#define SCREEN_OBJECT_HPP

#include <SFML/Graphics.hpp>
#include "operators.hpp"

class screen_object{
    protected:
        sf::Color col;
    public: 
        sf::Vector2f position;
        sf::Vector2f size;
        sf::Vector2f origin;
        screen_object(sf::Vector2f position, sf::Color color,
        sf::Vector2f size);
        std::string color_to_string(sf::Color &input);
        virtual void draw(sf::RenderWindow &window)=0;
        virtual std::string convert_object_to_string()=0;
        virtual bool is_within(sf::Vector2<int> coordinates);
};
#endif