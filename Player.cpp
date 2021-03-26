#include "pch.h"
#include "Player.h"

void Player::initSprite()
{
	this->sprite.setTexture(this->texture);
	this->sprite.scale(0.1f, 0.1f);
}

void Player::initTexture()
{
	if (!this->texture.loadFromFile("res/textures/spaceship.png")) {
		cout << "[ERROR]: Could not load spaceship picture" << endl;
	}
}

Player::Player()
{
	this->movementSpeed = 1.f;

	this->initTexture();
	this->initSprite();
}

Player::~Player()
{
}

void Player::move(const float dirX, const float dirY)
{
	this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
}

void Player::update()
{
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
