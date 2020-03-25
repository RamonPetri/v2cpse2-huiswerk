#ifndef CUSTOM_EXECPTIONS_HPP
#define CUSTOM_EXECPTIONS_HPP

#include <iostream>
#include <string>
#include <exception>

class unknown_color : public std::exception{
    private:
        std::string str;

    public:
        explicit unknown_color(const std::string &name):
            str{std::string {"Exception: Unknown color: "} + name + "\n"} {};
       [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();    
        }
};

class end_of_file : public std::exception{
    private:
        std::string str;

    public:
        end_of_file():
            str{std::string{"Exception: End of file reached.\n"}}{};
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
        
};

class invalid_position : public std::exception{
    private:
        std::string str;

    public:
       explicit invalid_position(const char *name):
            str{std::string{"Exception: Invalid position: "} + name + "\n"}{};
       explicit invalid_position(std::string const &name):
            str{std::string{"Exception: Invalid position: "} + name + "\n"}{};
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
};

class unknown_shape : public std::exception{
    private:
        std::string str;

    public:
        explicit unknown_shape(const std::string &name):
            str{std::string {"Exception: Unknown shape: "} + name + "\n"}{};
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
};

#endif