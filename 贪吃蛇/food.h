#pragma once
#include"file.h"

class Food
{
	friend Snake;

private:
	int x, y;
public:
	Food();
	void print();
	void refresh();
};

