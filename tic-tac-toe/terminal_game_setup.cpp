//
// Created by ramon on 13-4-2020.
//

#include "terminal_game_setup.hpp"

terminal_game_setup::terminal_game_setup(){};

void terminal_game_setup::start_game_setup() {
    std::cout << "Please select a game mode " << std::endl;
    std::cout << "press 1 for graphical version or ";
    std::cout << "press 2 for commandline version" <<std::endl;
    std::cout << "Please enter a choice: ";
    std::cin >> choice;
    switch(choice){
        case 1:{
            sf::RenderWindow window{sf::VideoMode{650,650},
                                    "Tic tac toe the game"};
            graphical_user_interface gui(window);
            game_logic game(gui);
            while (window.isOpen()) {
                game.main();
                sf::sleep( sf::milliseconds( 20 ));

                sf::Event event;
                while( window.pollEvent(event) ){
                    if( event.type == sf::Event::Closed ){
                        window.close();
                    }
                }
            }
            break;
        }
        case 2:{
            comand_line_interface cli;
            game_logic game(cli);
            game.main();
            break;
        }
        default: {
            std::cout << choice << " ";
            std::cout << "Please pick a valid game move" << std::endl;
            break;
        }

    }

}