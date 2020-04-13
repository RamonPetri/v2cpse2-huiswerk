//
// Created by ramon on 29-3-2020.
//

#ifndef TIC_TAC_TOE_GAME_LOGIC_HPP
#define TIC_TAC_TOE_GAME_LOGIC_HPP

#include "game_moves.hpp"
#include "game_interface.hpp"
#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "game_data.hpp"

class game_logic {
private:
    data game_data;
    std::vector<game_moves> moves;
    game_interface &gameInterface;


public:
    explicit game_logic(game_interface &anInterface);
    bool move(game_moves move);
    float check_for_win();
    bool get_last_player();
    void main();

};


#endif //TIC_TAC_TOE_GAME_LOGIC_HPP
