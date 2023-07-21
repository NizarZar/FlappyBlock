#include "Game.h"


Game::Game() {
	initVariables();
	initWindow();
	initPlayer();
}

Game::~Game() {
	delete this->window;
}

void Game::initVariables() {
	this->window = nullptr;
	this->spaceHeld = false;
	this->collided = false;
	this->gameEnd = false;
	this->points = 0;
	this->blockSpawnYOffset = 0;
	this->font.loadFromFile("Fonts/ARLRDBD.TTF");

	if (!this->blocksTextureTop.loadFromFile(BLOCK_TOP_SPRITE)) {
		std::cout << "Error on loading texture" << std::endl;
	}
	this->blocksSpriteTop.setTexture(this->blocksTextureTop);
	if (!this->blocksTextureBottom.loadFromFile(BLOCK_BOTTOM_SPRITE)) {
		std::cout << "Error on loading texture" << std::endl;
	}
	this->blocksSpriteBottom.setTexture(this->blocksTextureBottom);

	this->UI.setFont(this->font);
	this->UI.setCharacterSize(14);
	this->UI.setFillColor(sf::Color::White);
	this->UI.setString("NULL");
}

void Game::initWindow() {
	this->videoMode.height = 720;
	this->videoMode.width = 1280;

	this->window = new sf::RenderWindow(this->videoMode, "Flappy Block", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Game::initPlayer() {
	this->player.setFillColor(sf::Color::Yellow);
	this->player.setPosition(150.f, 150.f);
	this->player.setOutlineThickness(0.01f);
	this->player.setSize(sf::Vector2f(25.f, 25.f));
	this->player.setScale(sf::Vector2f(1.f, 1.f));
}


const bool Game::gameRunning() const {
	return this->window->isOpen();
}

const bool Game::getEndGame() const {
	return this->gameEnd;
}

void Game::pollEvents() {
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape) this->window->close();
			break;
		}
	}
}

void Game::spawnBottomBlocks() {
	this->blocksSpriteBottom.setPosition(this->window->getSize().x, this->window->getSize().y - this->blocksSpriteBottom.getLocalBounds().height - blockSpawnYOffset);
	blocks.push_back(this->blocksSpriteBottom);
}

void Game::spawnTopBlocks() {
	this->blocksSpriteTop.setPosition(this->window->getSize().x, -blockSpawnYOffset);
	blocks.push_back(this->blocksSpriteTop);
}

void Game::moveBlocks() {
	for (unsigned short int i = 0; i < blocks.size(); i++) 
	{
		if (blocks.at(i).getPosition().x < 0 - blocks.at(i).getGlobalBounds().width) 
		{
			blocks.erase(blocks.begin() + i);
		}
		else {
			float movement = BLOCKS_MOVEMENT;
			blocks.at(i).move(-movement, 0.f);
		}
	}
}
void Game::RandomizeBlockOffset() {
	blockSpawnYOffset = rand() % (450);
}

void Game::updatePlayer() {
	this->player.move(1.f, 1.f);

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (!this->spaceHeld) {
			this->spaceHeld = true;
			this->player.move(1.5f, -25.0f);
			this->points++;
			std::cout << "Space pressed" << std::endl;
		}
	}
	else {
		this->spaceHeld = false;
	}
}

void Game::update() {
	this->pollEvents();
	if (!this->gameEnd) {
		this->updatePlayer();
		this->moveBlocks();
		if (this->clock.getElapsedTime().asSeconds() > BLOCKS_SPAWN_FREQUENCY) {

			this->RandomizeBlockOffset();
			this->spawnBottomBlocks();
			this->spawnTopBlocks();
			clock.restart();
		}
	}

	std::stringstream stringS;
	stringS << "Points: " << this->points << std::endl;
	this->UI.setString(stringS.str());

	if (this->collided) {
		gameEnd = true;
	}

}

void Game::render() {

	this->window->clear(sf::Color::Black);
	this->window->draw(this->player);
	for (unsigned short int i = 0; i < blocks.size(); i++) {
		this->window->draw(blocks.at(i));
	}
	this->window->draw(this->UI);

	this->window->display();

}





