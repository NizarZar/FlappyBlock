#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <random>

#include "Collision.h"


#define LAND_MOVEMENT 5.f
#define BLOCKS_SPAWN_FREQUENCY 0.6f

// WINDOW
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024

// Textures
#define BLOCK_TOP_SPRITE "Textures/blocks-sprite.png"
#define BLOCK_BOTTOM_SPRITE "Textures/blocks-sprite-bottom.png"
#define WORLD_BACKGROUND "Textures/background.png"
#define GROUND_SPRITE "Textures/land.png"

// block states
#define BLOCK_STATE_STILL 1 
#define BLOCK_STATE_FALLING 2 
#define BLOCK_STATE_JUMPING 3

#define GRAVITY 225.f
#define JUMP_SPEED 225.f
#define JUMP_DURATION 0.5f

enum GameStates{
	readyState,
	playingState,
	gameOverState
};



class Game {

private:

	// window and events
	sf::RenderWindow* window;
	sf::Event event;
	sf::VideoMode videoMode;
	const float dt = 1.0f / 60.f;


	// Collision
	Collision collision;

	// variables of game logic
	bool spaceHeld;
	bool collided;
	bool gameEnd;
	unsigned int points;
	// classic clock
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


	// player and movement clock
	sf::Clock playerClock;
	sf::Clock movementClock;
	int playerState;

	int gameState;


	// methods
	void initWindow();
	void initVariables();
	void initPlayer();
	void RandomizeBlockOffset();
	void spawnBottomBlocks();
	void spawnTopBlocks();
	void spawnInfiniteLand();
	void moveBlocks();
	void moveLand();
	void pollEvents();
	void updatePlayer();
	void jumpPlayer();

	const std::vector<sf::Sprite>& GetLandSprite() const;

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
	void update();
	void render();
};

