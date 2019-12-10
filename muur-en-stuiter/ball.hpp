#ifndef _BALL_HPP
#define _BALL_HPP
#include "rectangle.hpp"
#include <SFML/Graphics.hpp>
#include "graph_obj.hpp"
class ball {
public:

	ball( sf::Vector2f position, sf::Vector2f direction, float size = 30.0);

	void draw( sf::RenderWindow & window ) const;

	void move( sf::Vector2f delta );

	void jump( sf::Vector2f target );

	void collision(rectangle & rec);

	sf::Vector2f get_direction();
	//bool out_of_bounds(sf::Shape & moving_shape);

	sf::Vector2f get_post();

	float get_size();
private:
	sf::Vector2f position;
    sf::Vector2f dir;
	float size;

};

#endif
