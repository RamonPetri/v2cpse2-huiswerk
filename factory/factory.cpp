#include "factory.hpp"

factory::factory(){};

screen_object * factory::fact(std::ifstream &input){
    sf::Vector2f pos;
    std::string name;
    sf::Color col;
    sf::Vector2f size;
    input >> pos >> name;

    if(name == "RECTANGLE"){
        input >> col;
        input >> size; 
        return new Rectangle(pos, size, col);
    } else if(name == "CIRCLE"){
        uint16_t rad;
        input >> col;
        input >> rad;
        return new Circle(pos, col, rad);
    } else if(name == "PICTURE"){
        std::string file;
        input >> file;
        return new Picture(pos, col, size, file);
    } else if(name.empty()){
       throw end_of_file();
    }
    throw unknown_shape(name);
}

void factory::file_writer(std::ofstream &output, std::vector<screen_object *> &object_array) {
    for(const auto &object : object_array){
        output << object->convert_object_to_string();
    }
}