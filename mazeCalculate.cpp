#include "mazeCalculate.h"
void maze::calculateWallMatrix(int _x,int _y)
{

}
void maze::consoleDraw()
{
        
}
void maze::sfmlDraw()
{

}

void maze::showMazeWallMatrix()
{



}
void maze::saveMazeWallMatrix()
{

}


void maze::showMatrix()
{
    
	for (int yNumber = 0; yNumber < nY; yNumber++)
	{
	    for (int xNumber = 0; xNumber < nX; xNumber++)
	    {
	        std::cout << mazeMatrix[yNumber * nX + xNumber] << "|";
	    }
	    std::cout << "\n";
	}
	std::cout << "\n";
}

void maze::start(int _nX,int _nY,int startPointX,int startPointY)
{
    nX = _nX, nY = _nY;
    x = startPointX-1; y = startPointY-1;
    createMap();
    calculate();

}


void maze::calculate()
{
    switch (directionDecide(mazeMatrix[mazeCoord]))
    {
    case RIGHT:
        calculateWallMatrix(x, y);
        mazeMatrix[mazeCoord] |= RIGHT;
        x++;
        mazeCounter++;
        mazeMatrix[mazeCoord] |= VISITED;
        mazeCheck.push({ x,y });
        mazeMatrix[mazeCoord] |= LEFT;
        calculate();
        break;
    case LEFT:

        calculateWallMatrix(x, y);
        mazeMatrix[mazeCoord] |= LEFT;
        x--;
        mazeCounter++;
        mazeMatrix[mazeCoord] |= VISITED;
        mazeCheck.push({ x,y });
        mazeMatrix[mazeCoord] |= RIGHT;
        calculate();
        break;
    case UP:


        calculateWallMatrix(x, y);
        mazeMatrix[mazeCoord] |= UP;
        y--;
        mazeCounter++;
        mazeMatrix[mazeCoord] |= VISITED;
        mazeCheck.push({ x,y });
        mazeMatrix[mazeCoord] |= DOWN;
        calculate();
        break;
    case DOWN:
        calculateWallMatrix(x, y);
        mazeMatrix[mazeCoord] |= DOWN;
        y++;
        mazeCounter++;
        mazeMatrix[mazeCoord] |= VISITED;
        mazeCheck.push({ x,y });
        mazeMatrix[mazeCoord] |= UP;
        calculate();
        break;

    case 0:

        if (mazeCounter == nX * nY)break;
        mazeCheck.pop();
        x = mazeCheck.top().first;
        y = mazeCheck.top().second;
        calculate();
        break;
    }
}





int maze::directionDecide(int mazeCell) //determine the direction of the next cell 
{
    int mazeDirectionBuffer[4] = { 0,0,0,0 }, i = rand() % 4;

    if (!(mazeCell % 2))if (!((maze::mazeMatrix[y * nX + x + 1] >> 4) % 2))
        mazeDirectionBuffer[0] = 1;     //RIGHT

    if (!((mazeCell >> 1) % 2))if (!((maze::mazeMatrix[y * nX + x - 1] >> 4) % 2))
        mazeDirectionBuffer[1] = 1;     //LEFT

    if (!((mazeCell >> 2) % 2))if (!((maze::mazeMatrix[(y - 1) * nX + x] >> 4) % 2))
        mazeDirectionBuffer[2] = 1;     //UP

    if (!((mazeCell >> 3) % 2))if (!((maze::mazeMatrix[(y + 1) * nX + x] >> 4) % 2))
        mazeDirectionBuffer[3] = 1;     //DOWN

    if (mazeDirectionBuffer[0] == 0 && mazeDirectionBuffer[1] == 0 && mazeDirectionBuffer[2] == 0 && mazeDirectionBuffer[3] == 0)
        return 0;                      //NOT DIRECTION

    while (!mazeDirectionBuffer[i]) i = rand() % 4;

    if (i == 0) return RIGHT;

    if (i == 1) return LEFT;

    if (i == 2) return UP;

    if (i == 3) return DOWN;
}






int maze::createMap()     //create the null map and determine the border

{
    
    mazeMatrix = new int[nX * nY];
    memset(mazeMatrix, 0x00, nX * nY * sizeof(int));

    for (int yNumber = 0; yNumber < nY; yNumber++)
    {
        for (int xNumber = 0; xNumber < nX; xNumber++)
        {
            if (yNumber == 0)           mazeMatrix[yNumber * nX + xNumber] |= 0x4;
            if (xNumber == 0)           mazeMatrix[yNumber * nX + xNumber] |= 0x2;
            if (yNumber == (nY - 1))    mazeMatrix[yNumber * nX + xNumber] |= 0x8;
            if (xNumber == (nX - 1))    mazeMatrix[yNumber * nX + xNumber] |= 0x1;
        }
    }

    //create wall matrix
    
    return 1;
}