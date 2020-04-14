#ifndef CUSTOM_EXECPTIONS_HPP
#define CUSTOM_EXECPTIONS_HPP

#include <iostream>
#include <string>
#include <exception>
///A class which inherits from std::exception for throwing the error unknown_color
class unknown_color : public std::exception{
    private:
        std::string str;

    public:
        /// Constructor for the class unknown_color
        /// \param the name of the color which will be served to the user
        explicit unknown_color(const std::string &name):
            str{std::string {"Exception: Unknown color: "} + name + "\n"} {};

        /// Function that builds an string which contains a error message
        /// \return  a string which contains a error message and the name of the color which triggerd the exception
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();    
        }
};

///A class which inherits from std::exception for throwing the error end_of_file
class end_of_file : public std::exception{
    private:
        std::string str;

    public:
        /// Constructor for the class end_of_file
        end_of_file():
            str{std::string{"Exception: End of file reached.\n"}}{};
        /// Function that builds a string which contains a error message
        /// \return a string which contains a error message when a eof exception is encounterd
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
        
};

///A class which inherits from std::exception for throwing the error invalid_position
class invalid_position : public std::exception{
    private:
        std::string str;

    public:
        /// First constructor for the class invalid_position
        /// \param name: the name parameter expects a const char ptr
       explicit invalid_position(const char *name):
            str{std::string{"Exception: Invalid position: "} + name + "\n"}{};

        /// Second constructor for the class invalid_position
        /// \param name: the name parameter expects a const string reference
       explicit invalid_position(std::string const &name):
            str{std::string{"Exception: Invalid position: "} + name + "\n"}{};

       /// Function that builds a string which contains a error message
       /// \return a string which contains a error message when a given position is deemed invalid
       [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
};

///A class which inherits from std::exception for throwing the error unknown_shape
class unknown_shape : public std::exception{
    private:
        std::string str;

    public:
        /// constructor for the class unknown_shape
        /// \param name: the name parameter expects a const string reference
        explicit unknown_shape(const std::string &name):
            str{std::string {"Exception: Unknown shape: "} + name + "\n"}{};

        ///  Function that builds a string which contains a error message
        /// \return  a string which contains a error message when a returned request for a shape object cannot be found
        [[nodiscard]] const char *what() const noexcept override{
            return str.c_str();
        }
};

#endif