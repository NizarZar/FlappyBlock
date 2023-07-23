#pragma once
#include <SFML/Graphics.hpp>


class Collision {

private:



public:
	Collision();
	// basic detection with rectangles
	bool checkSpriteCollision(sf::RectangleShape object, sf::Sprite secondObjectSprite);

	// collision detection method
	bool checkSpriteCollision(sf::RectangleShape object, float scale1, sf::Sprite secondObjectSprite, float scale2);

};