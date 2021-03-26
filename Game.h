#pragma once
#include "Player.h"
class Game
{
private:
	sf::RenderWindow* window;
	Player* player;

	void init();
	void initPlayer();
public:
	Game();
	virtual ~Game();

	void run();
	void update();
	void render();
};

