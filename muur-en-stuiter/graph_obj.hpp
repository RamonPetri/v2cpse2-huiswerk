//
// Created by ramon on 21-11-2019.
//

#ifndef V2CPSE2_GRAPH_OBJ_HPP
#define V2CPSE2_GRAPH_OBJ_HPP


#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
class graph_obj {
protected:
    sf::Vector2f size;
    sf::Color color;
public:
    graph_obj(sf::Vector2f size, sf::Color color);
    virtual void draw(sf::RenderWindow & window) const = 0;

    //virtual void collied()  = 0;
};


#endif //V2CPSE2_GRAPH_OBJ_HPP
