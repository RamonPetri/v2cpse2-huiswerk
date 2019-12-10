//
// Created by ramon on 13-11-2019.
//

#ifndef V2CPSE2_RECTANGLE_HPP
#define V2CPSE2_RECTANGLE_HPP
#include <SFML/Graphics.hpp>
#include "graph_obj.hpp"

class rectangle {
private:
    sf::Vector2f rectPostion;
    sf::Vector2f rectSize;
    sf::Color color;
public:
    rectangle(sf::Vector2f rectPostion, sf::Vector2f rectSize,sf::Color color);
    void draw(sf::RenderWindow & window) const;
    void move( sf::Vector2f delta );
    sf::Vector2f get_pos();
    sf::Vector2f get_size();
};


#endif //V2CPSE2_RECTANGLE_HPP
