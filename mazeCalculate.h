#ifndef MAZECALCULATE_H
#define MAZECALCULATE_H
#include <stack>
#include <iostream>
using namespace std;

#define mazeCoord	(y*nX+x) 





class maze
{
public:

	void start(int _cell_number_x,int _cell_number_y,int _start_point_x,int _start_point_y);
	void showMatrix();
	void consoleDraw();
	void sfmlDraw();
	void showMazeWallMatrix();
	void saveMazeWallMatrix();

private:


	enum dir
	{
		RIGHT = 0x1,
		LEFT = 0x2,
		UP = 0x4,
		DOWN = 0x8,
		VISITED = 0x10,
	};
	stack<pair<int, int>> mazeCheck;
	int* mazeMatrix;
	int* wallMatrix;
	int nX=10, nY=10, x=0, y=2,mazeCounter=0;
	int createMap();
	int directionDecide(int mazeCell);
	void calculate();
	void calculateWallMatrix(int _x, int _y);
};





#endif
