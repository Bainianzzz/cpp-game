#include "game.h"

Game::Game()
{
	s = new Snake;
	f = new Food;
	isDead = false;
	ch = NULL;
}

void Game::begin()
{
	//初始界面
	cout << "Adjust your forward direction by pressing \"AWDS\"" << endl;
	cout << "press \"q\" or \"Q\" to quit" << endl;
	cout << "press any key to start" << endl;
	cout << "ENJOY!!!!!" << endl;
	system("pause");
	system("cls");
}

void Game::start()
{
	//绘制游戏窗口
	int i = 0, j = 1;
	for (i = 0;i < 42;i++) {
		cout << "X";
	}
	cout << endl;

	for (i = 0;i < 20;i++) {
		cout << "X";
		gotoxy(41, j);
		j++;
		cout << "X";
		cout << endl;
	}

	for (i = 0;i < 42;i++) {
		cout << "X";
	}
	cout << endl;

	s->printbody();
	f->print();
}

void Game::loop()
{
	start();
	while (true) {
		while (!_kbhit()) {
			//没有操作自动按原方向前进
			s->move(f);
			//判断是否死亡
			if (s->isDead()) {
				isDead = true;
				break;
			}
			Sleep(250);
		}

		if (isDead) {
			system("cls");
			cout << "game over" << endl;
			s->showScore();
			cout << "press \"r\" to restart: ";
			ch = _getch();
			//重新开始
			if (ch == 'r' || ch == 'R') {
				restart();
				continue;
			}
			else {
				break;
			}
		}
		//处理键盘事件
		else {
			ch = _getch();

			if (ch == 'q' || ch == 'Q') {
				system("cls");
				cout << "是否退出(y/n): ";
				ch = _getch();
				//退出游戏
				if (ch == 'y' || ch == 'Y') {
					break;
				}
				//继续游戏
				else {
					system("cls");
					start();
				}
			}
			//处理转向
			else {
				s->turn(ch);
			}
		}
	}
}

void Game::restart()
{
	system("cls");
	delete s, f;
	s = new Snake;
	f = new Food;
	isDead = false;
	start();
}

Game::~Game()
{
	delete s, f;
}
