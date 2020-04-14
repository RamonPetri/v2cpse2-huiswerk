#include "Picture.hpp"


/// Constructor for the class picture
/// \param position The position of the picture
/// \param color altho this is not nessacery for a picture the screen object constructor requiers this
/// \param size altho this is not nessacery for a picture the screen object constructor requiers this
/// \param file_path the file path where the picture is located
Picture::Picture(sf::Vector2f position, sf::Color color, sf::Vector2f size, std::string &file_path):
        screen_object(position, color, size), path_to_file(file_path){
    sf::Texture texture;
    texture.loadFromFile(path_to_file);
    this->size.x = float(texture.getSize().x);
    this->size.y = float(texture.getSize().y);
};

/// This function will draw a picture on the screen
/// \param window a reference to the window u wish to draw on
void Picture::draw(sf::RenderWindow &window) {
    sf::Sprite sprite;
    sf::Texture texture;
    texture.loadFromFile(path_to_file);
    sprite.setPosition(position);
    sprite.setTexture(texture);
    window.draw(sprite);
}

/// This function will convert the object picture to a string
/// \return a string representing a object of class picture
std::string Picture::convert_object_to_string() {
    std::string stringify_position = "(" + std::to_string(int16_t(position.x)) + "," +
                                     std::to_string(int16_t(position.y)) + ") ";
    std::string object_name     = "PICTURE ";
    std::string file_name       = " "+ path_to_file + "\n";
    std::string stringify_object;
    stringify_object.append(stringify_position + object_name + file_name);
    return stringify_object;
}