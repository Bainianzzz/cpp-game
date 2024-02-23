#pragma once
#include "snake.h"
#include"food.h"

class Game
{
private:
	Snake* s;
	Food* f;
	bool isDead;
	char ch;

	void start();
	void restart();

public:
	Game();
	~Game();
	void begin();
	void loop();
};

