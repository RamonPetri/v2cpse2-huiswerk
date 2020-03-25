#include "screen_object.hpp"
#include "custom_execptions.hpp"

screen_object::screen_object(sf::Vector2f position, sf::Color color, sf::Vector2f size):
        col(color), position(position), size(size){}


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

bool screen_object::is_within(sf::Vector2<int> coordinates){
    return (coordinates >= this->position) && (coordinates <= (this->position + this->size));
}

