#include "pch.h"
#define _CRT_SECURE_NO_WARNINGS
#include <gl/glut.h>
#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include "Scene.h"
#include "utils.h"
#include "Tetrominos.h"
namespace TetrisGame
{
	using namespace GraphUtils;

	Scene::Scene()
	{
		border = new Board(-0.34, -0.1, -0.1, 1, 0.1, 1, diffWhite, ambiWhite, specWhite);
		// ��������� ����������� ��������� ����� ������ ����:
		initialize();
	}

	Scene::~Scene()
	{
		// ��������� �� ������:
		while (!shapes.empty())
		{
			shapes.pop();
		}
		delete border;
		for (int i = 0; i < 30; ++i)
			delete[] elements[i];
		delete[] elements;
	}

	void Scene::queue()
	{
		for (int i = 0; i < 3; ++i)
		{
			int number = rand() % 70;
			if (number >= 0 && number < 10)
				shapes.push(new Tetromino1(0.8, 0.2, 0.0, 1, 0.1, 1, diffGreen, ambiGreen, specGreen));
			if (number >= 10 && number < 20)
				shapes.push(new Tetromino2(0.8, 0.2, 0.0, 1, 0.1, 1, diffRed, ambiRed, specRed));
			if (number >= 20 && number < 30)
				shapes.push(new Tetromino3(0.8, 0.2, 0.0, 1, 0.1, 1, diffYellow, ambiYellow, specYellow));
			if (number >= 30 && number < 40)
				shapes.push(new Tetromino4(0.8, 0.2, 0.0, 1, 0.1, 1, diffBlue, ambiBlue, specBlue));
			if (number >= 40 && number < 50)
				shapes.push(new Tetromino5(0.8, 0.2, 0.0, 1, 0.1, 1, diffOrange, ambiOrange, specOrange));
			if (number >= 50 && number < 60)
				shapes.push(new Tetromino6(0.8, 0.2, 0.0, 1, 0.1, 1, diffLightBlue, ambiLightBlue, specLightBlue));
			if (number >= 60 && number < 70)
				shapes.push(new Tetromino7(0.8, 0.2, 0.0, 1, 0.1, 1, diffViolet, ambiViolet, specViolet));
		}
	}

	void Scene::moveElements()
	{
		current = shapes.front();
		current->setIn();
		shapes.pop();
		if (shapes.empty())
			queue();
		next = shapes.front();
	}

	// ����������� ����� (���������� ��������, � ���� � ������ ���������� ���):
	void Scene::initialize()
	{
		while (!shapes.empty())
			shapes.pop();
		// ����������� �������� �����:
		distZ = -2;
		angleX = -5;
		angleY = 10;
		time = 0;
		score = 0;
		finish = false;
		for (int i = 0; i < 30; ++i)
		{
			for (int j = 0; j < 10; ++j)
				elements[i][j] = nullptr;
		}
		queue();
		moveElements();
	}

	void Scene::drawCubes()
	{
		for (int i = 0; i < 30; ++i)
		{
			int total = 0;
			for (int j = 0; j < 10; ++j)
			{
				if (elements[i][j] != nullptr)
				{
					elements[i][j]->draw();
					total++;
				}
			}
			if (!total)
				break;
			//���� ����� ������� ���������� - ������� ����
			if (total == 10)
			{
				for (int j = 0; j < 10; ++j)
				{
					delete elements[i][j];
					elements[i][j] = nullptr;
				}
				//��������� �� ������ �� ���� ������� ����
				for (int k = i; k < 29; ++k)
				{
					for (int j = 0; j < 10; ++j)
					{
						Cube* temp = elements[k + 1][j];
						elements[k][j] = temp;
						if (elements[k][j] != nullptr)
						{
							elements[k][j]->yCenter -= 0.1;
						}
					}
				}
				score += 10;
			}
		}
	}

	void Scene::fillArr()
	{
		int i, j;
		for (int k = 0; k < 4; ++k)
		{
			if (current->arr[k]->yCenter < 0.0)
				i = std::abs(std::abs(round(current->arr[k]->yCenter * 10)) - 10);
			else
				i = round(current->arr[k]->yCenter * 10) + 10;
			j = round(current->arr[k]->xCenter * 10) + 8;
			if (i >= 18 && j <= 8 && j >= 3)
			{
				finish = 1; //����� ���
				std::ifstream in("������.txt");
				int data;
				in >> data;
				if (data < score)
					writeScore(score);
				in.close();
			}
			elements[i][j] = new Cube(current->arr[k]->xCenter, current->arr[k]->yCenter,
				current->arr[k]->zCenter, current->arr[k]->xSize, current->arr[k]->ySize,
				current->arr[k]->zSize, current->arr[k]->diffColor, current->arr[k]->ambiColor, current->arr[k]->specColor);
		}
		delete current;
		moveElements();
	}

	void Scene::writeScore(int x)
	{
		std::ofstream out("������.txt");
		out << x;
		out.close();
	}
	
	// ���������� ��䳿, ���'����� � �������������� ����
	void Scene::on_paint()
	{
		char text[80];
		char text1[80];// ����� �������, 
			// ���������� ������ ������� �������� �� ����� ���:

		if (finish)
		{
			char h_inf[50];
			int h_score;
			std::ifstream inScore("������.txt");
			inScore >> h_score;
			inScore.close();
			sprintf(text, "GAME OVER");
			sprintf(text1, "Your score: %d      The best score : %d", score, h_score);
			sprintf(h_inf, "F2 - Restart game     Esc - Exit");
			glClearColor(0, 0, 0, 0);

			// ������� ������:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glPushMatrix();
			// �������� ����� ������ � �������� ��������:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			// ��� ����������� ������, ����� ��������������� ������������ ��������:
			glOrtho(0, 800, 0, 600, -1, 40);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glColor3f(1, 1, 1);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 340, 400);
			glColor3f(1, 1, 1);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text1, 240, 350);
			glColor3f(1, 1, 1);
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, h_inf, 240, 300);
			glPopMatrix();

			glFlush();
			// �������� ����:
			glutSwapBuffers(); // ����������� ������
		}
		else
		{
			sprintf(text, "F2 - Restart game   Esc - Exit              Time: %d sec.    Score: %d", time, score);
			// ������������ ������� ��������� ����, ��� ���� �������� ��� ����:
			glViewport(0, 0, width, height);

			// ���������� ��������� �������� � ������� �����:
			float lightAmbient[] = { 0.0f, 0.0f, 0.0f, 1.0f }; // ���� �������� ��������� 
			float lightDiffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; // ���� ��������� ��������� 
			float lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };// ���� ������������ �����������
			float lightPosition[] = { 1.0f, 1.0f, 1.0f, 0.0f };// ������������ ������� �����

			// ������������ ��������� ������� �����:
			glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
			glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
			glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);
			glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

			// ��������� ������ ���� ��� ��������:
			glClearColor(0, 0, 0, 0);

			// ������� ������:
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glPushMatrix();
			// �������� ����� ������ � �������� ��������:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();


			glOrtho(0, 800, 0, 600, -1, 40);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glColor3f(1, 1, 1); // ���� �����
			drawString(GLUT_BITMAP_TIMES_ROMAN_24, text, 10, 580);
			glPopMatrix();

			// �������� ����� ������ � �������� ��������:
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			// ������ ������� ����� �������� � ����������� ������ ���������, 
			// 60 - ��� �������� � �������� �� �� �,
			// width/height - ��� �������� ������ �� x,
			// 1 � 100 - ������� �� ����������� �� ������ �������� �� ������:

			gluPerspective(60, width / height, 1, 100);

			// �������� ����� ������ � ������� ��������:
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			glTranslatef(0, 0, distZ); // ������ � ������� ��������� ��������� �� distZ, 

			glRotatef(angleX, 0.0f, 1.0f, 0.0f);  // ���� ���������� �� �� Oy
			glRotatef(angleY, 1.0f, 0.0f, 0.0f);  // ���� ���������� �� �� Ox
			glEnable(GL_DEPTH_TEST);	// �������� ����� ������� (��� �������� ��������� ������ ����������)

										// �������� ����� ��� ��������� ���������:
			glEnable(GL_LIGHTING);

			// ������ ������� ����� � 0 (�� ���� ���� �� 8), ����� ���� ������ � "����":
			glEnable(GL_LIGHT0);

			// ������� �� ������:
			border->draw();
			current->draw();
			next->draw();
			drawCubes();

			// Turn off everything that's turned on:
			glDisable(GL_LIGHT0);
			glDisable(GL_LIGHTING);
			glDisable(GL_DEPTH_TEST);
			glFlush();
			// �������� ����:
			glutSwapBuffers(); // ����������� ������
		}

	}

	// ���������� ��䳿, ���'����� � ����� ������ ���� 
	void Scene::on_size(int width, int height)
	{
		this->width = width;
		if (height == 0)
			height = 1;
		this->height = height;
	}

	void Scene::on_keyboard(int key, int x, int y)
	{
		switch (key)
		{
		case 100://d
			angleX -= 5;
			break;
		case 97://a
			angleX += 5;
			break;
		case 115://s
			distZ -= 0.1;
			break;
		case 119: //w
			if (distZ > -1.7)
			{
				break;
			}
			distZ += 0.1;
			break;
		case 27://esc
			exit(0);
		}
	}

	// ���������� ����, ���'������ � ����������� �������������� ����� � ������ 
	void Scene::on_special(int key, int x, int y)
	{
		switch (key) {
		case GLUT_KEY_LEFT:
			changeX(-0.1);
			break;
		case GLUT_KEY_RIGHT:
			changeX(0.1);
			break;
		case GLUT_KEY_UP:
			current->rotate++;
			if (current->rotate == 5)
				current->rotate = 1;
			current->Rotate();
			break;
		case GLUT_KEY_DOWN:
			changeY();
			break;
		case GLUT_KEY_F2:   // ���� ���
			initialize();
			break;
		}
	}

	int tick = 0; // ��������, �������� ����� ��������� ���� 25 ��

				  // ���������� ��䳿 �� �������
	void Scene::on_timer(int value)
	{
		tick++;
		if (tick >= 40) // ���������� �������� �������
		{
			if (!finish)// ������� �����������, ���� ��� �� ��������
			{
				time++;
			}
			tick = 0;   // ������� ��������
		}
		on_paint();     // ��������� ������������� ����
	}

	bool Scene::checkAccess(Cube* el)
	{
		int i;
		if (el->yCenter < 0.0)
			i = std::abs(std::abs(round(el->yCenter * 10)) - 10);
		else
			i = round(el->yCenter * 10) + 10;
		int j = round(el->xCenter * 10) + 8;
		if (elements[i][j] != nullptr)
			return 1;
		else
			return 0;
	}

	void Scene::changeX(float x)
	{
		for (int i = 0; i < 4; ++i)
		{
			current->arr[i]->xCenter = current->arr[i]->xCenter + x;
			if (current->arr[i]->xCenter >= 0.1 || current->arr[i]->xCenter <= -0.83 || checkAccess(current->arr[i]))
			{
				for (int j = i; j >= 0; --j)
					current->arr[j]->xCenter = current->arr[j]->xCenter - x;
				break;
			}
		}
	}

	void Scene::changeY()
	{
		for (int i = 0; i < 4; ++i)
		{
			current->arr[i]->yCenter = current->arr[i]->yCenter - 0.1;
			if (current->arr[i]->yCenter <= -1.1 || checkAccess(current->arr[i]))
			{
				for (int j = i; j >= 0; --j)
					current->arr[j]->yCenter = current->arr[j]->yCenter + 0.1;
				fillArr();
				break;
			}
		}
	}

	void Scene::on_idle(int value)
	{
		changeY();
	}

}
