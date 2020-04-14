#include "screen_object.hpp"
#include "custom_execptions.hpp"

/// Constructor for the class screen_object which is a superclass for all objects that are displayed
/// \param position: Value for setting the position of a particular object
/// \param color: Value for setting the color of a particular object
/// \param size: Value for setting the size of a particular object
screen_object::screen_object(sf::Vector2f position, sf::Color color, sf::Vector2f size):
        col(color), position(position), size(size){}

/// Function that will convert sfml colors to a std::string
/// \param input: A value that represents a SFML color object
/// \return std::string wich contains the value of the sfml object for example from sf::Color::Yellow to "yellow"
std::string screen_object::color_to_string(sf::Color &input) {
    struct {
        const char * name_color{};
        sf::Color col;
    } colors[]{
            {"yellow",  sf::Color::Yellow},
            { "cyan",   sf::Color::Cyan},
            {"black",   sf::Color::Black},
            {"white",   sf::Color::White},
            {"blue",    sf::Color::Blue},
            {"red",     sf::Color::Red},
            {"green",   sf::Color::Green},
            {"Magenta", sf::Color::Magenta}};
    for(auto const color: colors){
        if(color.col == input){
            std::string stringify_color;
            stringify_color += color.name_color;
            return stringify_color;
        }
    }
    throw unknown_color("Not a color");
}

/// Function that will check if the input coordinates intersect with the position of the object
/// \param coordinates: the coordinates of something you want to check on intersecting
/// \return Boolean value which represents ether a intersection or not
bool screen_object::is_within(sf::Vector2<int> coordinates){
    return (coordinates >= this->position) && (coordinates <= (this->position + this->size));
}

