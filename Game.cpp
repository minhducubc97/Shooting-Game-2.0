#include "pch.h"
#include "Game.h"

void Game::init()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Space Shooter", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(144);
	this->window->setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
	this->player = new Player();
}

Game::Game()
{
	this->init();
	this->initPlayer();
}

Game::~Game()
{
	delete this->window;
	delete this->player;
}

void Game::run()
{
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}

void Game::update()
{
	sf::Event e;
	while (this->window->pollEvent(e)) {
		if (e.Event::type == sf::Event::Closed) this->window->close();
		if (e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape) this->window->close();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) this->player->move(-1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) this->player->move(1.f, 0.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) this->player->move(0.f, -1.f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) this->player->move(0.f, 1.f);
}

void Game::render()
{
	this->window->clear();
	this->player->render(*this->window);
	this->window->display();
}
