#ifndef Shape_h
#define Shape_h
#include "Cube.h"

// Клас для представлення абстрактної фігури
class Shape
{
public:
	Cube* arr[4];
	int rotate;
	float xCenter, yCenter, zCenter;          // координати центру
	float xSize, ySize, zSize;                // розміри
	float *diffColor, *ambiColor, *specColor; // кольори
	Shape(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor);
	virtual ~Shape() { };
	virtual void Rotate() = 0;
	virtual void setIn() = 0;
	virtual void draw() = 0; // ця функція повинна бути перекрита у похідних класах
};

#endif
