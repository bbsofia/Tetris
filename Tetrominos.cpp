#include "pch.h"
#include <gl/glut.h>
#include "Tetrominos.h"
#include "utils.h"

void Board::draw()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambiColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specColor);
	glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
	// Запис поточної матриці в стек
	// (збереження вмісту поточної матриці для подальшого використання):
	glPushMatrix();
	glTranslatef(xCenter, yCenter, zCenter);
	GraphUtils::parallelepiped(1.05f, 2.0f, 0.1f);
	// Відновлення поточної матриці зі стека:
	glPopMatrix();
}
/*
##
######
*/
void Tetromino1::draw()
{
	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino1::setIn()
{
	arr[0]->setCoords(-0.5f, 0.9f, 0.0f);
	arr[1]->setCoords(-0.5f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[3]->setCoords(-0.3f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino1::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->xCenter += 0.2;
		arr[0]->yCenter += 0.1;
		arr[1]->xCenter += 0.1;
		arr[1]->yCenter += 0.2;
		arr[2]->yCenter += 0.1;
		arr[3]->xCenter -= 0.1;
		break;
	case 2:
		if (arr[3]->xCenter < -0.73)
		{
			arr[0]->yCenter -= 0.2;
			arr[0]->xCenter += 0.1;
			arr[1]->xCenter += 0.2;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter += 0.1;
			arr[3]->yCenter += 0.1;
			break;
		}
		else
		{
			arr[0]->yCenter -= 0.2;
			arr[1]->xCenter += 0.1;
			arr[1]->yCenter -= 0.1;
			arr[3]->yCenter += 0.1;
			arr[3]->xCenter -= 0.1;
			break;
		}
	case 3:
		arr[0]->xCenter -= 0.1;
		arr[1]->yCenter -= 0.1;
		arr[2]->xCenter += 0.1;
		arr[3]->xCenter += 0.2;
		arr[3]->yCenter += 0.1;
		break;
	case 4:
		if (arr[0]->xCenter < -0.73)
		{
			arr[0]->yCenter += 0.1;
			arr[1]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter += 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.1;
			arr[0]->yCenter += 0.1;
			arr[1]->xCenter -= 0.2;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
	}
}
/*
	  ##
	######
*/
void Tetromino2::draw()
{
	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino2::setIn()
{
	arr[0]->setCoords(-0.4f, 0.9f, 0.0f);
	arr[1]->setCoords(-0.5f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[3]->setCoords(-0.3f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino2::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->xCenter += 0.1;
		arr[1]->xCenter += 0.1;
		arr[1]->yCenter += 0.2;
		arr[2]->yCenter += 0.1;
		arr[3]->xCenter -= 0.1;
		break;
	case 2:
		if (arr[1]->xCenter < -0.73)
		{
			arr[0]->yCenter -= 0.1;
			arr[1]->xCenter += 0.2;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter += 0.1;
			arr[3]->yCenter += 0.1;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.1;
			arr[0]->yCenter -= 0.1;
			arr[1]->xCenter += 0.1;
			arr[1]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.1;
			arr[3]->yCenter += 0.1;
			break;
		}
	case 3:
		arr[0]->yCenter += 0.1;
		arr[1]->yCenter -= 0.1;
		arr[2]->xCenter += 0.1;
		arr[3]->xCenter += 0.2;
		arr[3]->yCenter += 0.1;
		break;
	case 4:
		if (arr[0]->xCenter < -0.73)
		{
			arr[0]->xCenter += 0.1;
			arr[1]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter += 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
		else
		{
			arr[1]->xCenter -= 0.2;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
	}
}
/*
	###
	###
*/
void Tetromino3::draw()
{

	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino3::setIn()
{
	arr[0]->setCoords(-0.3f, 0.9f, 0.0f);
	arr[1]->setCoords(-0.3f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.9f, 0.0f);
	arr[3]->setCoords(-0.4f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
/*
	########
*/
void Tetromino4::draw()
{

	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino4::setIn()
{
	arr[0]->setCoords(-0.5f, 0.8f, 0.0f);
	arr[1]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.3f, 0.8f, 0.0f);
	arr[3]->setCoords(-0.2f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino4::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->yCenter += 0.3;
		arr[1]->yCenter += 0.2;
		arr[1]->xCenter -= 0.1;
		arr[2]->yCenter += 0.1;
		arr[2]->xCenter -= 0.2;
		arr[3]->xCenter -= 0.3;
		break;
	case 2:
		if (arr[0]->xCenter < -0.13)
		{
			arr[0]->xCenter += 0.3;
			arr[0]->yCenter -= 0.3;
			arr[1]->xCenter += 0.2;
			arr[1]->yCenter -= 0.2;
			arr[2]->xCenter += 0.1;
			arr[2]->yCenter -= 0.1;
			break;
		}
		else
		{
			arr[0]->yCenter -= 0.3;
			arr[1]->xCenter -= 0.1;
			arr[1]->yCenter -= 0.2;
			arr[2]->xCenter -= 0.2;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.3;
			break;
		}
	case 3:
		arr[1]->xCenter += 0.1;
		arr[1]->yCenter += 0.1;
		arr[2]->xCenter += 0.2;
		arr[2]->yCenter += 0.2;
		arr[3]->xCenter += 0.3;
		arr[3]->yCenter += 0.3;
		break;
	case 4:
		if (arr[0]->xCenter < -0.13)
		{
			arr[1]->xCenter += 0.1;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter += 0.2;
			arr[2]->yCenter -= 0.2;
			arr[3]->xCenter += 0.3;
			arr[3]->yCenter -= 0.3;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.3;
			arr[1]->xCenter -= 0.2;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.2;
			arr[3]->yCenter -= 0.3;
			break;
		}
	}
}
/*
		##
	######
*/
void Tetromino5::draw()
{

	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino5::setIn()
{
	arr[0]->setCoords(-0.3f, 0.9f, 0.0f);
	arr[1]->setCoords(-0.3f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[3]->setCoords(-0.5f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino5::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->xCenter -= 0.1;
		arr[0]->yCenter -= 0.1;
		arr[1]->xCenter -= 0.2;
		arr[2]->xCenter -= 0.1;
		arr[2]->yCenter += 0.1;
		arr[3]->yCenter += 0.2;
		break;
	case 2:
		if (arr[1]->xCenter < -0.03)
		{
			arr[0]->xCenter -= 0.1;
			arr[1]->yCenter += 0.1;
			arr[2]->xCenter += 0.1;
			arr[3]->xCenter += 0.2;
			arr[3]->yCenter -= 0.1;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.2;
			arr[1]->xCenter -= 0.1;
			arr[1]->yCenter += 0.1;
			arr[3]->xCenter += 0.1;
			arr[3]->yCenter -= 0.1;
			break;
		}
	case 3:
		arr[0]->yCenter += 0.2;
		arr[1]->xCenter += 0.1;
		arr[1]->yCenter += 0.1;
		arr[3]->xCenter -= 0.1;
		arr[3]->yCenter -= 0.1;
		break;
	case 4:
		if (arr[0]->xCenter < -0.63)
		{
			arr[0]->xCenter += 0.2;
			arr[0]->yCenter -= 0.1;
			arr[1]->xCenter += 0.1;
			arr[1]->yCenter -= 0.2;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.1;
			break;
		}
		else
		{
			arr[0]->xCenter += 0.1;
			arr[0]->yCenter -= 0.1;
			arr[1]->yCenter -= 0.2;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.2;
			break;
		}
	}
}
/*
	####
	  ####
*/
void Tetromino6::draw()
{

	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino6::setIn()
{
	arr[0]->setCoords(-0.5f, 0.9f, 0.0f);
	arr[1]->setCoords(-0.4f, 0.9f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[3]->setCoords(-0.3f, 0.8f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino6::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->xCenter += 0.1;
		arr[0]->yCenter += 0.1;
		arr[2]->xCenter -= 0.1;
		arr[2]->yCenter += 0.1;
		arr[3]->xCenter -= 0.2;
		break;
	case 2:
		if (arr[2]->xCenter < -0.03)
		{
			arr[0]->xCenter += 0.1;
			arr[0]->yCenter -= 0.2;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter += 0.1;
			arr[3]->yCenter += 0.1;
			break;
		}
		else
		{
			arr[0]->yCenter -= 0.2;
			arr[1]->xCenter -= 0.1;
			arr[1]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.1;
			arr[3]->yCenter += 0.1;
			break;
		}
	case 3:
		arr[0]->xCenter -= 0.2;
		arr[1]->xCenter -= 0.1;
		arr[1]->yCenter += 0.1;
		arr[3]->xCenter += 0.1;
		arr[3]->yCenter += 0.1;
		break;
	case 4:
		if (arr[0]->xCenter < -0.03)
		{
			arr[0]->yCenter += 0.1;
			arr[1]->xCenter += 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter += 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.1;
			arr[0]->yCenter += 0.1;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->yCenter -= 0.2;
			break;
		}
	}
}
/*
	  ####
	####
*/
void Tetromino7::draw()
{

	for (int i = 0; i < 4; ++i)
		arr[i]->draw();
}
void Tetromino7::setIn()
{
	arr[0]->setCoords(-0.5f, 0.8f, 0.0f);
	arr[1]->setCoords(-0.4f, 0.8f, 0.0f);
	arr[2]->setCoords(-0.4f, 0.9f, 0.0f);
	arr[3]->setCoords(-0.3f, 0.9f, 0.0f);
	for (int i = 0; i < 4; ++i)
	{
		arr[i]->xSize = 1;
		arr[i]->ySize = 0.1;
		arr[i]->zSize = 1;
	}
}
void Tetromino7::Rotate()
{
	switch (rotate)
	{
	case 0:
		break;
	case 1:
		arr[0]->yCenter += 0.2;
		arr[1]->xCenter -= 0.1;
		arr[1]->yCenter += 0.1;
		arr[3]->xCenter -= 0.1;
		arr[3]->yCenter -= 0.1;
		break;
	case 2:
		if (arr[0]->xCenter < -0.03)
		{
			arr[0]->xCenter += 0.2;
			arr[0]->yCenter -= 0.1;
			arr[1]->xCenter += 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.1;
			break;
		}
		else
		{
			arr[0]->xCenter += 0.1;
			arr[0]->yCenter -= 0.1;
			arr[2]->xCenter -= 0.1;
			arr[2]->yCenter -= 0.1;
			arr[3]->xCenter -= 0.2;
			break;
		}
	case 3:
		arr[0]->xCenter -= 0.1;
		arr[0]->yCenter -= 0.1;
		arr[2]->xCenter -= 0.1;
		arr[2]->yCenter += 0.1;
		arr[3]->yCenter += 0.2;
		break;
	case 4:
		if (arr[2]->xCenter < -0.03)
		{
			arr[0]->xCenter -= 0.1;
			arr[1]->yCenter -= 0.1;
			arr[2]->xCenter += 0.1;
			arr[3]->xCenter += 0.2;
			arr[3]->yCenter -= 0.1;
			break;
		}
		else
		{
			arr[0]->xCenter -= 0.2;
			arr[1]->xCenter -= 0.1;
			arr[1]->yCenter -= 0.1;
			arr[3]->xCenter += 0.1;
			arr[3]->yCenter -= 0.1;
			break;
		}
	}
}
