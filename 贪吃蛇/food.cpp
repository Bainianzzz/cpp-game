#include "food.h"

Food::Food() {
	srand(time(nullptr));//�������������
	x = rand() % 40 + 1;//����һ�������
	y = rand() % 20 + 1;
}

void Food::print() {
	gotoxy(x, y);
	cout << "$";
}

void Food::refresh() {
	srand(time(nullptr));//�������������
	x = rand() % 40 + 1;//����һ�������
	y = rand() % 20 + 1;
	print();
}