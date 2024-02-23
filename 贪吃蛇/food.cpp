#include "food.h"

Food::Food() {
	srand(time(nullptr));//设置随机数种子
	x = rand() % 40 + 1;//产生一个随机数
	y = rand() % 20 + 1;
}

void Food::print() {
	gotoxy(x, y);
	cout << "$";
}

void Food::refresh() {
	srand(time(nullptr));//设置随机数种子
	x = rand() % 40 + 1;//产生一个随机数
	y = rand() % 20 + 1;
	print();
}