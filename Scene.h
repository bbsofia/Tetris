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
		float angleX, angleY; // поточний кут повороту сцени
		float width, height;  // розміри вікна
		float distZ;          // відстань по осі Z
		bool finish;          // ознака того, що гру завершено
		int time;             // поточний час у секундах
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