#include "ball.hpp"
#include "rectangle.hpp"
#include "action.hpp"
int main( int argc, char *argv[] ){
    std::cout << "Starting application muur en stuiter\n";

    sf::RenderWindow window{ sf::VideoMode{ 640, 480 }, "SFML window" };
    ball my_ball{ sf::Vector2f{ 320.0, 240.0 },sf::Vector2f{15,15} };
    rectangle rec {sf::Vector2f{100,100}, sf::Vector2f{50,50},sf::Color::Yellow};
    rectangle wallL {sf::Vector2f{0,0}, sf::Vector2f{10,480}, sf::Color::Green};
    rectangle wallR {sf::Vector2f{630,0}, sf::Vector2f{10,480}, sf::Color::Red};
    rectangle wallU {sf::Vector2f{0,0}, {640,10}, sf::Color::Magenta};
    rectangle wallD { sf::Vector2f{0,470}, sf::Vector2f{630,470}, sf::Color::Blue};

    action actions[] = {
            action( sf::Keyboard::Left,  [&](){ rec.move( sf::Vector2f( -2.0,  0.0 )); }),
            action( sf::Keyboard::Right, [&](){ rec.move( sf::Vector2f( +2.0,  0.0 )); }),
            action( sf::Keyboard::Up,    [&](){ rec.move( sf::Vector2f(  0.0, -2.0 )); }),
            action( sf::Keyboard::Down,  [&](){ rec.move( sf::Vector2f(  0.0, +2.0 )); }),
    };
 std::vector<rectangle> walls = { wallU, wallD, wallL, wallR};
 std::vector<rectangle> colison = {wallU,wallD, wallL, wallR};
    while (window.isOpen()) {
        for(auto & col : colison){ my_ball.collision(col);}
        my_ball.collision(rec);
        for( auto & action : actions ){action();}
        window.clear();
        for(auto & obj : walls){obj.draw(window);};
        rec.draw(window);
        my_ball.draw(window);
        window.display();
        my_ball.move(my_ball.get_direction());
        sf::sleep( sf::milliseconds( 20 ));

        sf::Event event;
        while( window.pollEvent(event) ){
            if( event.type == sf::Event::Closed ){
                window.close();
            }
        }
    }

    std::cout << "Terminating application\n";
    return 0;
}