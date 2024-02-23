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
	//��ʼ����
	cout << "Adjust your forward direction by pressing \"AWDS\"" << endl;
	cout << "press \"q\" or \"Q\" to quit" << endl;
	cout << "press any key to start" << endl;
	cout << "ENJOY!!!!!" << endl;
	system("pause");
	system("cls");
}

void Game::start()
{
	//������Ϸ����
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
			//û�в����Զ���ԭ����ǰ��
			s->move(f);
			//�ж��Ƿ�����
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
			//���¿�ʼ
			if (ch == 'r' || ch == 'R') {
				restart();
				continue;
			}
			else {
				break;
			}
		}
		//��������¼�
		else {
			ch = _getch();

			if (ch == 'q' || ch == 'Q') {
				system("cls");
				cout << "�Ƿ��˳�(y/n): ";
				ch = _getch();
				//�˳���Ϸ
				if (ch == 'y' || ch == 'Y') {
					break;
				}
				//������Ϸ
				else {
					system("cls");
					start();
				}
			}
			//����ת��
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
