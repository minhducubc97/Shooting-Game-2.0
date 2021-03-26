#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Player
{
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float movementSpeed;

	void initTexture();
	void initSprite();

public:
	Player();
	virtual ~Player();

	void move(const float dirX, const float dirY);
	void update();
	void render(sf::RenderTarget& target);
};