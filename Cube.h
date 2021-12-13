#ifndef CUBE
#define CUBE

class Cube
{
public:
	float xCenter, yCenter, zCenter;          // ���������� ������
	float xSize, ySize, zSize;                // ������
	float *diffColor, *ambiColor, *specColor; // �������
	Cube(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor);
	void setCoords(float x, float y, float z);
	void draw();
};
#endif