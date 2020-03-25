#include "Picture.hpp"

Picture::Picture(sf::Vector2f position, sf::Color color, sf::Vector2f size, std::string &file_path):
        screen_object(position, color, size), path_to_file(file_path){
    sf::Texture texture;
    texture.loadFromFile(path_to_file);
    this->size.x = float(texture.getSize().x);
    this->size.y = float(texture.getSize().y);
};

void Picture::draw(sf::RenderWindow &window) {
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile(path_to_file);
    sprite.setPosition(position);
    sprite.setTexture(texture);
    window.draw(sprite);
}

std::string Picture::convert_object_to_string() {
    std::string stringify_position = "(" + std::to_string(int16_t(position.x)) + "," +
                                     std::to_string(int16_t(position.y)) + ") ";
    std::string object_name     = "PICTURE ";
    std::string file_name       = " "+ path_to_file + "\n";
    std::string stringify_object;
    stringify_object.append(stringify_position + object_name + file_name);
    return stringify_object;
}