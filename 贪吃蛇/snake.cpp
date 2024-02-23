#include "food.h"
#include "snake.h"

Snake::Snake() {
	Node *head = new Node{ 21,10,nullptr };
	Node *tail = new Node{ 20,10,head };
	this->head = head;
	this->tail = tail;
	pos = {1,0};
	length = 2;
}

//������
void Snake::printbody() {
	Node* t = tail;
	while (tail) {
		gotoxy(tail->x_point, tail->y_point);
		cout << "@";
		tail = tail->next;
	}
	tail = t;
}

//�ƶ������ж�ͷ���Ƿ�����ʳ��
void Snake::move(Food *f) {
	Node* n = nullptr;
	n = new Node{ head->x_point + pos.x,head->y_point + pos.y,nullptr };
	if (n->x_point == f->x && n->y_point == f->y) {
		eat(n);
		f->refresh();
	}
	else {
		head->next = n;
		head = n;

		refresh();

		n = tail;
		tail = tail->next;

		delete n;
	}
}

//�Ե�ʳ�ֻ����ͷ
void Snake::eat(Node* n) {
	head->next = n;
	head = n;
	length++;

	gotoxy(head->x_point, head->y_point);
	cout << "@";
}

//�����ƶ�������ͷ��β
void Snake::refresh() {
	gotoxy(head->x_point, head->y_point);
	cout << "@";

	gotoxy(tail->x_point, tail->y_point);
	cout << " ";
}

//����ת��
void Snake::turn(char ch) {
	if (ch == 'a'||ch == 'A') {
		if (pos.x != 1 && pos.y != 0) {
			pos = { -1,0 };
		}
	}else if (ch == 'd' || ch == 'D') {
		if (pos.x != -1 && pos.y != 0) {
			pos = { 1,0 };
		}
	}
	else if (ch == 'w' || ch == 'W') {
		if (pos.x != 0 && pos.y != 1) {
			pos = { 0,-1 };
		}
	}
	else if (ch == 's' || ch == 'S') {
		if (pos.x != 0 && pos.y != -1) {
			pos = { 0,1 };
		}
	}
}

//�ж��Ƿ�����ǽ�ڻ�����
bool Snake::isDead() {
	if (head->x_point < 1 || head->x_point>40 || head->y_point < 1 || head->y_point>20) {
		return true;
	}
	else {
		Node* t = tail;
		while (tail->next) {
			if (head->x_point == tail->x_point && head->y_point == tail->y_point) {
				return true;
			}
			tail = tail->next;
		}
		tail = t;
	}
	return false;
}

//չʾ����
void Snake::showScore() {
	cout << "your score is " << length << endl;
}

Snake::~Snake() {
	Node* n = nullptr;
	while (this->tail) {
		n = tail->next;
		delete this->tail;
		tail = n;
	}
}