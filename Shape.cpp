#include "pch.h"
#include "Shape.h"
#include "Scene.h"

// Конструктор:
Shape::Shape(float xCenter, float yCenter, float zCenter,
	float xSize, float ySize, float zSize,
	float* diffColor, float* ambiColor, float* specColor)
{
	this->rotate = 0;
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