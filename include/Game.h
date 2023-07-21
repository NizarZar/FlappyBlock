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
#define BLOCKS_SPAWN_FREQUENCY 0.4f

// Textures
#define BLOCK_TOP_SPRITE "Textures/blocks-sprite.png"
#define BLOCK_BOTTOM_SPRITE "Textures/blocks-sprite-bottom.png"
#define WORLD_BACKGROUND "Textures/background.png"

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


	// Resources
	sf::Font font;
	sf::Text UI;


	// Game Objects
	sf::RectangleShape player;
	std::vector<sf::Sprite> blocks;


	// methods
	void initWindow();
	void initVariables();
	void initPlayer();

	// Sprite and Textures
	sf::Texture blocksTextureTop;
	sf::Sprite blocksSpriteTop;
	sf::Texture blocksTextureBottom;
	sf::Sprite blocksSpriteBottom;


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
	void moveBlocks();
	void pollEvents();
	void update();
	void updatePlayer();
	void render();
};

