#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>

#ifndef OPERATORS_HPP
#define OPERATORS_HPP

std::ifstream &operator >>(std::ifstream &input, sf::Color &rhs);
std::ifstream &operator >>(std::ifstream &input, sf::Vector2f &rhs);
bool operator >=(sf::Vector2i &lhs, sf::Vector2f &rhs);
bool operator <=(sf::Vector2i &lhs, sf::Vector2f rhs);
#endif