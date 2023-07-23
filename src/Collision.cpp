#include "Collision.h"


Collision::Collision() {
}

bool Collision::checkSpriteCollision(sf::RectangleShape object, sf::Sprite secondObjectSprite) {

	sf::Rect<float> spriteRectangle = secondObjectSprite.getGlobalBounds();
	sf::Rect<float> objectRectangle = object.getGlobalBounds();

	if (objectRectangle.intersects(spriteRectangle)) {
		return true;
	}
	else {
		return false;
	}

}

bool Collision::checkSpriteCollision(sf::RectangleShape object, float scale1, sf::Sprite secondObjectSprite, float scale2) {

	object.setScale(scale1, scale2);
	secondObjectSprite.setScale(scale1, scale2);

	sf::Rect<float> spriteRectangle = secondObjectSprite.getGlobalBounds();
	sf::Rect<float> objectRectangle = object.getGlobalBounds();

	if (objectRectangle.intersects(spriteRectangle)) {
		return true;
	}
	else {
		return false;
	}

}
