#ifndef Tetrominos_h
#define Tetrominos_h

#include "Shape.h"

class Board
{
public:
	float xCenter, yCenter, zCenter;          // координати центру
	float xSize, ySize, zSize;                // розміри
	float *diffColor, *ambiColor, *specColor; // кольори
	Board(float xCenter, float yCenter, float zCenter,
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

	void draw();
};
/*
////
///////////
*/
class Tetromino1 : public Shape
{
public:
	Tetromino1(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter + 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter + 0.2, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	};
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

/*
		///
	//////////
*/
class Tetromino2 : public Shape
{
public:
	Tetromino2(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter + 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter - 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

/*
	////////
	////////
	////////
*/
class Tetromino3 : public Shape
{
public:
	Tetromino3(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter + 0.1, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter + 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate() {};
	virtual void setIn();
	virtual void draw();
};

/*
	////////////////
*/
class Tetromino4 : public Shape
{
public:
	Tetromino4(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter - 0.1, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter - 0.2, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter + 0.1, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

/*
			////
	///////////
*/
class Tetromino5 : public Shape
{
public:
	Tetromino5(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter - 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter - 0.2, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

/*
	////////
		////////
*/
class Tetromino6 : public Shape
{
public:
	Tetromino6(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter - 0.1, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter + 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

/*
		////////
	////////
*/
class Tetromino7 : public Shape
{
public:
	Tetromino7(float xCenter, float yCenter, float zCenter,
		float xSize, float ySize, float zSize,
		float* diffColor, float* ambiColor, float* specColor)
		: Shape(xCenter, yCenter, zCenter,
			xSize, ySize, zSize,
			diffColor, ambiColor, specColor)
	{
		arr[0] = new Cube(xCenter, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[1] = new Cube(xCenter, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[2] = new Cube(xCenter + 0.1, yCenter, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
		arr[3] = new Cube(xCenter - 0.1, yCenter - 0.1, zCenter, xSize, ySize, zSize, diffColor, ambiColor, specColor);
	}
	virtual void Rotate();
	virtual void setIn();
	virtual void draw();
};

#endif