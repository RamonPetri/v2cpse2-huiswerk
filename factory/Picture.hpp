#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "screen_object.hpp"

class Picture : public screen_object{
private:
    std::string path_to_file;
public:
    Picture(sf::Vector2f position, sf::Color color, sf::Vector2f size, std::string &file_path);
    void draw(sf::RenderWindow &window) override;
    std::string convert_object_to_string() override;
};
#endif