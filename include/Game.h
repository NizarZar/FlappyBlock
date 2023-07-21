#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <vector>

#include <random>


#define BLOCKS_MOVEMENT 5.f
#define BLOCKS_SPAWN_FREQUENCY 0.6f

// Textures
#define BLOCK_TOP_SPRITE "Textures/blocks-sprite.png"
#define BLOCK_BOTTOM_SPRITE "Textures/blocks-sprite-bottom.png"
#define WORLD_BACKGROUND "Textures/background.png"
#define GROUND_TEXTURE "Textures/land.png"


class Game {

private:
	// window and events
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;

	// variables of game logic
	bool spaceHeld;
	bool collided;
	bool gameEnd;
	unsigned int points;
	sf::Clock clock;
	int blockSpawnYOffset;
	int landHeight;


	// Resources
	sf::Font font;
	sf::Text UI;


	// Game Objects
	sf::RectangleShape player;
	std::vector<sf::Sprite> blocks;
	std::vector<sf::Sprite> lands;


	// methods
	void initWindow();
	void initVariables();
	void initPlayer();

	// Sprite and Textures
	sf::Texture blocksTextureTop;
	sf::Sprite blocksSpriteTop;
	sf::Texture blocksTextureBottom;
	sf::Sprite blocksSpriteBottom;
	sf::Texture landTexture;
	sf::Sprite landSprite;
	sf::Texture secondLandTexture;
	sf::Sprite secondLandSprite;
	sf::Texture backgroundTexture;
	sf::Sprite backgroundSprite;


public:
	Game();
	virtual ~Game();

	// Accessors
	const bool gameRunning() const;
	const bool getEndGame() const;

	// Methods
	void RandomizeBlockOffset();
	void spawnBottomBlocks();
	void spawnTopBlocks();
	void spawnInvisibleBlocks();
	void spawnInfiniteLand();
	void moveBlocks();
	void moveLand();
	void pollEvents();
	void update();
	void updatePlayer();
	void render();
};

