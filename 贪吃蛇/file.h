#pragma once

#include<iostream>
#include<windows.h>
#include<conio.h>

using namespace std;

struct Node
{
	int x_point, y_point;
	Node* next;
};

struct Pos
{
	short int x, y;
};

void gotoxy(int x, int y);

class Snake;
class Food;
class Game;