#pragma once
#include"file.h"

class Snake
{
private:
	Node *head,*tail;
	Pos pos;
	int length;

	void refresh();
	void eat(Node *n);

public:
	Snake();
	~Snake();
	void printbody();
	bool isDead();
	void showScore();
	void move(Food *f);
	void turn(char ch);
};

