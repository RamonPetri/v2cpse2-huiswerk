#include "operators.hpp"
#include "custom_execptions.hpp"

/// Overloaded operator >> to facilitate the printing of a sf::Color object
/// \param input a input file stream which contains strings colors e.g "yellow"
/// \param rhs a sf::Color object
/// \return a input file stream object which contains the found color
std::ifstream &operator >>(std::ifstream &input, sf::Color &rhs){
    std::string str;
    input >> str;
    const struct { const char * name; sf::Color color; } colors[]{
       { "yellow", sf::Color::Yellow },
       { "red",    sf::Color::Red },
       { "black", sf::Color::Black},
       { "blue", sf::Color::Blue},
       { "green", sf::Color::Green},
       { "white", sf::Color::White},
       { "magenta", sf::Color::Magenta}
   };
   for (auto const &color : colors){
       if(color.name == str){
           rhs = color.color;
           return input;
       }
   }
   if(str == ""){
       end_of_file();
   }
   throw unknown_color(str);
};

/// Overloaded operator >> to facilitate the printing of a sf::Color object
/// \param input a input file stream which contains strings colors e.g "yellow"
/// \param rhs a sf::Color object
/// \return a input file stream object which contains the found color
std::ifstream &operator >>(std::ifstream &input, sf::Vector2f &rhs){
    char ch;
    std::string str;
    if(!(input >> ch)){throw end_of_file();}
    if(ch != '('){throw invalid_position(reinterpret_cast<const char *>(ch));}
    str += "(";
    if(!(input >> rhs.x)){}
    str += std::to_string(rhs.x);
    if(!(input >> ch)){}
    str += ",";
    if(!(input >> rhs.y)){}
    str += std::to_string(rhs.y);
    if(!(input >> ch)){}
    if(ch != ')'){throw invalid_position(reinterpret_cast<const char *>(ch));}
    return input;
};

/// Overloaded operator >= to facilitate the comparision between a interger vector and a float vector
/// \param lhs a sf::vector of interges
/// \param rhs a sf::vector of floats
/// \return either true or false depending the values of the vectors
bool operator >=(sf::Vector2i &lhs, sf::Vector2f &rhs){
    if(lhs.x < rhs.x){
        return false;
    } else{
        return lhs.y >= rhs.y;
    }

}

/// Overloaded operator <= to facilitate the comparision between a interger vector and a float vector
/// \param lhs a sf::vector of interges
/// \param rhs a sf::vector of floats
/// \return either true or false depending the values of the vectors
bool operator <=(sf::Vector2i &lhs, sf::Vector2f rhs){
    if(lhs.x > rhs.x){
        return false;
    } else{
        return lhs.y <= rhs.y;
    }
}
