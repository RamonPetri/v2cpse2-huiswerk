#include <SFML/Graphics.hpp>
#include "ball.hpp"
#include "rectangle.hpp"
#include "iostream"
#include "graph_obj.hpp"
ball::ball( sf::Vector2f position, sf::Vector2f direction, float size) :
	position{ position },
	dir{ direction },
    size{ size }
{}

sf::Vector2f ball::get_post() {
    return position;
}

float ball::get_size(){
    return size;
}

void ball::draw( sf::RenderWindow & window ) const {
	sf::CircleShape circle;
	circle.setRadius(size);
	circle.setPosition(position);
	circle.setFillColor(sf::Color ::Blue);
	window.draw(circle);
}

void ball::move( sf::Vector2f delta ) {
	position += delta;
}

void ball::jump( sf::Vector2f target ) {
	position = target;
}

sf::Vector2f ball::get_direction() {
    return dir;

}
void ball::collision(rectangle & rect ) {
    sf::FloatRect ball(position, sf::Vector2f{size * 2, size * 2});
    sf::FloatRect rec(rect.get_pos(), rect.get_size());
    sf::FloatRect result;
    if (ball.intersects(rec, result)) {
        sf::Vector2f ball_x_y_mid_point{ball.left + ball.width / 2, ball.top + ball.height / 2};
        sf::Vector2f rect_x_y_mid_point{result.left + result.width / 2, result.top + result.height / 2};
        int v_x = abs(rect_x_y_mid_point.x - ball_x_y_mid_point.x);
        int v_y = abs(rect_x_y_mid_point.y - ball_x_y_mid_point.y);
        if (v_x > v_y){
            dir.x =  dir.x * -1;
        } else{
            dir.y = dir.y * -1;
        }
    }
}