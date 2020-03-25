#include <iostream>
#include <functional>
#include <SFML/Graphics.hpp>
#include "factory.hpp"
#include "custom_execptions.hpp"
#include <vector>
#include <unistd.h>

int main( int argc, char *argv[] ){
    std::ifstream input_file("factoryInput.txt");
    sf::RenderWindow window{ sf::VideoMode{ 800, 800 }, "SFML window" };
    std::vector<screen_object *> object_arr{};
    volatile bool can_read = true;

    while (window.isOpen()) {
        try{
            for(;can_read;){
                object_arr.push_back(factory::fact(input_file));
                usleep(100000);
            }
        } catch(const end_of_file &){
           can_read = false;
        } catch(std::exception & ex){
            std::cout << ex.what() << std::endl;
        } catch(...){
            std::cout << "An unexpected error has occurrd" << std::endl;
        }

        for(const auto &obj : object_arr){
            obj->draw(window);
        }

        for(const auto &obj : object_arr){
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && obj->is_within(sf::Mouse::getPosition(window))){
                sf::Vector2f old_position = obj->position;
                sf::Vector2f mouse_position = {static_cast<float>(sf::Mouse::getPosition(window).x),
                                               static_cast<float>(sf::Mouse::getPosition(window).y)};
                sf::Vector2f delta_position = mouse_position - old_position;
                while(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                    mouse_position = {static_cast<float>(sf::Mouse::getPosition(window).x),
                                      static_cast<float>(sf::Mouse::getPosition(window).y)};
                    obj->position = mouse_position - delta_position;
                    for(const auto &object : object_arr){
                        object->draw(window);
                    }
                    window.display();
                    window.clear();
                }
            }
        }
        window.display();
        window.clear();
        sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                window.close();
            }
        }
    }
    std::ofstream output("factoryOutput.txt");
    factory::file_writer(output,object_arr);
    std::cout << "Terminating application\n";
    return 0;
}
