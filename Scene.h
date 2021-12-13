#ifndef Scene_h
#define Scene_h

#include "Tetrominos.h"
#include <vector>
#include <queue>

namespace TetrisGame
{
	class Scene
	{
		Board* border;
		std::queue<Shape*> shapes;
		Cube* elements[30][10];
		float angleX, angleY; // �������� ��� �������� �����
		float width, height;  // ������ ����
		float distZ;          // ������� �� �� Z
		bool finish;          // ������ ����, �� ��� ���������
		int time;             // �������� ��� � ��������
		int score;
		Shape* current;
		Shape* next;
	public:
		Scene();
		~Scene();
		void on_paint();
		void on_idle(int value);
		void on_size(int width, int height);
		void on_special(int key, int x, int y);
		void on_keyboard(int key, int x, int y);
		void on_timer(int value);
		void fillArr();
		void moveElements();
		void changeY();
		void changeX(float x);
		bool checkAccess(Cube* el);
	private:
		void initialize();
		void queue();
		void drawCubes();
		void writeScore(int x);
	};

}

#endif