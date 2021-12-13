#include "pch.h"
#include <gl/glut.h>
#include "Cube.h"
#include "utils.h"

Cube::Cube(float xCenter, float yCenter, float zCenter,
	float xSize, float ySize, float zSize,
	float* diffColor, float* ambiColor, float* specColor)
{
	this->xCenter = xCenter;
	this->yCenter = yCenter;
	this->zCenter = zCenter;
	this->xSize = xSize;
	this->ySize = ySize;
	this->zSize = zSize;
	this->diffColor = diffColor;
	this->ambiColor = ambiColor;
	this->specColor = specColor;
}
void Cube::draw()
{
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambiColor);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, diffColor);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specColor);
	glMaterialf(GL_FRONT, GL_SHININESS, GraphUtils::shininess);
	glPushMatrix();
	glTranslatef(xCenter, yCenter, zCenter);
	GraphUtils::parallelepiped(0.1f, 0.1f, 0.1f);
	glPopMatrix();
}
void Cube::setCoords(float x, float y, float z)
{
	xCenter = x;
	yCenter = y;
	zCenter = z;
}