

#include "pch.h"
#include <gl/glut.h>
#include "Scene.h"

using TetrisGame::Scene;

Scene *scene; // вказівник на клас Scene

void on_paint()
{
	// Викликаємо відповідну функцію класу Scene:
	scene->on_paint();
}

void on_size(int width, int height)
{
	// Викликаємо відповідну функцію класу Scene:
	scene->on_size(width, height);
}

void on_special(int key, int x, int y)
{
	// Викликаємо відповідну функцію класу Scene:
	scene->on_special(key, x, y);
}

void on_keyboard(unsigned char key, int x, int y)
{
	scene->on_keyboard(key, x, y);
}

void on_idle(int value)
{
	scene->on_idle(value);
	glutTimerFunc(500, on_idle, 0);
}

void on_timer(int value)
{
	// Обробка події від таймера
	scene->on_timer(value);
	glutTimerFunc(25, on_timer, 0); // зa 25 мс викличеться ця функція
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);         // ініціалізуємо GLUT
	scene = new Scene();   // створюємо об'єкт "сцена"
	glutInitWindowSize(800, 600);  // встановлюємо розміри вікна
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);// ініціалізуємо режими відображення
	glutCreateWindow("Tetris");     // створюємо вікно
	glutDisplayFunc(on_paint);     // реєструємо функцію відображення
	glutReshapeFunc(on_size);      // реєструємо функцію обробки зміни розмірів вікна
	glutKeyboardFunc(on_keyboard); // реєструємо функцію, яка відповідає за натискання клавіш
	glutSpecialFunc(on_special);   // реєструємо функцію, яка відповідає за натискання спеціальних клавіш
	glutTimerFunc(25, on_timer, 0);// кожні 25 мс викликається ця функція
	glutTimerFunc(500, on_idle, 0);
	glutMainLoop();                // стартуємо основний цикл обробки подій
	delete scene;                  // видаляємо об'єкт "сцена"
	return(0);
}