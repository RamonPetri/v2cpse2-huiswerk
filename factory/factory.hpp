#include <iostream>
#include <string>
#include <fstream>
#include "screen_object.hpp"
#include "Rectangle.hpp"
#include "Circle.hpp"
#include "Picture.hpp"
#include <SFML/Graphics.hpp>
#include "operators.hpp"
#include "custom_execptions.hpp"

class factory{

    public:
        factory();
        static screen_object * fact(std::ifstream &input);
        static void file_writer(std::ofstream &output, std::vector<screen_object *> & object_array);

};