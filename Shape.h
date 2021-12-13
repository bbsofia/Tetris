#ifndef Shape_h
#define Shape_h
#include "Cube.h"

// ���� ��� ������������� ���������� ������
class Shape
{
public:
	Cube* arr[4];
	int rotate;
	float xCenter, yCenter, zCenter;          // ���������� ������
	float xSize, ySize, zSize;                // ������
	float *diffColor, *ambiColor, *specColor; // �������
	Shape(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor);
	virtual ~Shape() { };
	virtual void Rotate() = 0;
	virtual void setIn() = 0;
	virtual void draw() = 0; // �� ������� ������� ���� ��������� � �������� ������
};

#endif
