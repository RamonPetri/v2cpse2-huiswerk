#include "factory.hpp"

/// default empty constructor for the class factory
factory::factory(){};

/// This function will convert strings in a text file into objects on the screen via the factory pattern
/// \param input : a std input file stream object
/// \return a object of either class rectangle, circle or picture
/// \example std::ifstream input_file("a_path_to_file);
///          factory::fact(input_file);
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

/// This function will convert a vector of screen objects into a output file stream
/// so it can be saved in a text file
/// \param output: a std output file stream object
/// \param object_array: a vector of type screen_object ptrs
/// \example std::vector<screen_object *> objects = {obj1,obj2,obj3}; std::ofstream out(outputFile.txt);
///          factory::file_witer(out, objects);
void factory::file_writer(std::ofstream &output, std::vector<screen_object *> &object_array) {
    for(const auto &object : object_array){
        output << object->convert_object_to_string();
    }
}